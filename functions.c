/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:00:50 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 20:55:06 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		calc_min_size(void)
{
	int		result;
	int		i;

	result = ((g_tcount * 4) / 2) + 1;
	while (result > 0)
		if (result * result < g_tcount * 4)
			break ;
		else
			result--;
	result++;
	i = 0;
	while (i < g_tcount)
	{
		if (result < g_tetrs[i].width)
			result = g_tetrs[i].width;
		else if (result < g_tetrs[i].height)
			result = g_tetrs[i].height;
		i++;
	}
	return (result);
}

void	init_square(t_square *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
		{
			s->c[i][j] = '.';
			j++;
		}
		s->c[i][j] = '\0';
		i++;
	}
}
