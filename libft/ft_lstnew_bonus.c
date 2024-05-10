/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:11:54 by haouky            #+#    #+#             */
/*   Updated: 2024/05/02 10:49:30 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ne;

	ne = malloc(sizeof(t_list));
	if (ne == 0)
		return (0);
	ne->content = content;
	ne->next = 0;
	return (ne);
}
