/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:32:26 by haouky            #+#    #+#             */
/*   Updated: 2024/05/09 11:53:52 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_child(int *fd, int fd2, char *v, char **env)
{
	char	*cmd;

	cmd = get_cmd(v, env);
	if (!cmd)
	{
		if (find_c(v, '/'))  
			ft_printf("./pipex: no such file or directory : %s\n", v);
		else
			ft_printf("./pipex: command not found: %s\n", v);
		exit(EXIT_FAILURE);
	}
	dup2(fd2, 0);
	close(fd2);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	if(fd2 == -1)
	{
		close (1);
		close (0);
		exit(EXIT_FAILURE);
	}	
	if (execve(cmd, lsplit(v, ' '), env) == -1)
		perror("execve");
	exit(EXIT_FAILURE);
}

int	middle_child(int old_read, char *v, char **env, int *fd)
{
	char	*cmd;

	cmd = get_cmd(v, env);
	if (!cmd)
	{
		if (find_c(v, '/'))
			ft_printf("./pipex: no such file or directory : %s\n", v);
		else
			ft_printf("./pipex: command not found: %s\n", v);
		exit(EXIT_FAILURE);
	}
	dup2(old_read, 0);
	close(old_read);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	if (execve(cmd, lsplit(v, ' '), env) == -1)
		perror("execve");
	exit(EXIT_FAILURE);
}

int	last_child(int *fd, char **v, char **env, int c)
{
	int		fd2;
	char	*cmd;

	if (cmp(v[1], "here_doc"))
		fd2 = open(v[c - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd2 = open(v[c - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd2 == -1)
	{
		perror(v[0]);
		exit(EXIT_FAILURE);
	}
	cmd = get_cmd(v[c - 2], env);
	if (!cmd)
	{
		if (find_c(v[c - 2], '/'))
			ft_printf("%s: no such file or directory : %s\n", v[0], v[c - 2]);
		else
			ft_printf("%s: command not found: %s\n", v[0], v[c - 2]);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd2, 1);
	close(fd2);
	close(fd[1]);
	if (execve(cmd, lsplit(v[c - 2], ' '), env) == -1)
		perror("execve");
	exit(EXIT_FAILURE);
}
