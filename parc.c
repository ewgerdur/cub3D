/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:21:34 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/21 11:35:20 by egektor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_map_parc(char *str, int res_open, t_iparc *map)
{
	char	**tmp_map;
	int		r;
	int		count;

	count = 1;
	r = 1;
	if (str[0] != '\0')
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	while (get_next_line(res_open, &str) && !(str[0] != '\0'))
	{
		free(str);
	}
	tmp_map = (char **)malloc(sizeof(char *) * count);
	tmp_map[0] = str;
	while (r)
	{
		r = get_next_line(res_open, &str);
		tmp_map = ft_mapre(r, tmp_map, str, ++count);
	}
	tmp_map[count] = 0;
	map->map = tmp_map;
}

static void	ft_fi_parc(char *str, t_iparc *map)
{
	char	**temp_arr;
	int		i;

	i = 0;
	if (str[0] != '\n')
	{
		temp_arr = ft_split(str, ' ');
		while (temp_arr[i])
		{
			i++;
		}
		ft_rcf_info(temp_arr, i, map);
		ft_free(temp_arr, i);
	}
}

static void	ft_init_struct1(t_iparc *map)
{
	map->r_x = -1;
	map->r_y = -1;
	map->f1 = -1;
	map->c1 = -1;
	map->f2 = -1;
	map->c2 = -1;
	map->f3 = -1;
	map->c3 = -1;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->s = 0;
	map->map = 0;
	map->direct = 0;
	ft_init_flags(map);
}

static int	ft_check_valid_flag(t_iparc *map)
{
	if (map->r_x == -1 || map->no == 0 || map->so == 0 || map->we == 0
		|| map->ea == 0 || map->s == 0
		|| map->c1 == -1 || map->f1 == -1)
		return (0);
	return (1);
}

void	ft_parc(int argc, char **argv, t_iparc *map)
{
	char	*str;
	int		res_open;

	argc = 0;
	str = NULL;
	if (argc != 0)
		return ;
	res_open = open(argv[1], O_RDONLY);
	ft_check_res_open(res_open);
	ft_init_struct1(map);
	while (get_next_line(res_open, &str) && !(ft_check_valid_flag(map)))
	{
		ft_fi_parc(str, map);
		free(str);
	}
	ft_map_parc(str, res_open, map);
	free(str);
	ft_val1(map);
	ft_val2(map);
	ft_ferror(map);
	close(res_open);
}
