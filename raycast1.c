/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:39:59 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/20 23:51:09 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_draw_hero_y(t_game *game, double *arr, int zn)
{
	int		count;
	double	rad;
	double	buba_x;
	double	buba_y;

	rad = game->rad - M_PI / 6;
	count = 0;
	while (count < game->map.r_x)
	{
		ft_init_param(game, 2, &buba_x, &buba_y);
		while (game->map.map[(int)((game->d_y) / CUB)]
				[(int)((game->d_x) / CUB)] != '1')
		{
			ft_turn_y(game, buba_x, buba_y, rad);
			buba_y += zn * 0.2;
		}
		game->len_rey = sqrt((game->d_x - game->x)
				* (game->d_x - game->x)
				+ (game->d_y - game->y) * (game->d_y - game->y))
			* (cos(-game->rad + rad));
		ft_draw_walls(game, game->len_rey, count, -game->rad + rad);
		arr[count] = game->len_rey;
		rad += M_PI / 3 / game->map.r_x;
		count++;
	}
}

static void	ft_draw_hero_x(t_game *game, double *arr, int zn)
{
	int		count;
	double	rad;
	double	buba_x;
	double	buba_y;

	rad = game->rad - M_PI / 6;
	count = 0;
	while (count < game->map.r_x)
	{
		ft_init_param(game, 2, &buba_x, &buba_y);
		while (game->map.map[(int)((game->d_y) / CUB)]
				[(int)((game->d_x) / CUB)] != '1')
		{
			ft_turn_x(game, buba_x, buba_y, rad);
			buba_x += zn * 0.2;
		}
		game->len_rey = sqrt((game->d_x - game->x)
				* (game->d_x - game->x)
				+ (game->d_y - game->y) * (game->d_y - game->y))
			* (cos(-game->rad + rad));
		ft_draw_walls(game, game->len_rey, count, -game->rad + rad);
		arr[count] = game->len_rey;
		rad += M_PI / 3 / game->map.r_x;
		count++;
	}
}

void	ft_draw_hero(t_game *game)
{
	double	*arr;

	arr = (double *)malloc(game->map.r_x * sizeof(double));
	if (game->map.direct == 'N')
	{
		ft_draw_hero_y(game, arr, -1);
		ft_buba_north(game);
	}
	else if (game->map.direct == 'S')
	{
		ft_buba_south(game);
		ft_draw_hero_y(game, arr, 1);
	}
	else if (game->map.direct == 'W')
	{
		ft_buba_west(game);
		ft_draw_hero_x(game, arr, -1);
	}
	else if (game->map.direct == 'E')
	{
		ft_buba_east(game);
		ft_draw_hero_x(game, arr, 1);
	}
	ft_find_spt(game, arr);
	free(arr);
}
