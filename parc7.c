/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:34:36 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 15:34:39 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_right(int i, int j, t_iparc *map)
{
	int	j1;

	j1 = j + 1;
	while (map->map[i][j1])
	{
		if (map->map[i][j1] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i][j1] == ' ' || map->map[i][j1] == 0)
			break ;
		j1++;
	}
	return (0);
}

int	ft_check_left(int i, int j, t_iparc *map)
{
	int	j1;

	j1 = j - 1;
	while (j1 >= 0)
	{
		if (map->map[i][j1] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i][j1] == ' ' || map->map[i][j1] == 0)
			break ;
		j1--;
	}
	return (0);
}

int	ft_check_down(int i, int j, t_iparc *map)
{
	int	i1;

	i1 = i + 1;
	while (map->map[i1])
	{
		if (map->map[i1][j] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i1][j] == ' ' || map->map[i1][j] == 0)
			break ;
		i1++;
	}
	return (0);
}

int	ft_check_up(int i, int j, t_iparc *map)
{
	int	i1;

	i1 = i - 1;
	while (i1 >= 0)
	{
		if (map->map[i1][j] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i1][j] == ' ' || map->map[i1][j] == 0)
			break ;
		i1--;
	}
	return (0);
}

void	ft_check_res_open(int res_open)
{
	if (0 > res_open)
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}
