/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:36:10 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/22 18:20:45 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetr(t_tetremino t, t_coords p, int n, t_square *s)
{
	t_coords	c;
	int			k;
	int			i;

	k = 0;
	if (p.x + t.width <= n && p.y + t.height <= n)
		while (k < 4)
		{
			c = t.p[k];
			if (c.x + p.x < 0 || c.x + p.x >= n ||
				c.y + p.y < 0 || c.y + p.y >= n ||
				s->c[c.y + p.y][c.x + p.x] != '.')
				break ;
			else
				s->c[c.y + p.y][c.x + p.x] = t.id;
			k += 1;
		}
	i = 0;
	if (k != 4)
		while (i < k)
		{
			c = t.p[i];
			s->c[c.y + p.y][c.x + p.x] = '.';
			i += 1;
		}
	return (k == 4 ? 1 : 0);
}

void	fillit(char tetr, int n, t_square s)
{
	int			i;
	int			j;
	int			t;
	int			k;
	t_coords	c;

	t = tetr - 'A';
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c.y = i;
			c.x = j;
			if (check_tetr(g_tetrs[t], c, n, &s) != 0)
			{
				if (g_tcount == t + 1)
					success(s, n);
				fillit('A' + t + 1, n, s);
				k = 0;
				while (k < 4)
				{
					c = g_tetrs[t].p[k];
					s.c[c.y + i][c.x + j] = '.';
					k += 1;
				}
			}
			j += 1;
		}
		i += 1;
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
		fillit('A', min_size, s);
		min_size += 1;
	}
}

int		main(int ac, char **av)
{
	proceed_input(ac, av);
	start();
}
