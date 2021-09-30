/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screeshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:28:18 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 17:28:23 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	first_info(int size, char **arr_info)
{
	(*arr_info)[0] = 'B';
	(*arr_info)[1] = 'M';
	(*arr_info)[2] = size;
	(*arr_info)[3] = size >> 8;
	(*arr_info)[4] = size >> 16;
	(*arr_info)[5] = size >> 24;
	(*arr_info)[10] = 54;
	(*arr_info)[14] = 40;
	(*arr_info)[26] = 1;
	(*arr_info)[28] = 24;
}

static void	init_width(int width, char **arr_info)
{
	int	i;

	i = 8;
	(*arr_info)[18] = width;
	while (i <= 24)
	{
		(*arr_info)[19] = width >> 8;
		(*arr_info)[20] = width >> 16;
		(*arr_info)[21] = width >> 24;
		i++;
	}
}

static void	init_height(int height, char **arr_info)
{
	int	i;

	i = 8;
	(*arr_info)[22] = height;
	while (i <= 24)
	{
		(*arr_info)[23] = height >> 8;
		(*arr_info)[24] = height >> 16;
		(*arr_info)[25] = height >> 24;
		i += 8;
	}
}

static void	output_screenshot(t_game *game, int fd, int width, int height)
{
	int	var[3];

	var[0] = height - 1;
	while (var[0] >= 0)
	{
		var[1] = 0;
		while (var[1] < width)
		{
			var[2] = *(int *)(game->img.adr + (var[0]
						* game->img.len + var[1] * (game->img.bits / 8)));
			write(fd, &var[2], 3);
			var[1]++;
		}
		var[0]--;
	}
	close(fd);
	exit(0);
}

int	get_screen(t_game *game)
{
	int		fd;
	int		size;
	int		width;
	int		height;
	char	*arr_info;

	arr_info = (char *)malloc(sizeof(char) * 54);
	ft_arrer(arr_info);
	width = game->map.r_x;
	height = game->map.r_y;
	fd = open("my_screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC
			| O_APPEND, 0666);
	if (!fd)
		return (-1);
	while (width % 4 != 0)
		width--;
	size = 54 + (4 * width * height);
	ft_memset(arr_info, 0, 54);
	first_info(size, &arr_info);
	init_width(width, &arr_info);
	init_height(height, &arr_info);
	write(fd, arr_info, 54);
	free(arr_info);
	output_screenshot(game, fd, width, height);
	return (0);
}
