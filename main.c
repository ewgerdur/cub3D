/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:18:07 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/14 15:18:18 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "stdio.h"

static int	mlx_end(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlxx);
	exit(0);
}

static void	mlx_hook_loop(t_game *game)
{
	mlx_hook(game->mlxx, 17, 1L << 0, mlx_end, game);
	mlx_hook(game->mlxx, 2, (1L << 0), ft_move_hook, game);
	mlx_loop(game->mlx);
}

static int	mlx_start(t_game *game)
{
	game->mlx = mlx_init();
	game->mlxx = mlx_new_window(game->mlx, game->map.r_x,
			game->map.r_y, "Cub3D");
	game->img.img = mlx_new_image(game->mlx, game->map.r_x, game->map.r_y);
	game->img.adr = mlx_get_data_addr(game->img.img, &game->img.bits,
			&game->img.len, &game->img.end);
	return (0);
}

static int	ft_save_s_screen(t_game *game, char *str)
{
	int	i;

	i = ft_strcmp("--save", str);
	if (i == 0)
	{
		get_screen(game);
		return (0);
	}
	else
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_parc(argc, argv, &game.map);
	ft_start_point(&(game));
	if (argc < 2 || argc > 3)
		return (0);
	mlx_start(&game);
	ft_init_textures(&game);
	ft_draw_hero(&game);
	mlx_put_image_to_window(game.mlx, game.mlxx, game.img.img, 0, 0);
	if (argc == 3)
		ft_save_s_screen(&game, argv[2]);
	if (argc != 2 && argc != 3)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	mlx_hook_loop(&game);
}
