/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 21:03:01 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 21:03:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		add_spaces(int currlen, int maxlen)
{
	int		tmp;

	tmp = currlen;
	while (tmp++ <= maxlen)
		ft_putchar(' ');
}

void		goto_first_line(t_data *data)
{
	int		ct;

	ct = 0;
	while (++ct < data->nb_lines_writed)
		tputs_termcap("up");
	ct = 0;
	while (++ct < data->max_cols)
		tputs_termcap("le");
}

void		refresh_screen(int nb_lines)
{
	int		ct;

	ct = 0;
	while (ct++ < nb_lines)
	{
		tputs_termcap("ce");
		tputs_termcap("cb");
		tputs_termcap("do");
	}
	while (--ct)
		tputs_termcap("up");
}
