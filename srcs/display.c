/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 21:00:35 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 21:00:38 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		display_lst(t_clist *lst)
{
	t_select	*tmp;

	tmp = lst->head;
	if (!tmp)
		return ;
	while (tmp)
	{
		ft_putstr(tmp->arg);
		if (tmp != lst->tail)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		display_arg(t_select *elem)
{
	struct stat		data;

	if (stat(elem->arg, &data) == -1)
		return (ft_putendl("error stat"));
	if (elem->select_arg)
		tputs_termcap("mr");
	else
		tputs_termcap("me");
	if (elem->on_arg)
		tputs_termcap("us");
	else
		tputs_termcap("ue");
	if (data.st_mode & S_IXOTH)
		ft_putstr(RED);
	if (data.st_mode & S_IFDIR)
		ft_putstr(BLUE);
	ft_putstr(elem->arg);
	ft_putstr(END);
}

void		horizontal_display(t_clist *lst, t_data *data)
{
	t_select	*tmp;
	int			ct;
	int			stop;

	tmp = lst->head;
	ct = 0;
	stop = 0;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (stop >= data->max_elems_by_row)
		{
			stop = 0;
			ft_putchar('\n');
		}
		display_arg(tmp);
		if (ct < (int)lst->lenght - 1)
			add_spaces((int)ft_strlen(tmp->arg), data->maxlen_arg + 2);
		ct += 1;
		stop += 1;
		tmp = tmp->next;
	}
}
