/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:15:35 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 23:49:27 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extract_word(char const *s, char d, unsigned int n)
{
	unsigned int	c;
	unsigned int	i;
	int				f;
	int				b;

	c = 0;
	f = 0;
	i = 0;
	b = -1;
	while (s[i])
	{
		if (s[i] != d)
		{
			c += (f == 0) ? 1 : 0;
			if (c == n && b == -1)
				b = i;
			f = 1;
		}
		else if ((f = 0) == 0 && c == n)
			break ;
		i++;
	}
	return (ft_strsub(s, b, i - b));
}
