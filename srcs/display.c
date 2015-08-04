/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 21:39:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/04 19:00:58 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		lu_putchar(int c)
{
	ft_putchar(c);
	return (0);
}

void	tputs_termcap(char *tc)
{
	char	*res;

	if ((res = tgetstr(tc, NULL)) == NULL)
		return ;
	tputs(res, 0, lu_putchar);
}

int		display_choices(t_circular **lst)
{
	t_circular	*tmp;
	char		*ret;

	tmp = (*lst)->next;
	ret = NULL;
	if (tmp)
	{
		tputs_termcap("ue"), tputs_termcap("me");
		while (tmp)
		{
			if (tmp->select == 1 && tmp->arg != NULL)
				ret = ft_strjoin(ret, tmp->arg);
			ret = ft_strjoin(ret, " ");
			tmp = tmp->next;
			if (tmp == *lst)
			{
				ret = ft_strjoin(ret, "\n");
				tputs_termcap("cl");
				ft_putstr(ret);
				return (-1);
			}
		}
	}
	return (0);
}

void	display_list(t_circular *lst)
{
	t_circular	*nav;

	nav = lst->next;
	if (c_list_size(lst) == 0)
	{
		write(1, "\0", 1);
		return ;
	}
	while (nav)
	{
		if (nav->select == 1)
			tputs_termcap("mr");
		else
			tputs_termcap("me");
		if (nav->onArg == 1)
			tputs_termcap("us");
		else
			tputs_termcap("ue");
		ft_putendl(nav->arg);
		if (nav->next->arg == NULL)
			break ;
		nav = nav->next;
	}
	return ;
}
