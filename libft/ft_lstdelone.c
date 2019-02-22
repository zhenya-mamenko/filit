/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 08:15:32 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 23:20:20 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL || del == NULL)
		return ;
	if ((*alst)->content != NULL)
		(*del)((*alst)->content, (*alst)->content_size);
	free((*alst));
	(*alst) = NULL;
}
