/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:21:51 by haouky            #+#    #+#             */
/*   Updated: 2023/12/13 19:25:08 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	l = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		if (size > 0)
		{
			dest[i] = '\0';
		}
	}
	return (l);
}
