/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:33 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 22:47:05 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	for_first(t_pipex *pipex, int i)
{
	int	x;

	check_cmd(pipex);
	if (dup2(pipex->file1, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->fd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	x = 0;
	while (x < pipex->count_pipe)
	{
		close(pipex->fd[x][0]);
		close(pipex->fd[x][1]);
		x++;
	}
	if (execve(pipex->for_execve, pipex->split_cmd, pipex->env) != 0)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	for_middle(t_pipex *pipex, int i)
{
	int	x;

	x = 0;
	check_cmd(pipex);
	if (dup2(pipex->fd[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->fd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	while (x < pipex->count_pipe)
	{
		close(pipex->fd[x][0]);
		close(pipex->fd[x][1]);
		x++;
	}
	if (execve(pipex->for_execve, pipex->split_cmd, pipex->env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	for_last(t_pipex *pipex, int i)
{
	int	x;

	x = 0;
	check_cmd(pipex);
	if (dup2(pipex->fd[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->file2, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}	
	while (x < pipex->count_pipe)
	{
		close(pipex->fd[x][0]);
		close(pipex->fd[x][1]);
		x++;
	}
	if (execve(pipex->for_execve, pipex->split_cmd, pipex->env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	check_and_call_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->count_pipe)
	{
		if (pipe(pipex->fd[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	if (ft_strcmp(pipex->arg.argv[1], "here_doc") != 0)
		call_mandatory(pipex);
	else
		call_here_doc(pipex);
	while (i < pipex->count_pipe)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		i++;
	}
	while (wait(NULL) != -1)
		;
}
