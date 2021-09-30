/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:54:12 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 17:54:15 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_text_col_no(t_game *game, int x, int y)
{
	char	*textuu;

	textuu = game->txt_no.t_adr + ((y * game->txt_no.img_height / CUB)
			* game->txt_no.t_len + x * (game->txt_no.t_bits / 8));
	return (*(unsigned int *)textuu);
}

int	ft_text_col_so(t_game *game, int x, int y)
{
	char	*textuu;

	textuu = game->txt_so.t_adr + ((y * game->txt_so.img_height / CUB)
			* game->txt_so.t_len + x * (game->txt_so.t_bits / 8));
	return (*(unsigned int *)textuu);
}

int	ft_text_col_ea(t_game *game, int x, int y)
{
	char	*textuu;

	textuu = game->txt_ea.t_adr + ((y * game->txt_ea.img_height / CUB)
			* game->txt_ea.t_len + x * (game->txt_ea.t_bits / 8));
	return (*(unsigned int *)textuu);
}

int	ft_text_col_we(t_game *game, int x, int y)
{
	char	*textuu;

	textuu = game->txt_we.t_adr + ((y * game->txt_we.img_height / CUB)
			* game->txt_we.t_len + x * (game->txt_we.t_bits / 8));
	return (*(unsigned int *)textuu);
}
