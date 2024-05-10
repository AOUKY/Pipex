/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:26:51 by haouky            #+#    #+#             */
/*   Updated: 2024/05/09 18:04:49 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	fr_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	lenw(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

static char	**getarray(t_list *lst)
{
	char	**str;
	int		i;

	i = 0;
	str = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (lst)
	{
		str[i] = lst->content;
		i++;
		lst = lst->next;
	}
	str[i] = 0;	
	return (str);
}

char	**lsplit(char *s, char c)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		c = ' ';
		while (s[i] == c && s[i])
			i++;
		if ((s[i] == '\'' || s[i] == '"') && s[i])
		{
			c = s[i];
			while (s[i] == c)
				i++;
		}
		if(s[i])
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_substr(s, i, lenw(&s[i], c))));
			i += lenw(&s[i], c);
		}
	}
	return (getarray(lst));
}
