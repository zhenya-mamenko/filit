/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:00:25 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 11:33:22 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsetdel(char **dst, char *src)
{
	if (dst != NULL && *dst != NULL)
		ft_strdel(dst);
	*dst = src;
}
