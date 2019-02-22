/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:18:24 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 22:22:17 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct	s_fpt
{
	int			fd;
	char		*buf;
}				t_fpt;

int				get_next_line(const int fd, char **line);

#endif
