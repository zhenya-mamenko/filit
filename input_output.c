/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:44:24 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/22 21:17:58 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	success(t_square s, int n)
{
	int		i;
	char	*l;

	i = 0;
	while (i < n)
	{
		l = ft_strsub(s.c[i], 0, n);
		ft_putstr(l);
		ft_putchar('\n');
		i += 1;
	}
	exit(0);
}

void	proceed_input(int ac, char **av)
{
	if (ac < 0 && av[1])
		error();
	g_tetrs[0].id = 'A';
	g_tetrs[0].p[0].x = 0;
	g_tetrs[0].p[0].y = 0;
	g_tetrs[0].p[1].x = 0;
	g_tetrs[0].p[1].y = 1;
	g_tetrs[0].p[2].x = 0;
	g_tetrs[0].p[2].y = 2;
	g_tetrs[0].p[3].x = 0;
	g_tetrs[0].p[3].y = 3;
	g_tetrs[0].height = 4;
	g_tetrs[0].width = 1;
	g_tetrs[1].id = 'B';
	g_tetrs[1].p[0].x = 0;
	g_tetrs[1].p[0].y = 0;
	g_tetrs[1].p[1].x = 1;
	g_tetrs[1].p[1].y = 0;
	g_tetrs[1].p[2].x = 2;
	g_tetrs[1].p[2].y = 0;
	g_tetrs[1].p[3].x = 3;
	g_tetrs[1].p[3].y = 0;
	g_tetrs[1].height = 1;
	g_tetrs[1].width = 4;
	g_tetrs[2].id = 'C';
	g_tetrs[2].p[0].x = 0;
	g_tetrs[2].p[0].y = 0;
	g_tetrs[2].p[1].x = 1;
	g_tetrs[2].p[1].y = 0;
	g_tetrs[2].p[2].x = 2;
	g_tetrs[2].p[2].y = 0;
	g_tetrs[2].p[3].x = 2;
	g_tetrs[2].p[3].y = 1;
	g_tetrs[2].height = 2;
	g_tetrs[2].width = 3;
	g_tetrs[3].id = 'D';
	g_tetrs[3].p[0].x = 0;
	g_tetrs[3].p[0].y = 0;
	g_tetrs[3].p[1].x = 1;
	g_tetrs[3].p[1].y = 0;
	g_tetrs[3].p[2].x = -1;
	g_tetrs[3].p[2].y = 1;
	g_tetrs[3].p[3].x = 0;
	g_tetrs[3].p[3].y = 1;
	g_tetrs[3].height = 2;
	g_tetrs[3].width = 3;
	g_tetrs[4].id = 'E';
	g_tetrs[4].p[0].x = 0;
	g_tetrs[4].p[0].y = 0;
	g_tetrs[4].p[1].x = 1;
	g_tetrs[4].p[1].y = 0;
	g_tetrs[4].p[2].x = 0;
	g_tetrs[4].p[2].y = 1;
	g_tetrs[4].p[3].x = 1;
	g_tetrs[4].p[3].y = 1;
	g_tetrs[4].height = 2;
	g_tetrs[4].width = 2;
	g_tetrs[5].id = 'F';
	g_tetrs[5].p[0].x = 0;
	g_tetrs[5].p[0].y = 0;
	g_tetrs[5].p[1].x = 1;
	g_tetrs[5].p[1].y = 0;
	g_tetrs[5].p[2].x = 1;
	g_tetrs[5].p[2].y = 1;
	g_tetrs[5].p[3].x = 2;
	g_tetrs[5].p[3].y = 1;
	g_tetrs[5].height = 2;
	g_tetrs[5].width = 3;
	g_tetrs[6].id = 'G';
	g_tetrs[6].p[0].x = 0;
	g_tetrs[6].p[0].y = 0;
	g_tetrs[6].p[1].x = 1;
	g_tetrs[6].p[1].y = 0;
	g_tetrs[6].p[2].x = 1;
	g_tetrs[6].p[2].y = 1;
	g_tetrs[6].p[3].x = 1;
	g_tetrs[6].p[3].y = 2;
	g_tetrs[6].height = 3;
	g_tetrs[6].width = 2;
	g_tetrs[7].id = 'H';
	g_tetrs[7].p[0].x = 0;
	g_tetrs[7].p[0].y = 0;
	g_tetrs[7].p[1].x = 1;
	g_tetrs[7].p[1].y = 0;
	g_tetrs[7].p[2].x = 2;
	g_tetrs[7].p[2].y = 0;
	g_tetrs[7].p[3].x = 1;
	g_tetrs[7].p[3].y = 1;
	g_tetrs[7].height = 2;
	g_tetrs[7].width = 3;

	g_tcount = 8;
}
