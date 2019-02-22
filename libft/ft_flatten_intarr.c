/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatten_intarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:33:32 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 23:19:14 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flatten_intarr(int *a, size_t n)
{
	size_t	i;
	int		len;
	char	*s;
	char	*e;

	s = ft_strnew(n * 12);
	if (s == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (i < n)
	{
		e = ft_itoa(a[i]);
		ft_strcpy(&s[len], e);
		len += ft_strlen(e);
		free(e);
		s[len++] = '\t';
		i += 1;
	}
	s[len - 1] = '\0';
	e = ft_strdup(s);
	free(s);
	return (e);
}
