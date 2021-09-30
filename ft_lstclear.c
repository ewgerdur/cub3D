/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:06:49 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 18:07:13 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*buf_lst;
	t_list	*save_lst;

	if (*lst && lst)
	{
		buf_lst = (*lst);
		while (buf_lst)
		{
			save_lst = buf_lst->next;
			free(buf_lst);
			buf_lst = save_lst;
		}
		(*lst) = NULL;
	}
}
