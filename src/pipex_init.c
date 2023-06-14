/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:58:15 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/17 15:22:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex)
{
	pipex->path = 0;
	pipex->first_cmd = 0;
	pipex->file1 = 0;
	pipex->file2 = 0;
	pipex->count_cmd = 0;
	pipex->count_pipe = 0;
	pipex->for_execve = 0;
	pipex->slesh_cmd = 0;
	pipex->arg.argc = 0;
	pipex->split_cmd = NULL;
	pipex->all_path = NULL;
	pipex->env = NULL;
	pipex->arg.argv = NULL;
}

void	count_pip_count_cmd(t_pipex *pipex)
{
	int	i;

	i = pipex->arg.argc - pipex->first_cmd - 1;
	pipex->count_cmd = i;
	if (ft_strcmp(pipex->arg.argv[1], "here_doc") == 0)
		pipex->count_pipe = pipex->count_cmd;
	else
		pipex->count_pipe = pipex->count_cmd - 1;
}

void	initialize_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->path = find_path(env, "PATH");
	if (!pipex->path)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	pipex->env = env;
	pipex->arg.argc = argc;
	pipex->arg.argv = argv;
	pipex->slesh_cmd = ft_strdup("/");
	pipex->path = chang_path(pipex->path);
	pipex->all_path = split_path(pipex->path);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		pipex->first_cmd = 3;
	else
		pipex->first_cmd = 2;
	count_pip_count_cmd(pipex);
	pipex->fd = malloc(pipex->count_pipe * sizeof(int [2]));
}
