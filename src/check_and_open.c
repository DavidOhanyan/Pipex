/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:24 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 19:58:34 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_and_open(t_pipex *pipex, int argc, char **argv)
{
	pipex->file1 = open(argv[1], O_RDONLY);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		pipex->file2 = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 00755);
	else
		pipex->file2 = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 00755);
}
