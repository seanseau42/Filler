/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/17 22:47:39 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/25 14:09:24 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void	splitfree(char **split)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (split[i])
		i++;
	while (j != i)
	{
		ft_strdel(&split[j]);
		j++;
	}
	free(split);
}

void	ft_get_player(t_player *player)
{
	char	*line;

	get_next_line(0, &line);
	if (line[10] == '1')
		player->carac = 'O';
	else
		player->carac = 'X';
	player->advercarac = (player->carac == 'X') ? 'O' : 'X';
	ft_strdel(&line);
}

void	ft_update_map(t_map *map, char *str)
{
	int		i;
	char	*line;
	char	**words;

	words = ft_strsplit(str, ' ');
	map->size_x = ft_atoi(words[1]);
	map->size_y = ft_atoi(words[2]);
	splitfree(words);
	if (map->pass != 1)
		map->tab = (char **)malloc(sizeof(char *) * (map->size_x + 1));
	map->pass = 1;
	i = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++i < map->size_x)
	{
		get_next_line(0, &line);
		map->tab[i] = ft_strdup(4 + line);
		ft_strdel(&line);
	}
	map->tab[i] = 0;
}

void	gettab(t_piece *piece, int i)
{
	char *line;

	while (++i < piece->size_x)
	{
		get_next_line(0, &line);
		piece->tab[i] = ft_strdup(line);
		ft_strdel(&line);
	}
	piece->tab[i] = 0;
}

void	ft_get_piece(t_piece *piece, int j, int i)
{
	char	*line;
	char	*str;

	get_next_line(0, &line);
	while (!(ft_isdigit(line[i])))
		i++;
	j = i;
	while (ft_isdigit(line[j]))
		j++;
	str = ft_strsub(line, i, j++ - i);
	piece->size_x = ft_atoi(str);
	ft_strdel(&str);
	i = j;
	while (ft_isdigit(line[j]))
		j++;
	str = ft_strsub(line, i, j - i);
	piece->size_y = ft_atoi(str);
	ft_strdel(&line);
	ft_strdel(&str);
	piece->tab = (char **)malloc(sizeof(char *) * (piece->size_x + 1));
	i = -1;
	gettab(piece, i);
}
