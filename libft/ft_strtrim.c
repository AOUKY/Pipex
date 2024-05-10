/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:03:58 by haouky            #+#    #+#             */
/*   Updated: 2023/12/16 16:14:44 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chek(char c, const char *set)
{
	int	j;

	j = 0;
	while (set[j] != 0)
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;
	char	*p;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (0);
	i = 0;
	l = ft_strlen(s1) - 1;
	while (s1[i] != 0 && chek(s1[i], set))
		i++;
	while (l >= i && chek(s1[l], set))
		l--;
	p = ft_substr(s1, i, (l - i + 1));
	return (p);
}
