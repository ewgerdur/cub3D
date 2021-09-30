/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:40:18 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 19:40:21 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_wall(t_game *game, double x, double y)
{
	if (!(game->map.map[(int)((y - 4) / CUB)][(int)(x / CUB)] != '1' &&
			game->map.map[(int)((y + 4) / CUB)][(int)(x / CUB)] != '1' &&
			game->map.map[(int)(y / CUB)][(int)((x + 4) / CUB)] != '1' &&
			game->map.map[(int)(y / CUB)][(int)((x - 4) / CUB)] != '1'))
		return (0);
	return (1);
}

void	ft_start_rad(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'N')
		game->r_dir = -M_PI / 4;
	else if (game->map.map[i][j] == 'S')
		game->r_dir = M_PI / 4;
	else if (game->map.map[i][j] == 'E')
		game->r_dir = 0;
	else if (game->map.map[i][j] == 'W')
		game->r_dir = M_PI / 2;
	game->d_x = game->x;
	game->d_y = game->y;
	game->spt.c_x = game->x;
	game->spt.c_y = game->y;
	game->spt.d_x = game->x;
	game->spt.d_y = game->y;
	game->rad = 0;
	game->len_rey = 0;
	game->sprt = 0;
}

void	ft_start_point(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
					|| game->map.map[i][j] == 'E' ||game->map.map[i][j] == 'W')
			{
				ft_start_rad(game, i, j);
				game->f_color = ft_translate_rgb(0, game->map.f1,
						game->map.f2, game->map.f3);
				game->c_color = ft_translate_rgb(0, game->map.c1,
						game->map.c2, game->map.c3);
				game->x = (j * CUB + 32);
				game->y = (i * CUB + 32);
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	ft_draw_sky(t_game *game, double len, int x)
{
	int		centre;
	double	y;
	double	count;
	double	st;

	centre = game->map.r_y / 2;
	y = (64.0 / len * (game->map.r_x / (2.0 * tan(M_PI / 6))));
	count = 0;
	st = 0;
	while ((int)count < (int)(centre - y / 2))
	{
		ft_pixel(&(game->img), x, count, game->c_color);
		count++;
		st++;
	}
	count += (int)y;
	while ((int)count < (int)(game->map.r_y))
	{
		ft_pixel(&(game->img), x, count, game->f_color);
		count++;
	}
	return (st);
}

void	ft_draw_walls(t_game *game, double len, int x, double degree)
{
	int		centre;
	double	h;
	double	buba;

	centre = game->map.r_y / 2;
	degree = 0;
	if (centre == 1000000 && degree != 0)
		return ;
	h = (64.0 / len * (game->map.r_x / (2.0 * tan(M_PI / 6))));
	buba = ft_draw_sky(game, len, x);
	if ((int)game->d_x % (CUB) > 0 && (int)game->d_x % (CUB)
		< 63 && (int)game->d_y % (CUB) == 63)
		game->flag = ft_draw_no(game, h, (double)buba, x);
	else if ((int)game->d_x % (CUB) == 0 && (int)game->d_y % (CUB)
		> 0 && (int)game->d_y % (CUB) < 63)
		game->flag = ft_draw_ea(game, h, (double)buba, x);
	else if ((int)game->d_x % (CUB) == 63 && (int)game->d_y % (CUB)
		> 0 && (int)game->d_y % (CUB) < 63)
		game->flag = ft_draw_we(game, h, (double)buba, x);
	else if ((int)game->d_x % (CUB) > 0 && (int)game->d_x % (CUB)
		< 63 && (int)game->d_y % (CUB) == 0)
		game->flag = ft_draw_so(game, h, (double)buba, x);
	else
		ft_draw_text(game, h, (double)buba, x);
}
