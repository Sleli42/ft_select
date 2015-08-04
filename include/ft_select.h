/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 01:01:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/04 18:56:08 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <curses.h>
# include <sys/ioctl.h>

# include <stdio.h>

# define NOTATTY 1

# define K_UP			(buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
# define K_DOWN			(buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
# define K_RIGHT		(buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
# define K_LEFT			(buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
# define K_SPACE		(buff[0] == 32 && !buff[1] && !buff[2])
# define K_ECHAP		(buff[0] == 27 && !buff[1] && !buff[2])
# define K_BACKSPACE	(buff[0] == 27 && buff[1] == 91 && buff[2] == 51)
# define K_DELETE		(buff[0] == 127 && !buff[1] && !buff[2])
# define K_ENTER		(buff[0] == 10 && !buff[1] && !buff[2])

typedef struct termios t_termios;

typedef struct		s_all
{
	struct termios		default_term;
	struct termios		term;
	struct winsize		ws;
	int					tty;
	size_t				maxlen;
	struct s_circular	*lst;
}					t_all;

typedef struct		s_circular
{
	char				*arg;
	int					onArg;
	int					select;
	int					lenArg;
	size_t				index;
	struct s_circular	*next;
	struct s_circular	*prev;
}					t_circular;


/*
** main.c
*/
void				loop(t_all *all);
void				reset_term(t_termios default_term);
/*
** init.c
*/
t_all				*init_all(int ac, char **av);
int					init_tty(void);
void				init_termios(struct termios term);
void				init_windows_size(t_all *all);
/*
** error.c
*/
void				term_error(char *err);
/*
** list.c
*/
t_circular			*create_circular_list(int ac, char **av);
t_circular			*lst_create_elem(char *s);
void				lst_add_elem_back(t_circular **lst, t_circular *new_elem);
size_t				c_list_size(t_circular *lst);
void				del_circular_list(t_circular **lst);
/*
** utils.c
*/
t_all				*f_cpy(t_all *all);
size_t				define_maxlen(t_circular *lst);
int					delete_elem(t_circular **lst);
int					key_hook(t_circular *lst);
/*
** display.c
*/
int					my_outc(int c);
int					display_choices(t_circular **lst);
void				tputs_termcap(char *tc);
void				display_list(t_circular *lst);
/*
** signal.c
*/
void				c_list_del_one(t_circular *elem);
void				ft_catch_sig(void);
void				ft_func(int sig);
/*
** moves.c
*/
int					move_cursor_up(t_circular **lst);
int					move_cursor_down(t_circular **lst);
int					select_cursor(t_circular **lst);
#endif
