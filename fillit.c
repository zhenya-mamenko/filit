/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:36:10 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 22:27:36 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

	init_square(&s);
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
