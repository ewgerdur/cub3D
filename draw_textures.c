/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:41:10 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 19:41:13 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_draw_no(t_game *game, double h, double count, int x)
{
	double	n_x;
	double	n_y;
	double	step;
	int		start;
	int		num_no;

	num_no = 1;
	n_x = (int)game->d_x % (CUB);
	step = (64.0 / h);
	n_y = (count - game->map.r_y / 2 + h / 2) * step;
	start = 0;
	if (n_y < 0)
		n_y = 0;
	while ((int)start < (int)h)
	{
		if (count >= game->map.r_y)
			break ;
		ft_pixel(&(game->img), x, (int)count,
			ft_text_col_no(game, (int)n_x, (int)n_y));
		n_y += step;
		count++;
		start++;
	}
	return (num_no);
}

int	ft_draw_we(t_game *game, double h, double count, int x)
{
	double	n_x;
	double	n_y;
	double	step;
	int		start;
	int		num_we;

	num_we = 2;
	start = 0;
	n_x = (int)game->d_y % (CUB);
	step = (64.0 / h);
	n_y = (count - game->map.r_y / 2 + h / 2) * step;
	if (n_y < 0)
		n_y = 0;
	while ((int)start < (int)h)
	{
		if (count >= game->map.r_y)
			break ;
		ft_pixel(&(game->img), x, (int)count,
			ft_text_col_we(game, (int)n_x, (int)n_y));
		n_y += step;
		count++;
		start++;
	}
	return (num_we);
}

int	ft_draw_ea(t_game *game, double h, double count, int x)
{
	double	n_x;
	double	n_y;
	double	step;
	int		start;
	int		num_ea;

	num_ea = 3;
	n_x = (int)game->d_y % (CUB);
	step = (64.0 / h);
	n_y = (count - game->map.r_y / 2 + h / 2) * step;
	start = 0;
	if (n_y < 0)
		n_y = 0;
	while ((int)start < (int)h)
	{
		if (count >= game->map.r_y)
			break ;
		ft_pixel(&(game->img), x, (int)count,
			ft_text_col_ea(game, (int)n_x, (int)n_y));
		n_y += step;
		count++;
		start++;
	}
	return (num_ea);
}

int	ft_draw_so(t_game *game, double h, double count, int x)
{
	double	n_x;
	double	n_y;
	double	step;
	int		start;
	int		num_so;

	num_so = 4;
	start = 0;
	n_x = (int)game->d_x % (CUB);
	step = (64.0 / h);
	n_y = (count - game->map.r_y / 2 + h / 2) * step;
	if (n_y < 0)
		n_y = 0;
	while ((int)start < (int)h)
	{
		if (count >= game->map.r_y)
			break ;
		ft_pixel(&(game->img), x, (int)count, ft_text_col_so(game,
				(int)n_x, (int)n_y));
		n_y += step;
		count++;
		start++;
	}
	return (num_so);
}

void	ft_draw_text(t_game *game, double h, double start, int x)
{
	if (game->flag == 1)
		ft_draw_no(game, h, (double)start, x);
	else if (game->flag == 2)
		ft_draw_we(game, h, (double)start, x);
	else if (game->flag == 3)
		ft_draw_ea(game, h, (double)start, x);
	else if (game->flag == 4)
		ft_draw_so(game, h, (double)start, x);
}
