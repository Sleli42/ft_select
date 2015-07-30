/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 21:39:43 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/30 21:10:58 by lubaujar         ###   ########.fr       */
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
