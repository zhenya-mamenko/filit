/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:15:17 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 20:48:00 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	calc_bounds(void)
{
	int		x_min;
	int		y_min;
	int		x_max;
	int		y_max;
	int		i;
	int		j;

	x_min = 0;
	y_min = 0;
	x_max = 0;
	y_max = 0;
	i = 0;
	j = 0;
	while (i++ < 4)
	{
		if (tetrimino[i][j] == '#')
			x_min = i;
		if (tetrimino[i][j] == '#' && tetrimino[i + 1][j] != '#')
			x_max = i;
	}
	while (j++ < 4)
	{
		if (tetrimino[i][j] == '#')
			y_min = j;
		if (tetrimino[i][j] == '#' && tetrimino[i][j + 1] != '#')
			x_max = i;
	}
	g_tetrs[g_tcount].height = y_max - y_min;
	g_tetrs[g_tcount].width = x_max - x_min;
}

void	make_tetrimino(char **tetrimino)
{
	int			i;
	int			j;
	int			k;
	t_coords	c;

	g_tetrs[g_tcount].id = 'A' + g_tcount;
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetrimino[i][j] == '#')
			{
				if (k++ == 0)
				{
					c.x = j;
					c.y = i;
				}
				g_tetrs[g_tcount].p[k].x = j - c.x;
				g_tetrs[g_tcount].p[k].y = i - c.y;
			}
	}
	calc_bounds();
	g_tcount += 1;
}

int		check_tetrimino(char **tetrimino)
{
	int		count_con;
	int		count_hash;
	int		i;
	int		j;

	i = -1;
	count_con = 0;
	count_hash = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetrimino[i][j] == '#')
			{
				count_con += (i > 0 && tetrimino[i - 1][j] == '#') ? 1 : 0;
				count_con += (i < 4 && tetrimino[i + 1][j] == '#') ? 1 : 0;
				count_con += (j > 0 && tetrimino[i][j - 1] == '#') ? 1 : 0;
				count_con += (j < 4 && tetrimino[i][j + 1] == '#') ? 1 : 0;
				count_hash++;
			}
		}
	}
	return (((count_con != 6 && count_con != 8) || count_hash != 4) ? 0 : 1);
}
