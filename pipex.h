/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:43:47 by haouky            #+#    #+#             */
/*   Updated: 2024/05/10 16:05:24 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Get_Next_Line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

char	*get_cmd(char *cmd, char **env);
char	*get_path(char **env);
int		first_child(int *fd, int fd2, char *v, char **env);
int		last_child(int *fd, char **v, char **env, int c);
int		middle_child(int read, char *v, char **env, int *fd);
int		cmp(char *s, char *p);

#endif