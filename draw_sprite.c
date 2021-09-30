/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:40:48 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 19:40:50 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	find_monster_centre(t_game *game, int cnt, double degree)
{
	t_list	*mons;
	double	buf_d_y;
	double	buf_d_x;

	cnt = 0;
	if (cnt != 0)
		return (0);
	if (game->map.map[(int)((game->spt.d_y) / CUB)]
			[(int)((game->spt.d_x) / CUB)] == '2')
	{
		buf_d_x = (int)(game->spt.d_x / CUB)*CUB + CUB / 2;
		buf_d_y = (int)(game->spt.d_y / CUB)*CUB + CUB / 2;
		if (ft_check(game->sprt, (int)(buf_d_x), (int)(buf_d_y)))
		{
			mons = ft_lstnew(game, (int)(buf_d_x), (int)(buf_d_y), degree);
			ft_lstadd_back(&(game->sprt), mons);
			return (1);
		}
	}
	return (0);
}

static void	ft_init_vertical(t_game *game)
{
	if (fabs(game->sprt->aaa.c_y - game->y) >= 0.000000001)
		game->delta = game->sprt->aaa.c_y - game->y;
	else
		game->delta = game->y - game->sprt->aaa.c_y;
	game->deg_spr = atan2(game->delta, game->sprt->aaa.c_x - game->x);
	while (game->deg_spr - 2 * game->r_dir > M_PI)
		game->deg_spr -= 2 * M_PI;
	while (game->deg_spr - 2 * game->r_dir < -M_PI)
		game->deg_spr += 2 * M_PI;
	game->scr_size = (int)((double)(game->map.r_x)
			/ game->sprt->aaa.len_to_spt * 64.0);
	game->vert_x = (int)((game->deg_spr - 2 * game->r_dir)
			/ (M_PI / 3.0) * (double)(game->map.r_x)
			+ (double)(game->map.r_x / 2) - (game->scr_size / 2));
	ft_init_vertical2(game);
}

static void	ft_init_buf_vert(t_game *game, int i, double *buf_vert_y)
{
	i = 0;
	if (i != 0)
		return ;
	if ((int)(game->vert_y < 0))
	{
		game->tex_y = (int)(-1 * game->vert_y * game->step_y);
		*buf_vert_y = 0;
	}
	else
		game->tex_y = 0;
}

static void	ft_print_sprite(t_game *game, int i, double buf_vert_y, double *arr)
{
	int	j;

	j = 0;
	if ((int)(game->vert_x + i) < game->map.r_x && (int)(game->vert_x + i) > 0)
	{
		while (j < (int)game->scr_size)
		{
			if ((int)(buf_vert_y + j) >= game->map.r_y)
				break ;
			if (arr[(int)game->vert_x + i] >= game->sprt->aaa.len_to_spt
				&& get_s(game, (int)game->tex_x, (int)(game->tex_y)) != 000000)
				ft_pixel(&(game->img), (int)(game->vert_x + i), (int)(buf_vert_y
						+ j), get_s(game, (int)game->tex_x,
						(int)game->tex_y));
			game->tex_y += game->step_y;
			j++;
		}
	}
}

void	ft_find_spt(t_game *game, double *arr)
{
	t_list	*head;
	int		i;
	double	buf_vert_y;

	head = game->sprt;
	ft_sort_list((game->sprt));
	while (game->sprt)
	{
		ft_init_vertical(game);
		i = 0;
		buf_vert_y = game->vert_y;
		while (i < (int)game->scr_size)
		{
			if (((int)(game->vert_x + i) >= (game->map.r_x)))
				break ;
			ft_init_buf_vert(game, i, &buf_vert_y);
			ft_print_sprite(game, i, buf_vert_y, arr);
			game->tex_x += game->step_x;
			i++;
		}
		game->sprt = game->sprt->next;
	}
	game->sprt = head;
	ft_lstclear(&(game->sprt));
}
