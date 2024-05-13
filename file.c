/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:13:48 by haouky            #+#    #+#             */
/*   Updated: 2024/05/11 11:13:13 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*tmp;
	char	**cmd2;
	int		i;

	i = 0;
	cmd2 = ft_split(cmd, ' ');
	if (access(cmd2[0], F_OK) == 0)
		return (cmd2[0]);
	paths = ft_split(get_path(env), ':');
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd2[0]);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		if (tmp != path)
			free(path);
		i++;
	}
	fr_double(paths);
	return (0);
}

char	*get_path(char **env)
{
	int	i;
	int	j;

	i = 4;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5))
			return (&env[i][5]);
		i++;
	}
	return (0);
}

int	cmp(char *s, char *p)
{
	int	i;

	i = 0;
	if (ft_strlen(s) != ft_strlen(p))
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] != p[i])
			return (0);
		i++;
	}
	return (1);
}
