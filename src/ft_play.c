/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_play.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/18 09:44:09 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/31 12:15:21 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		placeable(t_piece *p, t_result *r, t_map *m, t_player *pl)
{
	int x;
	int y;

	m->superp = 0;
	x = 0;
	while (x < p->size_x)
	{
		y = 0;
		while (y < p->size_y)
		{
			if (r->i + x >= m->size_x || r->j + y >= m->size_y)
				return (0);
			if (p->tab[x][y] == '*' && r->hm[r->i + x][r->j + y] == 0)
				return (0);
			if (p->tab[x][y] == '*' && m->tab[r->i + x][r->j + y] == pl->carac)
				m->superp = m->superp + 1;
			y++;
		}
		x++;
	}
	if (m->superp != 1)
		return (0);
	return (1);
}

void	ft_move(t_result *res)
{
	ft_putnbr(res->x);
	ft_putchar(' ');
	ft_putnbr(res->y);
	ft_putchar('\n');
}

void	ft_play(t_map *map, t_result *r, t_piece *p, t_player *pl)
{
	int i;
	int j;

	i = 0;
	r->score = 999;
	while (i < map->size_x)
	{
		j = 0;
		while (j < map->size_y)
		{
			r->i = i;
			r->j = j;
			if (placeable(p, r, map, pl) == 1 && r->hm[i][j] < r->score)
			{
				r->score = r->hm[i][j];
				r->x = i;
				r->y = j;
			}
			j++;
		}
		i++;
	}
	ft_move(r);
}
