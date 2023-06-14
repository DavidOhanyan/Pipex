/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:20:00 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 22:47:17 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	check_argv(argc, argv);
	init_pipex(&pipex);
	initialize_pipex(&pipex, argc, argv, env);
	check_and_open(&pipex, argc, argv);
	check_and_call_cmd(&pipex);
	return (0);
}
