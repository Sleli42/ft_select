/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:46:53 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/15 02:46:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char		*elem_2_del(t_clist *lst, t_data *data)
{
	t_select	*tmp;

	tmp = lst->head;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (tmp->on_arg)
		{
			if (tmp->index == ((data->curr_line - 1) * data->max_elems_by_row))
				data->curr_line -= 1;
			if (tmp->prev)
				tmp->prev->on_arg = 1;
			else if (!tmp->prev)
				lst->tail->on_arg = 1;
			return (tmp->arg);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int			elem_exist(t_clist *lst, char *elem2find)
{
	t_select	*tmp;

	tmp = lst->head;
	if (!tmp || !elem2find || !*elem2find)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->arg, elem2find))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		delete_elem(t_all *all, char *elem2del)
{
	if (all->select->lenght == 0)
		return ;
	if (elem_exist(all->select, elem2del))
		clst_del_one(all->select, elem2del);
	define_nb_lines_writed(all->select, all->data);
}
