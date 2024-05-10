/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:26:13 by haouky            #+#    #+#             */
/*   Updated: 2023/12/25 11:12:25 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nd;
	t_list	*last_node;

	if (!lst || !del)
		return ;
	last_node = *lst;
	while (last_node)
	{
		nd = last_node;
		last_node = last_node->next;
		ft_lstdelone(nd, del);
	}
	*lst = 0;
}
