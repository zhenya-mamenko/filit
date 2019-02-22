/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:36:23 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/22 11:25:56 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_coords
{
	char x;
	char y;
}				t_coords;

typedef struct	s_tetremino
{
	char		id;
	t_coords	p[4];
}				t_tetremino;

void			error(void);
void			proceed_input(int ac, char **av);

#endif
