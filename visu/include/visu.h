/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 17:29:13 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 14:52:13 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <curses.h>
# include "../../includes/ft_filler.h"

typedef struct	s_infos
{
	int			size_x;
	int			size_y;
	int			x;
	int			y;
	char		*p1login;
	char		*p2login;
	int			scorex;
	int			scoreo;
	int			i;
}				t_infos;

void			printinfo(t_infos *g);
void			print_gianttab(t_infos *g);
void			printcount(char *str, int count, t_infos *g);
void			printscore(t_infos *g);

#endif
