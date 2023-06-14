/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:59:57 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 20:00:58 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env, char *name)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == name[j] && env[i][j])
		{
			j++;
			if (j == ft_strlen(name))
				return (env[i]);
		}
		i++;
	}
	return (NULL);
}

char	*chang_path(char	*real_path)
{
	int		i;
	char	*path;

	i = 0;
	path = ft_strdup(real_path);
	while (path[i++] != 'T')
		i++;
	path[i] = '.';
	path[i + 1] = ':';
	return (path);
}

char	**split_path(char *path)
{
	int	i;

	i = 0;
	while (path[i] != 'T')
		i++;
	i++;
	return (ft_split(path + i, ':'));
}
