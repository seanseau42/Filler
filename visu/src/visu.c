/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 13:21:27 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/16 14:51:56 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/visu.h"

void	printcount(char *str, int count, t_infos *g)
{
	if (str[count] == 'o')
	{
		attron(COLOR_PAIR(4) | A_STANDOUT | A_BOLD);
		mvprintw(g->x / 2 + g->i - g->size_x / 2, g->y / 2 + count -
				ft_strlen(str) / 2, "o");
		g->scoreo += 1;
		attroff(COLOR_PAIR(4) | A_STANDOUT | A_BOLD);
	}
	if (str[count] == 'x')
	{
		attron(COLOR_PAIR(5) | A_STANDOUT | A_BOLD);
		mvprintw(g->x / 2 + g->i - g->size_x / 2, g->y / 2 + count -
				ft_strlen(str) / 2, "x");
		g->scorex += 1;
		attroff(COLOR_PAIR(5) | A_STANDOUT | A_BOLD);
	}
}

void	print_gianttab(t_infos *g)
{
	mvprintw(g->x / 2 - 2, g->y / 2 - g->size_y, "FILLER");
	attron(COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
	mvprintw(g->x / 2, g->y / 2 - g->size_y - ft_strlen(g->p1login) - 2, "%s",
			g->p1login);
	attroff(COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
	attron(COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
	mvprintw(g->x / 2, g->y / 2 - g->size_y + 8, "%s", g->p2login);
	attroff(COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
	mvprintw(g->x / 2, g->y / 2 - g->size_y + 2, "vs");
	mvprintw(g->x / 2 + 2, g->y / 2 - g->size_y - ft_strlen(g->p1login) - 2,
			"%d", g->scoreo);
	mvprintw(g->x / 2 + 2, g->y / 2 - g->size_y + 8, "%d", g->scorex);
}

void	printinfo(t_infos *g)
{
	if (g->size_x < g->y && g->size_y < g->x)
	{
		mvprintw(g->x / 2 - g->size_x / 2 - 2, g->y / 2 - 1, "FILLER");
		attron(COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
		mvprintw(g->x / 2 + g->size_x / 2 + 2, g->y / 2 - ft_strlen(g->p1login)
				/ 2 - ft_strlen(g->p2login) / 2 - 4, "%s", g->p1login);
		attroff(COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
		attron(COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
		mvprintw(g->x / 2 + g->size_x / 2 + 2, g->y / 2 + ft_strlen(g->p2login)
				, "%s", g->p2login);
		attroff(COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
		mvprintw(g->x / 2 + g->size_x / 2 + 4, g->y / 2 - ft_strlen(g->p1login)
				/ 2 - ft_strlen(g->p2login) / 2 - 4, "%d", g->scoreo);
		mvprintw(g->x / 2 + g->size_x / 2 + 4, g->y / 2 + ft_strlen(g->p2login)
				, "%d", g->scorex);
		mvprintw(g->x / 2 + g->size_x / 2 + 2, g->y / 2 + 2, "vs");
	}
	else
		print_gianttab(g);
}

void	printscore(t_infos *g)
{
	ft_putstr("PARTIE TERMINEE\n");
	if (g->scoreo > g->scorex)
	{
		ft_putstr(g->p1login);
		ft_putstr(" remporte la partie avec un score de [");
		ft_putnbr(g->scoreo);
		ft_putstr("] contre [");
		ft_putnbr(g->scorex);
		ft_putstr("]\n");
	}
	if (g->scoreo < g->scorex)
	{
		ft_putstr(g->p2login);
		ft_putstr(" remporte la partie avec un score de [");
		ft_putnbr(g->scorex);
		ft_putstr("] contre [");
		ft_putnbr(g->scoreo);
		ft_putstr("]\n");
	}
}
