/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filler.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/08 11:38:47 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/25 14:13:05 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct	s_map
{
	int			size_x;
	int			size_y;
	char		**tab;
	short		superp;
	int			pass;
}				t_map;

typedef struct	s_piece
{
	int			size_x;
	int			size_y;
	char		**tab;
}				t_piece;

typedef struct	s_player
{
	char		carac;
	char		advercarac;
}				t_player;

typedef struct	s_result
{
	int			**hm;
	int			x;
	int			y;
	int			score;
	int			i;
	int			j;
}				t_result;

void			splitfree(char **split);
void			ft_get_player(t_player *player);
void			ft_update_map(t_map *map, char *str);
void			gettab(t_piece *piece, int i);
void			ft_get_piece(t_piece *piece, int j, int i);

int				ft_isconverted(t_map *map, int **tab);
void			ft_getinttab(t_result *res, t_map *map, t_player *player);
void			ft_heatmap(t_result *res, t_map *map, int i, int x);
void			ft_think(t_result *res, t_map *map, t_player *player);
int				**ft_malloctab(t_map *map);

int				placeable(t_piece *p, t_result *r, t_map *m, t_player *pl);
void			ft_play(t_map *map, t_result *res, t_piece *p, t_player *pl);

#endif
