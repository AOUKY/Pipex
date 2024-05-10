/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:36:55 by haouky            #+#    #+#             */
/*   Updated: 2023/12/12 09:55:16 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = str;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
