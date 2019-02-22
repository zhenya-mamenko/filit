/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 08:59:22 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 23:25:24 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*b;
	size_t	l;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	b = malloc(l + 1);
	if (b != NULL)
	{
		while (s[i])
		{
			b[i] = (*f)(s[i]);
			i += 1;
		}
		b[l] = '\0';
	}
	return (b);
}
