/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:36:14 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 18:30:07 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy != NULL)
		ft_strcpy(copy, s1);
	return (copy);
}
