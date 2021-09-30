/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:46:15 by wgerdur           #+#    #+#             */
/*   Updated: 2021/04/14 16:46:18 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_mapre(int r, char **tmp_map, char *str, int count)
{
	char	**a;
	int		i;
	int		size;

	i = 0;
	size = count + 1;
	if (r == 0)
		size = count + 2;
	a = (char **)malloc(sizeof(char *) * size);
	while (i < count - 1)
	{
		a[i] = tmp_map[i];
		i++;
	}
	free(tmp_map);
	a[count - 1] = str;
	return (a);
}

int	ft_check_allval(t_iparc *map, int i, int j)
{
	int	count;

	count = 0;
	count += ft_check_left(i, j, map);
	count += ft_check_leftcorn1(i, j, map);
	count += ft_check_down(i, j, map);
	count += ft_check_rightcorn1(i, j, map);
	count += ft_check_right(i, j, map);
	count += ft_check_rightcorn2(i, j, map);
	count += ft_check_up(i, j, map);
	count += ft_check_leftcorn2(i, j, map);
	if (count == 8)
		return (1);
	else
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
	return (0);
}

void	ft_init_flags(t_iparc *map)
{
	map->dr = -1;
	map->dno = -1;
	map->dso = -1;
	map->dea = -1;
	map->dwe = -1;
	map->ds = -1;
	map->dc = -1;
	map->df = -1;
}

void	ft_ferror(t_iparc *map)
{
	if (map->dr > 0
		|| map->dno > 0
		|| map->dso > 0
		|| map->dea > 0
		|| map->dwe > 0
		|| map->ds > 0
		|| map->dc > 0
		|| map->df > 0)
	{
		write(1, "ERORR\n", 6);
		exit(-1);
	}
}
