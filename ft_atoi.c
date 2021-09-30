/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:58:05 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/14 16:25:15 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_atoi(char *str)
{
	long int	c;
	long int	q;
	long int	number;

	c = 0;
	q = 1;
	number = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n'
		|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '-')
		q = -1;
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
		number = number * 10 + str[c++] - '0';
	return ((int)number * q);
}
