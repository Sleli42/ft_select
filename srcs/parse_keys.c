/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 02:59:24 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 03:05:26 by lubaujar         ###   ########.fr       */
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

void		delete_elem(t_all *all, char *elem2del)
{
	if (all->select->lenght == 0)
		return ;
	clst_del_one(all->select, elem2del);
	clst_del_one(all->ret_list, elem2del);
	define_nb_lines_writed(all->select, all->data);
}

void		parse_keys(t_all *all, int key)
{
	if (key == K_DOWN)
		try_down_moves(all->select, all->data);
	else if (key == K_UP)
		try_up_moves(all->select, all->data);
	else if (key == K_LEFT || key == K_RIGHT)
		try_horizontal_moves(all->select, all->data, key);
	else if (key == K_SPACE)
		select_choice(all->select, all->data, all->ret_list);
	else if (key == K_BACKSPACE || key == K_DELETE)
		delete_elem(all, elem_2_del(all->select, all->data));
}

int			getkey(char *s)
{
	int			result;
	int			i;
	int			mult;
	int			value;

	result = 0;
	i = 0;
	while (i < 6)
	{
		mult = 10;
		value = s[i];
		while (value > 10)
		{
			mult *= 10;
			value /= 10;
		}
		result = result * mult + s[i];
		i++;
	}
	return (result);
}

int			check_keys_arrows(t_all *all, char *buff)
{
	all->key_arrow = getkey(buff);
	if (*buff == 32)
		all->key_arrow = 32;
	else if (buff[0] == 27 && !buff[1])
		all->key_arrow = 27;
	if (all->key_arrow == K_ENTER || all->key_arrow == K_ECHAP)
		return (-1);
	if (all->key_arrow == K_RIGHT || all->key_arrow == K_LEFT
		|| all->key_arrow == K_UP || all->key_arrow == K_DOWN
		|| all->key_arrow == K_SPACE || all->key_arrow == K_BACKSPACE
		|| all->key_arrow == K_DELETE)
		return (1);
	return (0);
}

int			read_keys(t_all *all)
{
	int		key;
	char	*buff;

	key = 0;
	buff = ft_strnew(MAX_READ);
	if (read(0, buff, MAX_READ) == -1)
	{
		ft_putendl("Error read.."); 
		return (0);
	}
	if ((key = check_keys_arrows(all, buff)) < 0)
		return (0);
	else if (key > 0)
		return 1;
	ft_strdel(&buff);
	return (42);
}
