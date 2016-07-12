/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:37:24 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/11 23:37:26 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <sys/ioctl.h>

# define NOTATTY 		1
# define MAX_READ		3
# define K_UP			279165000
# define K_DOWN			279166000
# define K_RIGHT		279167000
# define K_LEFT			279168000
# define K_ENTER		1000000

typedef struct winsize	t_winsize;

typedef struct			s_select
{
	char				*arg;
	int					on_arg;
	int					select_arg;
	struct s_select		*next;
	struct s_select		*prev;
}						t_select;

typedef struct			s_clist
{
	struct s_select		*head;
	struct s_select		*tail;
	size_t				lenght;
}						t_clist;

typedef struct			s_data
{
	t_winsize			ws;
	int					max_rows;
	int					max_cols;
	int					maxlen_arg;
	int					max_elems_by_row;
	int					curr_row;
	// int					curr_col;
	int					nb_lines_writed;
}						t_data;

typedef	struct			s_all
{
	t_data				*data;
	t_clist				*select;
	char				**dupenv;
}						t_all;

/*
*** |================================================|
*** |				loop.c					 	 	 |
*** |================================================|
*/
void		select_loop(t_all *all);
/*
*** |================================================|
*** |				parse_keys.c					 |
*** |================================================|
*/
int			getkey(char *s);
int			check_keys_arrows(char *buff);
int			read_keys();
/*
*** |================================================|
*** |				select_tools.c					 |
*** |================================================|
*/
char		**ft_dupenv(char **env);
void		parse_cursor_row(t_data *data, char *buff);
char		*get_cursor_row_loop(char *buff);
void		get_cursor_row(t_data *data);
/*
*** |================================================|
*** |				init.c					 		 |
*** |================================================|
*/
int			init_tty();
void		init_windows_size(t_data *data);
t_all		*init_all(char **env);
/*
*** |================================================|
*** |				error.c					 		 |
*** |================================================|
*/
void		error(char *err);
void		term_error(char *err);
/*
*** |================================================|
*** |				termcaps.c					 	 |
*** |================================================|
*/
void		init_term(char **dupenv);
void		reset_term();
int			lu_putchar(int c);
void		tputs_termcap(char *tc);
/*
*** |================================================|
*** |				clist.c					 	 	 |
*** |================================================|
*/
t_clist		*create_clst(void);
t_select	*clst_create_elem(char *s);
t_clist		*clst_add_elem_back(t_clist *lst, t_select *node);
void		del_clist(t_clist **lst);

#endif
