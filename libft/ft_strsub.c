/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:44:22 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/21 21:42:25 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	if (s == NULL)
		return (NULL);
	b = malloc(sizeof(char) * (len + 1));
	if (b != NULL)
	{
		i = 0;
		while (i < len && s[i + start] != '\0')
		{
			b[i] = s[i + start];
			i += 1;
		}
		b[i] = '\0';
	}
	return (b);
}
