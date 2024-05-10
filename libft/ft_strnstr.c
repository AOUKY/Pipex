/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:32:05 by haouky            #+#    #+#             */
/*   Updated: 2023/12/19 16:54:09 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find(const char *find, const char *str, size_t l)
{
	size_t	i;

	i = 0;
	while (find[i] == str[i] && find[i] != 0 && i < l)
		i++;
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	chek_sz;
	size_t	len_find;

	i = 0;
	len_find = ft_strlen(to_find);
	if (to_find[i] == '\0')
		return ((char *)str);
	if (len == 0)
		return (0);
	while (i < len && str[i] != '\0')
	{
		chek_sz = 0;
		if (str[i] == to_find[chek_sz])
		{
			chek_sz = find(to_find, &str[i], len - i);
			if (chek_sz == len_find)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
