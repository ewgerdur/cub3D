/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:12:10 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 18:12:28 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list	*ft_lstnew(t_game *game, double buf_d_x, double buf_d_y, double degree)
{
	t_list	*headpre;

	headpre = (t_list *)malloc(sizeof(t_list));
	if (!headpre)
		return (0);
	headpre->aaa.c_x = (int)(buf_d_x);
	headpre->aaa.c_y = (int)(buf_d_y);
	headpre->aaa.len_to_spt = sqrt((buf_d_x - game->x)
			* (buf_d_x - game->x) + (buf_d_y - game->y)
			* (buf_d_y - game->y)) * sqrt(cos(degree));
	headpre->next = 0;
	return (headpre);
}
