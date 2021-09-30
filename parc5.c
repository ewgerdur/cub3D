#include "cub.h"

void	ft_direct(t_iparc *map, int i, int j)
{
	if (map->map[i][j] == 'S')
		map->direct = 'S';
	else if (map->map[i][j] == 'W')
		map->direct = 'W';
	else if (map->map[i][j] == 'E')
		map->direct = 'E';
	else if (map->map[i][j] == 'N')
		map->direct = 'N';
}

void	ft_check_zp(char *str)
{
	int	buba;

	buba = 0;
	while (*str)
	{
		if (*str == ',')
			buba++;
		str++;
	}
	if (buba == 2)
		return ;
	else
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}

void	ft_rcf_info(char **tmp_arr, int count, t_iparc *map)
{
	int	i;

	i = 0;
	if (tmp_arr[0] != NULL && i == 0)
	{
		if (!(ft_memcmp(tmp_arr[0], "R", 1
					+ ft_strlen(tmp_arr[0]))) && count == 3)
			ft_r(tmp_arr, map);
		else if (!(ft_memcmp(tmp_arr[0], "C",
					ft_strlen(tmp_arr[0]))) && count == 2)
		{
			ft_c(tmp_arr, map);
			map->dc += 1;
		}
		else if (!(ft_memcmp(tmp_arr[0], "F",
					ft_strlen(tmp_arr[0]))) && count == 2)
		{
			ft_f(tmp_arr, map);
			map->df += 1;
		}
		else
			ft_init_textorsprite(tmp_arr, count, map);
	}
	ft_ferror(map);
}

void	*ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	ft_er0255(t_iparc *map)
{
	if ((map->f1 < 0 || map->f1 > 255)
		|| (map->f2 < 0 || map->f2 > 255)
		|| (map->f3 < 0 || map->f3 > 255)
		|| (map->c1 < 0 || map->c1 > 255)
		|| (map->c2 < 0 || map->c2 > 255)
		|| (map->c3 < 0 || map->c3 > 255))
	{
		write(2, "ERROR\n", 6);
		exit(-1);
	}
}
