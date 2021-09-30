/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:41:36 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 16:41:38 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_swap_l(t_list *head)
{
	t_spt	t;

	if (head->next)
	{
		t = head->aaa;
		head->aaa = (head->next)->aaa;
		(head->next)->aaa = t;
	}
}

t_list	*ft_sort_list(t_list *head)
{
	t_list	*tmphead;
	t_list	*last;
	int		count;

	tmphead = head;
	if (!head)
		return (0);
	last = 0;
	count = 1;
	while (count)
	{
		count = 0;
		head = tmphead;
		while (head->next != last)
		{
			if (head->aaa.len_to_spt < (head->next)->aaa.len_to_spt)
			{
				count = 1;
				ft_swap_l(head);
			}
			head = head->next;
		}
		last = head;
	}
	return (tmphead);
}
