/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:14:56 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 19:59:24 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argv(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	else
	{
		if (argc < 5)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
}
