/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:17:10 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 18:17:27 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check(t_list *lst, double x, double y)
{
	while (lst != 0)
	{
		if ((int)(lst->aaa.c_x) == (int)x && (int)(lst->aaa.c_y) == (int)y)
			return (0);
		lst = lst->next;
	}
	return (1);
}
