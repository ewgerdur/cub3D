/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekey2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:23:33 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 16:23:47 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mlx_clear_put(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlxx);
	mlx_put_image_to_window(game->mlx, game->mlxx, game->img.img, 0, 0);
}

void	ft_pixel(t_data *data, int x, int y, int c)
{
	char	*str;

	str = data->adr + (y * data->len + x * (data->bits / 8));
	*(unsigned int *)str = c;
}

void	ft_key53(int keycode, t_game *game)
{
	if (keycode == 65361)
	{
		game->rad -= 0.03;
		game->r_dir -= 0.03;
	}
	else if (keycode == 65363)
	{
		game->rad += 0.03;
		game->r_dir += 0.03;
	}
	else if (keycode == 65307)
		exit(0);
}
