/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:22:58 by haouky            #+#    #+#             */
/*   Updated: 2023/12/23 12:48:13 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstp;
	const unsigned char	*srcp;

	if (!dst && !src)
		return (0);
	if (dst == src)
		return (dst);
	dstp = dst;
	srcp = src;
	i = 0;
	while (i < n)
	{
		dstp[i] = srcp[i];
		i++;
	}
	return (dst);
}
