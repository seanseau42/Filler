/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 22:46:55 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/30 17:54:27 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void	freeturn(t_map *map, t_piece *piece)
{
	int i;

	i = -1;
	while (++i != map->size_x)
		ft_strdel(&map->tab[i]);
	i = -1;
	while (++i != piece->size_x)
		ft_strdel(&piece->tab[i]);
}

int		main(void)
{
	char		*line;
	t_map		map;
	t_piece		piece;
	t_player	player;
	t_result	result;

	ft_get_player(&player);
	while (get_next_line(0, &line))
	{
		ft_update_map(&map, line);
		ft_get_piece(&piece, 0, 0);
		ft_think(&result, &map, &player);
		ft_play(&map, &result, &piece, &player);
		freeturn(&map, &piece);
	}
	return (0);
}
