/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:56:22 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 18:18:30 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*b;

	i = 0;
	b = malloc(sizeof(char) * size);
	if (b != NULL)
		ft_memset(b, 0, size);
	return ((void *)b);
}
