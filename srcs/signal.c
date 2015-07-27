/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 22:28:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/27 22:30:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_func(int sig)
{
	(void)sig;
}

void	ft_catch_sig(void)
{
	int sig;

	sig = 1;
	while (sig <= 31)
	{
		signal(sig++, ft_func);
	}
}
