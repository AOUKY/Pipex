/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:25:41 by haouky            #+#    #+#             */
/*   Updated: 2023/12/14 16:47:13 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ld;

	i = 0;
	ld = ft_strlen(dst);
	if (ld >= size || size == 0)
		return (ft_strlen(src) + size);
	while (src[i] != 0 && i < size - ld - 1)
	{
		dst[i + ld] = src[i];
		i++;
	}
	dst[i + ld] = '\0';
	return (ld + ft_strlen(src));
}
