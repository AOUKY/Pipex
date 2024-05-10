/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:45:10 by haouky            #+#    #+#             */
/*   Updated: 2023/12/26 19:06:31 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	a;

	a = ft_strlen(str);
	while (a >= 0)
	{
		if (str[a] == (char)c)
			return ((char *)&str[a]);
		a--;
	}
	return (0);
}
