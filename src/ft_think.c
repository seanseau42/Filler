/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_think.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 22:51:39 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/31 12:16:45 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		**ft_malloctab(t_map *map)
{
	int		**tab;
	int		i;

	if (!(tab = (int **)malloc(sizeof(int *) * (map->size_x))))
		return (0);
	i = 0;
	while (i < map->size_x)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * (map->size_y))))
			return (0);
		i++;
	}
	return (tab);
}

int		ft_isconverted(t_map *map, int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < map->size_x)
	{
		j = 0;
		while (j < map->size_y)
		{
			if (tab[i][j] == -2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_getinttab(t_result *res, t_map *map, t_player *player)
{
	int i;
	int j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == player->advercarac)
				res->hm[i][j] = 0;
			else if (map->tab[i][j] == '.' || map->tab[i][j] == player->carac)
				res->hm[i][j] = -2;
			j++;
		}
		i++;
	}
}

void	ft_heatmap(t_result *r, t_map *map, int i, int x)
{
	int j;

	while (i < map->size_x)
	{
		j = -1;
		while (++j < map->size_y)
		{
			if (r->hm[i][j] == x)
			{
				if (i + 1 < map->size_x && r->hm[i + 1][j] != x && r->hm[i + 1]
				[j] != 0 && r->hm[i + 1][j] != x - 1)
					r->hm[i + 1][j] = x + 1;
				if (i - 1 >= 0 && r->hm[i - 1][j] != x && r->hm[i - 1][j] != 0
						&& r->hm[i - 1][j] != x - 1)
					r->hm[i - 1][j] = x + 1;
				if (j - 1 >= 0 && r->hm[i][j - 1] != x && r->hm[i][j - 1] != 0
						&& r->hm[i][j - 1] != x - 1)
					r->hm[i][j - 1] = x + 1;
				if (j + 1 < map->size_y && r->hm[i][j + 1] != x && r->hm[i][j +
				1] != 0 && r->hm[i][j + 1] != x - 1)
					r->hm[i][j + 1] = x + 1;
			}
		}
		i++;
	}
}

void	ft_think(t_result *res, t_map *map, t_player *player)
{
	int x;

	res->hm = ft_malloctab(map);
	ft_getinttab(res, map, player);
	x = 0;
	while (ft_isconverted(map, res->hm) == 0)
	{
		ft_heatmap(res, map, 0, x);
		x++;
	}
}
