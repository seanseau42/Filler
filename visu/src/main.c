/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/15 14:40:50 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/22 12:28:56 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/visu.h"

void	ft_getlogins(t_infos *game)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "resources") != 0)
	{
		game->p1login = ft_strdup(36 + line);
		get_next_line(0, &line);
		get_next_line(0, &line);
		game->p2login = ft_strdup(18 + line);
	}
	else
	{
		game->p1login = ft_strdup(18 + line);
		get_next_line(0, &line);
		get_next_line(0, &line);
		game->p2login = ft_strdup(36 + line);
	}
	game->p1login[ft_strlen(game->p1login) - 8] = '\0';
	game->p2login[ft_strlen(game->p2login) - 8] = '\0';
}

void	ft_gatherinfo(t_infos *game)
{
	int		i;
	char	*line;
	char	**words;

	i = -1;
	getmaxyx(stdscr, game->x, game->y);
	while (++i != 6)
		get_next_line(0, &line);
	ft_getlogins(game);
	get_next_line(0, &line);
	words = ft_strsplit(line, ' ');
	game->size_x = ft_atoi(words[1]);
	game->size_y = ft_atoi(words[2]);
	game->scoreo = 0;
	game->scorex = 0;
}

void	apply_color(char *str, t_infos *g, int count)
{
	int		mid;

	mid = g->x / 2 + g->i - g->size_x / 2;
	if (str[count] == 'X')
	{
		attron(COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
		mvprintw(mid, g->y / 2 + count - ft_strlen(str) / 2, "x");
		attroff(COLOR_PAIR(1) | A_STANDOUT | A_BOLD);
	}
	if (str[count] == '.')
	{
		attron(COLOR_PAIR(3) | A_BOLD);
		mvprintw(mid, g->y / 2 + count - ft_strlen(str) / 2, ".");
		attroff(COLOR_PAIR(3) | A_BOLD);
	}
	if (str[count] == 'O')
	{
		attron(COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
		mvprintw(mid, g->y / 2 + count - ft_strlen(str) / 2, "o");
		attroff(COLOR_PAIR(2) | A_STANDOUT | A_BOLD);
	}
	printcount(str, count, g);
	if (g->size_x < g->y && g->size_y < g->x)
		refresh();
}

void	print_tab(char *str, t_infos *g)
{
	int		count;

	start_color();
	init_color(COLOR_CYAN, 500, 500, 500);
	init_color(COLOR_YELLOW, 600, 900, 950);
	init_color(COLOR_GREEN, 850, 400, 550);
	init_color(COLOR_RED, 650, 100, 300);
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_CYAN);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	count = -1;
	while (++count < (int)ft_strlen(str))
		apply_color(str, g, count);
	refresh();
}

int		main(void)
{
	char	*line;
	t_infos game;

	initscr();
	curs_set(0);
	ft_gatherinfo(&game);
	while (get_next_line(0, &line))
	{
		if (line[0] == 'P' && line[1] == 'l')
		{
			get_next_line(0, &line);
			game.i = -1;
			while (++game.i < game.size_x)
			{
				get_next_line(0, &line);
				print_tab(line, &game);
			}
			printinfo(&game);
		}
	}
	endwin();
	printscore(&game);
	return (0);
}
