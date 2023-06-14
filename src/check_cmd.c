/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:05:14 by dohanyan          #+#    #+#             */
/*   Updated: 2023/05/24 14:51:38 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_from_path(t_pipex *pipex, char *path)
{
	int		i;
	char	*for_check;
	char	*get_path;

	i = 0;
	for_check = 0;
	get_path = 0;
	while (pipex->all_path[i])
	{
		get_path = pipex->all_path[i];
		for_check = ft_strjoin(get_path, path, 0);
		if (access(for_check, X_OK) == -1)
			i++;
		else
		{
			pipex->for_execve = for_check;
			free(path);
			return (0);
		}
		free(for_check);
	}
	free(path);
	return (1);
}

void	check_cmd(t_pipex *pipex)
{
	char	*path;
	int		i;

	i = 0;
	pipex->split_cmd = ft_split(pipex->arg.argv[pipex->first_cmd], ' ');
	if (access(pipex->split_cmd[i], X_OK) == -1)
	{
		if (ft_strchr(pipex->split_cmd[i], '/') != NULL)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		path = ft_strjoin(pipex->slesh_cmd, pipex->split_cmd[i], 0);
		if (find_from_path(pipex, path) == 1)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	else
		pipex->for_execve = pipex->split_cmd[i];
}
