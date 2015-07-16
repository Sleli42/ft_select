/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 01:01:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/16 04:46:53 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <curses.h>

# include <stdio.h>

# define NOTATTY 1

typedef struct termios t_termios;

typedef struct		s_all
{
	struct termios		*default_term;
	struct termios		*term;
	struct s_circular	*lst;
}					t_all;

typedef struct		s_circular
{
	char				*arg;
	int					onArg;
	int					select;
	int					lenArg;
	struct s_circular	*next;
	struct s_circular	*prev;
}					t_circular;

void	print_list(t_circular *lst);

/*
** init.c
*/
t_all			*init_all(int ac, char **av);
int				init_tty(void);
void			init_termios(struct termios *term, char *s);
/*
** error.c
*/
void			termError(char *err);
/*
** list.c
*/
t_circular		*create_circular_list(int ac, char **av);
t_circular		*lst_create_elem(char *s);
void			lst_add_elem_back(t_circular **alst, t_circular *new_elem);

#endif
