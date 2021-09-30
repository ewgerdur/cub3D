/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:04:17 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 17:04:20 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_spt(t_game *game)
{
	game->spt.s_img = mlx_xpm_file_to_image(game->mlx, game->map.s,
			&game->spt.img_width, &game->spt.img_height);
	game->spt.s_addr = mlx_get_data_addr(game->spt.s_img,
			&game->spt.s_bits, &game->spt.s_len, &game->spt.s_endian);
}

void	ft_buba_east(t_game *game)
{
	double	rad;
	double	x;
	double	y;
	int		count;
	int		s_flag;

	count = 0;
	rad = game->rad - M_PI / 6;
	while (count < game->map.r_x)
	{
		ft_init_param(game, 1, &x, &y);
		s_flag = 0;
		while (game->map.map[(int)((game->spt.d_y) / CUB)]
				[(int)((game->spt.d_x) / CUB)] != '1')
		{
			ft_turn_mat(game, x, y, rad);
			s_flag = find_monster_centre(game, count, -game->rad + rad);
			if (s_flag == 1)
				break ;
			x++;
		}
		rad += M_PI / 3 / game->map.r_x;
		count++;
	}
}

void	ft_buba_south(t_game *game)
{
	double	rad;
	double	x;
	double	y;
	int		count;
	int		s_flag;

	count = 0;
	rad = game->rad - M_PI / 6;
	while (count < game->map.r_x)
	{
		ft_init_param(game, 1, &x, &y);
		s_flag = 0;
		while (game->map.map[(int)((game->spt.d_y) / CUB)]
				[(int)((game->spt.d_x) / CUB)] != '1')
		{
			ft_turn_mat(game, x, y, rad);
			s_flag = find_monster_centre(game, count, -game->rad + rad);
			if (s_flag == 1)
				break ;
			y++;
		}
		rad += M_PI / 3 / game->map.r_x;
		count++;
	}
}

void	ft_buba_north(t_game *game)
{
	double	rad;
	double	x;
	double	y;
	int		count;
	int		s_flag;

	count = 0;
	rad = game->rad - M_PI / 6;
	while (count < game->map.r_x)
	{
		ft_init_param(game, 1, &x, &y);
		s_flag = 0;
		while (game->map.map[(int)((game->spt.d_y) / CUB)]
				[(int)((game->spt.d_x) / CUB)] != '1')
		{
			ft_turn_mat(game, x, y, rad);
			s_flag = find_monster_centre(game, count, -game->rad + rad);
			if (s_flag == 1)
				break ;
			y--;
		}
		rad += M_PI / 3 / game->map.r_x;
		count++;
	}
}

void	ft_buba_west(t_game *game)
{
	double	rad;
	double	x;
	double	y;
	int		count;
	int		s_flag;

	count = 0;
	rad = game->rad - M_PI / 6;
	while (count < game->map.r_x)
	{
		ft_init_param(game, 1, &x, &y);
		s_flag = 0;
		while (game->map.map[(int)((game->spt.d_y) / CUB)]
				[(int)((game->spt.d_x) / CUB)] != '1')
		{
			ft_turn_mat(game, x, y, rad);
			s_flag = find_monster_centre(game, count, -game->rad + rad);
			if (s_flag == 1)
				break ;
			x--;
		}
		rad += M_PI / 3 / game->map.r_x;
		count++;
	}
}
