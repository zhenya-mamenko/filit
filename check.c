/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:15:17 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 22:22:54 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetrimino(char **tetrimino)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(&tetrimino[i]);
		i += 1;
	}
}

void	calc_bounds(char **tetrimino, char **line)
{
	t_coords	min;
	t_coords	max;
	int			i;

	min.x = 10;
	min.y = 10;
	max.x = -10;
	max.y = -10;
	i = 0;
	while (i++ < 4)
	{
		if (g_tetrs[g_tcount].p[i].x > max.x)
			max.x = g_tetrs[g_tcount].p[i].x;
		if (g_tetrs[g_tcount].p[i].x < min.x)
			min.x = g_tetrs[g_tcount].p[i].x;
		if (g_tetrs[g_tcount].p[i].y > max.y)
			max.y = g_tetrs[g_tcount].p[i].y;
		if (g_tetrs[g_tcount].p[i].y < min.y)
			min.y = g_tetrs[g_tcount].p[i].y;
	}
	g_tetrs[g_tcount].min = min;
	g_tetrs[g_tcount].max = max;
	free_tetrimino(tetrimino);
	ft_strdel(line);
}

void	make_tetrimino(char **tetrimino, char **line)
{
	int			i;
	int			j;
	int			k;
	t_coords	c;

	g_tetrs[g_tcount].id = 'A' + g_tcount;
	i = -1;
	k = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetrimino[i][j] == '#')
			{
				if (++k == 0)
				{
					c.x = j;
					c.y = i;
				}
				g_tetrs[g_tcount].p[k].x = j - c.x;
				g_tetrs[g_tcount].p[k].y = i - c.y;
			}
	}
	calc_bounds(tetrimino, line);
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
