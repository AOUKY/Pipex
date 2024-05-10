/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:20:42 by haouky            #+#    #+#             */
/*   Updated: 2024/05/06 16:32:10 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		l;
	char	*s;

	if (!(s1) && !(s2))
		return (0);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	l = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s = malloc(l);
	if (!s)
		return (0);
	ft_strlcpy(s, s1, l);
	ft_strlcat(s, s2, l);
	return (s);
}
