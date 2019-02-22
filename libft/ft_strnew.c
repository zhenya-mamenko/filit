/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:07:23 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 23:26:07 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*b;

	b = malloc(sizeof(char) * (size + 1));
	if (b != NULL)
		ft_memset(b, 0, size + 1);
	return (b);
}
