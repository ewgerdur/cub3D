/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:32:32 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/19 15:32:37 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_leftcorn1(int i, int j, t_iparc *map)
{
	while (map->map[i])
	{
		if (map->map[i][j] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i][j] == ' ' || map->map[i][j] == 0)
			break ;
		i++;
		j--;
	}
	return (0);
}

int	ft_check_rightcorn1(int i, int j, t_iparc *map)
{
	while (map->map[i])
	{
		if (map->map[i][j] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i][j] == ' ' || map->map[i][j] == 0)
			break ;
		i++;
		j++;
	}
	return (0);
}

int	ft_check_leftcorn2(int i, int j, t_iparc *map)
{
	while (map->map[i])
	{
		if (map->map[i][j] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i][j] == ' ' || map->map[i][j] == 0 || i <= 0)
			break ;
		i--;
		j--;
	}
	return (0);
}

int	ft_check_rightcorn2(int i, int j, t_iparc *map)
{
	while (map->map[i])
	{
		if (map->map[i][j] == '1')
		{
			return (1);
			break ;
		}
		else if (map->map[i][j] == ' ' || map->map[i][j] == 0 || i <= 0)
			break ;
		i--;
		j++;
	}
	return (0);
}

int	get_s(t_game *game, int x, int y)
{
	char	*tmp;

	tmp = game->spt.s_addr + ((y * game->spt.s_len)
			+ x * (game->spt.s_bits / 8));
	return (*(unsigned int *)tmp);
}
