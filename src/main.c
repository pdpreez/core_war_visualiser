/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:39:11 by ppreez            #+#    #+#             */
/*   Updated: 2018/09/19 10:39:22 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cwv.h"
/*
int	main(void)
{
	int ch;
	int row;
	int col;

	initscr();
	raw();
	noecho();
	getmaxyx(stdscr, col, row);
	init_color(COLOR_RED, 0, 0, 0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(0, 0, "Hello World\t");
	mvprintw(1, 0, "The size of the window is %d x %d\n", col, row);
	refresh();
	keypad(stdscr, TRUE);
	ch = getch();
	attroff(COLOR_PAIR(1));
	printw("Goodbye World");
	refresh();
	sleep(1);
	endwin();
	return (1);
}*/

#include <panel.h>

int main()
{	
	WINDOW *my_wins[2];

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	my_wins[0] = newwin(32, 64, 0, 0);
	my_wins[1] = newwin(32, 32, 0, 65);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	mvwprintw(my_wins[0], 1, 1, "Hello");
	wattron(my_wins[1], COLOR_PAIR(1));
	mvwprintw(my_wins[1], 1, 1, "Bitch");
	wattroff(my_wins[0], A_REVERSE | COLOR_PAIR(1));
	wattroff(my_wins[1], A_REVERSE | COLOR_PAIR(1));
	box(my_wins[0], 0, 0);
	box(my_wins[1], 0, 0);
	refresh();
	wrefresh(my_wins[0]);
	wrefresh(my_wins[1]);
	
	getch();
	endwin();
}