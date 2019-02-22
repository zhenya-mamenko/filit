/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:44:24 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/22 11:22:25 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	proceed_input(int ac, char **av)
{
	if (ac != 2 && av[1])
		error();
}
