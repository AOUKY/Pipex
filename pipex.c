/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:15:48 by haouky            #+#    #+#             */
/*   Updated: 2024/05/08 12:29:14 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_error(int pipe, int open, char **v, int c)
{
	if (c < 6 && (cmp(v[1], "here_doc")))
	{
		ft_printf("%s <here_doc> <limeter> <cmd> ... <cmd> <outfile>\n", v[0]);
		exit(EXIT_FAILURE);
	}
	else if (c < 5)
	{
		ft_printf("%s <infile> <cmd> ... <cmd> <outfile>\n", v[0]);
		exit(EXIT_FAILURE);
	}
	if (pipe == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	if (open == -1)
	{
		ft_printf("%s", v[1]);
		perror(" ");
	}
	return (open);
}

static void	se_here_doc(char **v, char **env, int *fd, int c)
{
	int	i;
	int	oldread;
	int	pid;

	i = 3;
	close(fd[1]);
	while (i < (c - 2))
	{
		oldread = fd[0];
		pipe(fd);
		pid = fork();
		if (pid == 0)
			middle_child(oldread, v[i], env, fd);
		close(oldread);
		close(fd[1]);
		i++;
	}
}

void	here_doc(char **v, char **env, int *fd, int c)
{
	char	*line;
	char	*heredoc;
	int		pid;
	char	*limeter;

	check_error(pipe(fd), 1, v, c);
	heredoc = 0;
	limeter = ft_strjoin(v[2], "\n");
	ft_printf(">");
	line = get_next_line(0);
	while (line && (cmp(line, limeter)) == 0)
	{
		heredoc = ft_strjoin(heredoc, line);
		ft_printf(">");
		line = get_next_line(0);
	}
	ft_putstr_fd(heredoc, fd[1]);
	se_here_doc(v, env, fd, c);
	pid = fork();
	if (pid == 0)
		last_child(fd, v, env, c);
	close(fd[0]);
	while (wait(0) && ((c--) - 4))
		;
}

static void	semain(int c, char **v, char **env, int *fd)
{
	int	i;
	int	oldread;
	int	pid2;

	i = 3;
	close(fd[1]);
	while (i < (c - 2))
	{
		oldread = fd[0];
		pipe(fd);
		pid2 = fork();
		if (pid2 == 0)
			middle_child(oldread, v[i], env, fd);
		close(oldread);
		close(fd[1]);
		i++;
	}
}

int	main(int c, char **v, char **env)
{
	int	fd[2];
	int	pid;
	int	pid2;
	int	i;

	if (cmp(v[1], "here_doc"))
	{
		here_doc(v, env, fd, c);
		return (0);
	}
	i = check_error(pipe(fd), open(v[1], O_RDONLY), v, c);
	pid = fork();
	if (pid == 0)
		first_child(fd, i, v[2], env);
	semain(c, v, env, fd);
	pid2 = fork();
	if (pid2 == 0)
		last_child(fd, v, env, c);
	close(fd[0]);
	while (wait(0) && ((c--) - 3))
		;
}
