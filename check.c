/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:15:17 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 18:56:03 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetrimino(char **tetrimino)
{
	int		count_con;
	int		count_hash;
	int		i;
	int		j;
	char	c;

	i = -1;
	count_con = 0;
	count_con = 0;
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
