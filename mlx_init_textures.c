/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:06:31 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 17:05:04 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_print_valid_eror(void)
{
	write(2, "ERROR\n", 6);
	exit(-1);
}

static void	ft_check_valid_texture(t_game *game)
{
	int	res_openea;
	int	res_openno;
	int	res_openso;
	int	res_openwe;
	int	res_opens;

	res_openea = open(game->map.ea, O_RDONLY);
	res_openno = open(game->map.no, O_RDONLY);
	res_openso = open(game->map.so, O_RDONLY);
	res_openwe = open(game->map.we, O_RDONLY);
	res_opens = open(game->map.s, O_RDONLY);
	if (res_openea <= 0
		|| res_openno <= 0
		|| res_openso <= 0
		|| res_openwe <= 0
		|| res_opens <= 0)
		ft_print_valid_eror();
}

static void	ft_init_wall_texture(t_game *game)
{
	game->txt_ea.t_img = mlx_xpm_file_to_image(game->mlx, game->map.ea,
			&game->txt_ea.img_width, &game->txt_ea.img_height);
	game->txt_ea.t_adr = mlx_get_data_addr(game->txt_ea.t_img,
			&game->txt_ea.t_bits, &game->txt_ea.t_len, &game->txt_ea.end);
	game->txt_no.t_img = mlx_xpm_file_to_image(game->mlx, game->map.no,
			&game->txt_no.img_width, &game->txt_no.img_height);
	game->txt_no.t_adr = mlx_get_data_addr(game->txt_no.t_img,
			&game->txt_no.t_bits, &game->txt_no.t_len, &game->txt_no.end);
	game->txt_so.t_img = mlx_xpm_file_to_image(game->mlx, game->map.so,
			&game->txt_so.img_width, &game->txt_so.img_height);
	game->txt_so.t_adr = mlx_get_data_addr(game->txt_so.t_img,
			&game->txt_so.t_bits, &game->txt_so.t_len, &game->txt_so.end);
	game->txt_we.t_img = mlx_xpm_file_to_image(game->mlx, game->map.we,
			&game->txt_we.img_width, &game->txt_we.img_height);
	game->txt_we.t_adr = mlx_get_data_addr(game->txt_we.t_img,
			&game->txt_we.t_bits, &game->txt_we.t_len, &game->txt_we.end);
}

void	ft_init_textures(t_game *game)
{
	ft_check_valid_texture(game);
	ft_init_wall_texture(game);
	init_spt(game);
}
