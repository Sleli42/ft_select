/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 01:01:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/15 05:46:22 by lubaujar         ###   ########.fr       */
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

typedef struct s_all
{
	struct termios	*default_term;
	struct termios	*term;
}				t_all;

/*
** init.c
*/
int		init_tty(void);

#endif
