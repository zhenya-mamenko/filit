/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:26:23 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/21 21:52:49 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	return (ft_strncmp(s1, s2, l1 > l2 ? l1 : l2));
}
