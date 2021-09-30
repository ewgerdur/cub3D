/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:39:16 by wgerdur           #+#    #+#             */
/*   Updated: 2020/12/22 17:12:02 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_td(char **temp, char **line, char **rem)
{
	*(*(temp)) = '\0';
	(*temp) = ft_strdup(*temp + 1);
	(*line) = ft_strdup(*rem);
	free(*rem);
	*rem = ft_strdup(*temp);
	free(*temp);
}

int	ft_add_gnl(int fd, char **line, char **buf, char **temp)
{
	static char	*rem;
	int			bread;

	bread = 1;
	if (!rem)
		rem = ft_strdup("\0");
	while (bread)
	{
		*temp = ft_strchr(rem, '\n');
		if (*temp || !(bread))
		{
			ft_td(temp, line, &rem);
			return (1);
		}
		bread = read(fd, *buf, 1);
		if (bread < 0)
			return (-1);
		(*buf)[bread] = '\0';
		rem = ft_strjoin(rem, *buf);
		if (bread != 1)
			(*line) = rem;
	}
	rem = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		ree;
	char	*temp;

	ree = 0;
	buf = calloc(1 + 1, sizeof(char));
	if (!(buf))
		return (-1);
	if (fd < 0 || !(line) || 1 <= 0)
	{
		free(buf);
		return (-1);
	}
	ree = ft_add_gnl(fd, line, &buf, &temp);
	free(buf);
	if (ree == 1)
		return (1);
	else if (ree == -1)
		return (-1);
	return (0);
}
