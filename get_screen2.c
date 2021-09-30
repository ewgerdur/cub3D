/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:11:35 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 19:12:23 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_arrer(char	*arr_info)
{
	if (!arr_info)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}

void	ft_check_val1(t_iparc *map)
{
	if (map->r_x == -1 || map->r_y == -1)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	else if (map->c1 == -1 || map->f1 == -1
		|| map->r_x == 0 || map->r_y == 0)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}

void	ft_init_vertical2(t_game *game)
{
	game->vert_y = (int)(game->map.r_y / 2 - game->scr_size / 2);
	game->step_y = game->spt.img_height / game->scr_size;
	game->step_x = game->spt.img_width / game->scr_size;
	game->tex_x = 0;
	game->tex_y = 0;
}
