/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:36:10 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 23:05:05 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		calc_min_size(void)
{
	int		result;
	int		i;

	result = g_tcount * 4 / 2 + 1;
	while (result > 0)
	{
		if ((result * result) < (g_tcount * 4))
			break ;
		else
			result--;
	}
	result++;
	i = 0;
	while (i < g_tcount)
	{
		if (result < (g_tetrs[i].max.x - g_tetrs[i].min.x + 1))
			result = (g_tetrs[i].max.x - g_tetrs[i].min.x + 1);
		else if (result < (g_tetrs[i].max.y - g_tetrs[i].min.y + 1))
			result = (g_tetrs[i].max.y - g_tetrs[i].min.y + 1);
		i++;
	}
	return (result);
}

int		check_tetr(t_tetremino t, t_coords p, int n, t_square *s)
{
	t_coords	c;
	int			k;
	int			i;

	k = -1;
	if (p.x + t.max.x <= n && p.y + t.max.y <= n &&
		p.x + t.min.x >= 0 && p.y + t.min.y >= 0)
		while (++k < 4)
		{
			c = t.p[k];
			if (c.x + p.x < 0 || c.x + p.x >= n ||
				c.y + p.y < 0 || c.y + p.y >= n ||
				s->c[c.y + p.y][c.x + p.x] != '.')
				break ;
			else
				s->c[c.y + p.y][c.x + p.x] = t.id;
		}
	i = -1;
	if (k != 4)
		while (++i < k)
		{
			c = t.p[i];
			s->c[c.y + p.y][c.x + p.x] = '.';
		}
	return (k == 4 ? 1 : 0);
}

void	fillit(int t, int n, t_square s)
{
	int			i;
	int			j;
	int			k;
	t_coords	c;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			c.y = i;
			c.x = j;
			if (check_tetr(g_tetrs[t], c, n, &s) != 0)
			{
				if (g_tcount == t + 1)
					success(s, n);
				fillit(t + 1, n, s);
				k = -1;
				while (++k < 4)
					s.c[g_tetrs[t].p[k].y + i][g_tetrs[t].p[k].x + j] = '.';
			}
		}
	}
}

void	start(void)
{
	int			min_size;
	t_square	s;
	int			i;
	int			j;

	i = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
		{
			s.c[i][j] = '.';
			j++;
		}
		s.c[i][j] = '\0';
		i++;
	}
	min_size = calc_min_size();
	while (min_size < 20)
	{
		fillit(0, min_size, s);
		min_size += 1;
	}
}

int		main(int ac, char **av)
{
	proceed_input(ac, av);
	start();
}
