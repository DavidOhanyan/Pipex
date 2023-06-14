/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:56:54 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 21:50:45 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "pipex.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int flag);
char	*ft_strchr(char *s, int c);

#endif
