/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:02:47 by haouky            #+#    #+#             */
/*   Updated: 2023/12/22 16:44:48 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev(char *c)
{
	int		i;
	int		l;
	char	*v;

	i = 0;
	l = ft_strlen(c) - 1;
	v = malloc(l + 2);
	if (v == 0)
		return (0);
	while (i <= l)
	{
		v[i] = c[l - i];
		i++;
	}
	v[i] = '\0';
	return (v);
}

char	*ft_itoa(int nb)
{
	long	n;
	char	c[12];
	int		i;
	char	*p;

	n = nb;
	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		c[i++] = '0';
	while (n > 0)
	{
		c[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	if (nb < 0)
		c[i++] = '-';
	c[i] = '\0';
	p = rev(c);
	if (p == 0)
		return (0);
	return (p);
}
