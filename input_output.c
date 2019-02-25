/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:44:24 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/24 21:04:49 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include "get_next_line.h"

void	error(void *p)
{
	if (p != NULL)
		free(p);
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

int		check_chars(char *line)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (0);
		i += 1;
	}
	return (1);
}

void	read_lines(int fd)
{
	int		ret;
	char	*line;
	char	*tetrimino[4];
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) != 4 || check_chars(line) != 1)
			error(line);
		tetrimino[i++] = line;
		if (i == 4)
		{
			i = 0;
			if (((ret = get_next_line(fd, &line)) > 0 &&
				ft_strlen(line) != 0) || ret == -1 ||
				check_tetrimino(tetrimino) != 1)
				error(line);
			make_tetrimino(tetrimino);
			free(line);
		}
	}
	if (ret == -1 || i != 0)
		error(line);
}

void	proceed_input(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: fillit tetriminos_list_file\n");
		exit(2);
	}
	g_tcount = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error(NULL);
	read_lines(fd);
}
