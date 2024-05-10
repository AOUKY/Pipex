/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:55:08 by haouky            #+#    #+#             */
/*   Updated: 2023/12/16 18:32:47 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		d = dst;
		s = src;
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		d = dst;
		s = src;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
