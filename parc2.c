/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:28:57 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/21 10:54:33 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_check_arr(int i, int j, int *cher, t_iparc *map)
{
	if (map->map[i][j] == '0' || map->map[i][j] == '2' || map->map[i][j] == 'S'
		|| map->map[i][j] == 'N' || map->map[i][j] == 'E'
		|| map->map[i][j] == 'W')
	{
		if (ft_check_allval(map, i, j) && (map->map[i][j] == 'S'
			|| map->map[i][j] == 'N' || map->map[i][j] == 'E'
			|| map->map[i][j] == 'W'))
		{
			(*cher)++;
			ft_direct(map, i, j);
		}
	}
	else if (map->map[i][j] != '1' && map->map[i][j] != ' ')
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}

void	ft_val1(t_iparc *map)
{
	ft_ferror(map);
	if (map->r_x > 1920)
		map->r_x = 1920;
	if (map->r_y > 1080)
		map->r_y = 1080;
	if (map->r_x < 100)
		map->r_x = 100;
	if (map->r_y < 100)
		map->r_y = 100;
	ft_check_val1(map);
	ft_er0255(map);
}

void	ft_val2(t_iparc *map)
{
	int	i;
	int	j;
	int	cher;

	i = 0;
	cher = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			ft_check_arr(i, j, &cher, map);
			j++;
		}
		i++;
	}
	if (!(cher == 1))
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}

static void	ft_prod(char **tmp_arr, int count, t_iparc *map)
{
	if (!(ft_memcmp(tmp_arr[0], "WE",
				ft_strlen(tmp_arr[0]) + 1)) && count == 2)
	{
		map->we = ft_strdup(tmp_arr[1]);
		map->dwe += 1;
	}
	else if (!(ft_memcmp(tmp_arr[0], "EA",
				ft_strlen(tmp_arr[0]) + 1)) && count == 2)
	{
		map->ea = ft_strdup(tmp_arr[1]);
		map->dea += 1;
	}
	else if (tmp_arr[0][0] != '0' || tmp_arr[0][0] != '1'
			|| tmp_arr[0][0] != '2' || tmp_arr[0][0] != 'N'
			|| tmp_arr[0][0] != 'S' || tmp_arr[0][0] != 'W'
			|| tmp_arr[0][0] != 'E')
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}

void	ft_init_textorsprite(char **tmp_arr, int count, t_iparc *map)
{
	if (!(ft_memcmp(tmp_arr[0], "NO", ft_strlen(tmp_arr[0]) + 1)) && count == 2)
	{
		map->no = ft_strdup(tmp_arr[1]);
		map->dno += 1;
	}
	else if (!(ft_memcmp(tmp_arr[0], "SO",
				ft_strlen(tmp_arr[0]) + 1)) && count == 2)
	{
		map->so = ft_strdup(tmp_arr[1]);
		map->dso += 1;
	}
	else if (!(ft_memcmp(tmp_arr[0], "S",
				ft_strlen(tmp_arr[0]) + 1)) && count == 2)
	{
		map->s = ft_strdup(tmp_arr[1]);
		map->ds += 1;
	}
	else
		ft_prod(tmp_arr, count, map);
}
