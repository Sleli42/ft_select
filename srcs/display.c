/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 21:39:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/31 01:29:23 by lubaujar         ###   ########.fr       */
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

int		check_next(t_circular *lst)
{
	t_circular	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next->select == 1)
			return (1);
		tmp = tmp->next;
		if (tmp->arg == NULL)
			return (0);
	}
	return (0);
}

int		display_choices(t_circular **lst)
{
	t_circular	*tmp;

	tmp = (*lst)->next;
	if (tmp)
	{
		tputs_termcap("ue");
		tputs_termcap("me");
		while (tmp)
		{
			if (tmp->select == 1)
			{
				ft_putstr(tmp->arg);
				if (check_next(tmp) == 1)
					write(1, " ", 1);
				else
					write(1, "\n", 1);
			}
			tmp = tmp->next;
			if (tmp == *lst)
				return (-1);
		}
	}
	return (0);
}

void	display_list(t_circular *lst)
{
	t_circular	*nav;

	nav = lst->next;
	if (list_size(lst) == 0)
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

/*			MEMO */
/*
	ve: curseur mode visible
	mr: Début de mode inverse
	so: Début de mode standout
	se: Fin de monde standout
	us: souligner
	cl: clear
	ho: Remettre le curseur à la positon de début
	cm: Déplacer le curseur à la ligne %1, colonne %2 (sur l'écran)
	hd: Déplacer le curseur d'une ligne vers le bas
	kr: Touche de déplacement du curseur vers la droite
	vi: Curseur invisible

	me: Fin de tous les modes tels que so, us, mb, md et mr
*/
