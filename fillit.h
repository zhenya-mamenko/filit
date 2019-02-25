/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:36:23 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 22:22:33 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_coords
{
	int		x;
	int		y;
}				t_coords;

typedef struct	s_tetremino
{
	char		id;
	t_coords	p[4];
	t_coords	min;
	t_coords	max;
}				t_tetremino;

typedef struct	s_square
{
	char		c[12][13];
}				t_square;

t_tetremino		g_tetrs[26];
int				g_tcount;

void			error(void *p);
void			success(t_square s, int n);
void			proceed_input(int ac, char **av);
int				calc_min_size(void);
void			init_square(t_square *s);
int				check_tetrimino(char **tetrimino);
void			make_tetrimino(char **tetrimino, char **line);

#endif
