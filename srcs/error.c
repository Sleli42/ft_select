/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 02:30:28 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/16 04:24:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	termError(char *err)
{
	if (ft_strcmp(err, "getenv"))
		ft_putendl("Error GETENV(), var TERM == NULL\n");
	if (ft_strcmp(err, "tgetent"))
		ft_putendl("Error TGETENT, terminfo database could not be found\n");
	if (ft_strcmp(err, "tcgetattr"))
		ft_putendl("Error TCGETATTR, empty struct\n");
	if (ft_strcmp(err, "tcsetattr"))
		ft_putendl("Error TCSETATTR, no changes made\n");
	return ;
}
