/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 02:30:28 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/31 00:44:56 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	termError(char *err)
{
	if (ft_strcmp(err, "getenv") == 0)
		ft_putendl("Error GETENV(), var TERM == NULL\n");
	if (ft_strcmp(err, "tgetent") == 0)
		ft_putendl("Error TGETENT, terminfo database could not be found\n");
	if (ft_strcmp(err, "tcgetattr[init]") == 0)
		ft_putendl("Error TCGETATTR[init], empty struct\n");
	if (ft_strcmp(err, "tcsetattr") == 0)
		ft_putendl("Error TCSETATTR, no changes made\n");
	if (ft_strcmp(err, "tcgetattr[reset]") == 0)
		ft_putendl("Error TCGETATTR[reset], empty struct\n");
	if (ft_strcmp(err, "tcsetattr[reset]") == 0)
		ft_putendl("Error TCSETATTR[reset], no changes made\n");
	return ;
}
