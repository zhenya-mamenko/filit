/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 08:16:51 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/20 23:20:16 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*el;

	if (*alst == NULL || del == NULL)
		return ;
	while ((*alst))
	{
		el = (*alst)->next;
		if ((*alst)->content != NULL)
			(*del)((*alst)->content, (*alst)->content_size);
		free((*alst));
		(*alst) = el;
	}
}
