/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:43:55 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 22:48:04 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	call_get_next_line(t_pipex *pipex)
{
	int		i;
	char	*for_exit;
	char	*line;

	i = 0;
	for_exit = pipex->arg.argv[2];
	for_exit = ft_strjoin(for_exit, "\n", 0);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL || ft_strcmp(line, for_exit) == 0)
			break ;
		write (pipex->fd[i][1], line, ft_strlen(line));
		free(line);
	}
}

void	call_here_doc(t_pipex *pipex)
{
	int	i;
	int	pid;

	pid = 0;
	i = 0;
	call_get_next_line(pipex);
	i++;
	while (i <= pipex->count_cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == pipex->count_pipe)
				for_last(pipex, i);
			else
				for_middle(pipex, i);
		}
		pipex->first_cmd++;
		i++;
	}
}

void	call_mandatory(t_pipex *pipex)
{
	int	i;
	int	pid;

	pid = 0;
	i = 0;
	while (i < pipex->count_cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				for_first(pipex, i);
			else
				if (i == pipex->count_pipe)
					for_last(pipex, i);
			else
				for_middle(pipex, i);
		}
		pipex->first_cmd++;
		i++;
	}
}
