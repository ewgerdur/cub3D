/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:44:29 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/14 16:45:20 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_w_f(char **parc_color, int bub, int count, t_iparc *map)
{
	if (bub == 0 && count == 3)
	{
		map->f1 = ft_atoi(parc_color[0]);
		map->f2 = ft_atoi(parc_color[1]);
		map->f3 = ft_atoi(parc_color[2]);
	}
}

static void	ft_w_c(char **parc_color, int bub, int count, t_iparc *map)
{
	if (bub == 1 && count == 3)
	{
		map->c1 = ft_atoi(parc_color[0]);
		map->c2 = ft_atoi(parc_color[1]);
		map->c3 = ft_atoi(parc_color[2]);
	}
}

void	ft_c(char **parc_arr, t_iparc *map)
{
	char	**parc_color;
	int		count;
	int		i;

	ft_check_zp(parc_arr[1]);
	parc_color = ft_split(parc_arr[1], ',');
	count = 0;
	while (parc_color[count])
	{
		i = 0;
		while (parc_color[count][i])
		{
			if (!(ft_isdigit(parc_color[count][i])))
			{
				write(2, "ERROR\n", 6);
				exit(-1);
			}
			i++;
		}
		count++;
	}
	ft_w_c(parc_color, 1, count, map);
	ft_free(parc_color, count);
}

void	ft_f(char **tmp_arr, t_iparc *map)
{
	char	**a_f;
	int		count;
	int		i;

	ft_check_zp(tmp_arr[1]);
	a_f = ft_split(tmp_arr[1], ',');
	count = 0;
	while (a_f[count])
	{
		i = 0;
		while (a_f[count][i])
		{
			if (!(ft_isdigit(a_f[count][i])))
			{
				write(2, "ERROR\n", 6);
				exit(-1);
			}
			i++;
		}
		count++;
	}
	ft_w_f(a_f, 0, count, map);
	ft_free(a_f, count);
}

void	ft_r(char **tmp_arr, t_iparc *map)
{
	int	i;

	i = 0;
	while (tmp_arr[1][i])
	{
		if (!(ft_isdigit(tmp_arr[1][i])))
		{
			write(1, "ERORR\n", 6);
			exit(-1);
		}
		i++;
	}
	i = 0;
	while (tmp_arr[2][i])
	{
		if (!(ft_isdigit(tmp_arr[2][i])))
		{
			write(1, "ERORR\n", 6);
			exit(-1);
		}
		i++;
	}
	map->r_x = ft_atoi(tmp_arr[1]);
	map->r_y = ft_atoi(tmp_arr[2]);
	map->dr += 1;
}
