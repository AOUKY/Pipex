/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:45:43 by haouky            #+#    #+#             */
/*   Updated: 2024/05/08 12:20:22 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_error(int c, int pipe, int open, char **v)
{
	if (c != 5)
	{
		ft_printf("%s <infile> <cmd> <cmd> <outfile>\n", v[0]);
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

int	main(int c, char **v, char **env)
{
	int	fd[2];
	int	pid;
	int	pid2;
	int	fd2;

	fd2 = check_error(c, pipe(fd), open(v[1], O_RDONLY), v);
	pid = fork();
	if (pid == 0)
		first_child(fd, fd2, v[2], env);
	pid2 = fork();
	if (pid2 == 0)
		last_child(fd, v, env, c);
	close(fd[0]);
	close(fd[1]);
	wait(0);
	wait(0);
}
