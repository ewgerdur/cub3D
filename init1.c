/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:56:32 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 16:56:36 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_param(t_game *game, int flag, double *plr_x, double *plr_y)
{
	if (flag == 1)
	{
		(*plr_x) = game->x;
		(*plr_y) = game->y;
		game->spt.d_x = game->x;
		game->spt.d_y = game->y;
	}
	else if (flag == 2)
	{
		(*plr_x) = game->x;
		(*plr_y) = game->y;
		game->d_x = game->x;
		game->d_y = game->y;
	}
}

void	ft_turn_y(t_game *game, double plr_x, double plr_y, double rad)
{
	game->d_x = (plr_x - game->x) * cos(game->rad + rad)
		- (plr_y - game->y) * sin(game->rad + rad) + game->x;
	game->d_y = (plr_x - game->x) * sin(game->rad + rad)
		+ (plr_y - game->y) * cos(game->rad + rad) + game->y;
}

void	ft_turn_x(t_game *game, double plr_x, double plr_y, double rad)
{
	game->d_x = (plr_x - game->x) * cos(game->rad + rad)
		- (plr_y - game->y) * sin(game->rad + rad) + game->x;
	game->d_y = (plr_x - game->x) * sin(game->rad + rad)
		+ (plr_y - game->y) * cos(game->rad + rad) + game->y;
}

void	ft_turn_mat(t_game *game, double plr_x, double plr_y, double rad)
{
	game->spt.d_x = (plr_x - game->x) * cos(game->rad + rad)
		- (plr_y - game->y) * sin(game->rad + rad) + game->x;
	game->spt.d_y = (plr_x - game->x) * sin(game->rad + rad)
		+ (plr_y - game->y) * cos(game->rad + rad) + game->y;
}

int	ft_translate_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
