/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:08:31 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 16:08:34 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_move_left(int keycode, t_game *game, int del_x, int del_y)
{
	if (keycode == 100 && is_wall(game, game->x + del_x, game->y + del_y))
	{
		game->x = game->x + 4 * cos(2 * game->r_dir + M_PI / 2);
		game->y = game->y + 4 * sin(2 * game->r_dir + M_PI / 2);
	}
}

void	ft_move_right(int keycode, t_game *game, int del_x, int del_y)
{
	if (keycode == 97 && is_wall(game, game->x - del_x, game->y - del_y))
	{
		game->x = game->x - 4 * cos(2 * game->r_dir + M_PI / 2);
		game->y = game->y - 4 * sin(2 * game->r_dir + M_PI / 2);
	}
}

void	ft_move_up(int keycode, t_game *game, int del_x, int del_y)
{
	if (keycode == 119 && is_wall(game, game->x + del_x, game->y + del_y))
	{
		game->x = game->x + 4 * cos(2 * game->r_dir);
		game->y = game->y + 4 * sin(2 * game->r_dir);
	}
}

void	ft_move_down(int keycode, t_game *game, int del_x, int del_y)
{
	if (keycode == 115 && is_wall(game, game->x - del_x, game->y - del_y))
	{
		game->x = game->x - 4 * cos(2 * game->r_dir);
		game->y = game->y - 4 * sin(2 * game->r_dir);
	}
}

int	ft_move_hook(int keycode, t_game *game)
{
	int	de_x;
	int	de_y;

	de_x = 4 * cos(2 * game->r_dir);
	de_y = 4 * sin(2 * game->r_dir);
	ft_move_up(keycode, game, de_x, de_y);
	ft_move_down(keycode, game, de_x, de_y);
	de_x = 4 * cos(2 * game->r_dir + M_PI / 2);
	de_y = 4 * sin(2 * game->r_dir + M_PI / 2);
	ft_move_left(keycode, game, de_x, de_y);
	ft_move_right(keycode, game, de_x, de_y);
	ft_key53(keycode, game);
	ft_draw_hero(game);
	mlx_clear_put(game);
	return (0);
}
