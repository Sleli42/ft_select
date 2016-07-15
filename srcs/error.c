/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:47:49 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/11 23:47:50 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		error(char *err)
{
	if (ft_strcmp(err, "MALLOC") == 0)
		ft_putendl("Malloc error.");
	return ;
}

void		term_error(char *err)
{
	if (!ft_strcmp(err, "GETENV"))
		ft_putstr("getenv() error\n");
	if (!ft_strcmp(err, "TGETENT"))
		ft_putstr("tgetent() error\n");
	if (!ft_strcmp(err, "TCGETATTR"))
		ft_putstr("tcgetattr() error\n");
	if (!ft_strcmp(err, "TCSETATTR"))
		ft_putstr("TCSETATTR() error\n");
}
