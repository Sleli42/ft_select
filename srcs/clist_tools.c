/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:00:33 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/15 02:00:34 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		create_ret_list(t_all *all)
{
	t_select	*tmp;

	tmp = all->select->head;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->select_arg)
				clst_add_elem_back(all->ret_list, clst_create_elem(tmp->arg));
			tmp = tmp->next;
		}
	}
}

int			update_list(t_clist *lst, t_select *elem)
{
	if (!elem->next && elem->prev)
	{
		lst->tail = elem->prev;
		lst->tail->next = NULL;
		ft_strdel(&elem->arg);
	}
	else if (!elem->prev && elem->next)
	{
		lst->head = elem->next;
		lst->head->prev = NULL;
		ft_strdel(&elem->arg);
	}
	else
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		ft_strdel(&elem->arg);
	}
	return (1);
}

t_clist		*clst_del_one(t_clist *lst, char *arg2del)
{
	t_select	*tmp;
	int			found;

	tmp = lst->head;
	found = 0;
	if (lst && arg2del && *arg2del)
	{
		while (tmp && !found)
		{
			if (ft_strncmp(tmp->arg, arg2del, ft_strlen(arg2del)) == 0)
			{
				if (!tmp->next && !tmp->prev)
					(lst->head->arg) ? ft_strdel(&lst->head->arg) : NULL;
				else
					found = update_list(lst, tmp);
				lst->lenght--;
				free(tmp);
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}

void		del_clist(t_clist **lst)
{
	t_select	*next_elem;
	t_select	*nav;

	nav = (*lst)->head;
	next_elem = NULL;
	if (nav)
	{
		while (nav && nav->next)
		{
			next_elem = nav->next;
			if (nav->arg)
				ft_strdel(&nav->arg);
			free(nav);
			nav = next_elem;
		}
	}
}
