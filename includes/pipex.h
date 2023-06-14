/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:20:08 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 21:57:00 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_arg
{
	int		argc;
	char	**argv;
}		t_arg;

typedef struct s_pipex
{
	int		(*fd)[2];
	int		first_cmd;
	char	*for_execve;
	char	**split_cmd;
	char	**all_path;
	char	**cmd_path;
	char	**env;
	char	*slesh_cmd;
	char	*path;
	int		count_cmd;
	int		count_pipe;
	int		file1;
	int		file2;
	t_arg	arg;
}		t_pipex;

void	*ft_free(char	**matrix, int j);
void	check_argv(int argc, char **argv);
size_t	qanak(char const	*s, char c);
char	**ft_allocate_matrix(char const	*s, char c);
char	**ft_fill_matrix(char const	*s, char c, char	**res);
char	**ft_split(char const	*s, char c);
int		ft_strlen(const char	*s);
void	*ft_memcpy(void	*dst, const void	*src, int n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, int start, size_t len);
char	*find_path(char **env, char *name);
char	*chang_path(char *real_path);
char	**split_path(char *path);
void	init_pipex(t_pipex *pipex);
void	initialize_pipex(t_pipex *pipex, int argc, char **argv, char **env);
void	check_and_open(t_pipex *pipex, int argc, char **argv);
void	check_cmd(t_pipex *pipex);
int		find_from_path(t_pipex *pipex, char *path);
int		ft_strcmp(char *s1, char *s2);
void	check_and_call_cmd(t_pipex *pipex);
void	for_first(t_pipex *pipex, int i);
void	for_middle(t_pipex *pipex, int i);
void	for_last(t_pipex *pipex, int i);
void	call_here_doc(t_pipex *pipex);
void	call_mandatory(t_pipex *pipex);
#endif