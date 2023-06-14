/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:55:11 by dohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 21:48:41 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_parc_buf(char *buf)
{
	int		j;
	int		i;
	char	*rem;

	i = 0;
	j = 0;
	if (buf == 0 || *buf == 0)
		return (0);
	if (ft_strchr(buf, '\n') != NULL)
	{
		while (buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			i++;
		rem = (char *)malloc(sizeof(char) * ft_strlen(ft_strchr(buf, '\n')));
		if (!rem)
			return (NULL);
		while (buf[i] != '\0')
			rem[j++] = buf[i++];
		rem[j] = '\0';
		free(buf);
		buf = 0;
		return (rem);
	}
	return (0);
}

char	*ft_check(char *buf, char *result, int i)
{
	if (buf[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
	}
	else
	{
		result[i] = '\0';
		free(buf);
		buf = 0;
	}
	return (result);
}

char	*ft_parc1(char *buf)
{
	int		i;
	char	*result;

	i = 0;
	if (buf == 0 || *buf == 0)
	{
		if (buf)
			free(buf);
		return (0);
	}
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		result[i] = buf[i];
		i++;
	}
	return (ft_check(buf, result, i));
}

char	*get_next_line(int fd)
{
	int			val;
	char		*result;
	char		mas[BUFFER_SIZE + 1];
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		val = read(fd, mas, BUFFER_SIZE);
		if (val <= 0)
			break ;
		mas[val] = '\0';
		buf = ft_strjoin(buf, mas, 1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (val < 0)
		return (0);
	result = (ft_parc1(buf));
	buf = ft_parc_buf(buf);
	return (result);
}
