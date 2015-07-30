/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 04:08:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/30 21:25:14 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_circular	*create_circular_list(int ac, char **av)
{
	t_circular	*lst;
	int			i;

	lst = NULL;
	i = 1;
	lst = lst_create_elem(NULL);
	while (i < ac)
		lst_add_elem_back(&lst, lst_create_elem(av[i])), i++;
	return (lst);
}

t_circular		*lst_create_elem(char *s)
{
	t_circular		*new;
	static size_t	i = 1;

	if (!(new = (t_circular *)malloc(sizeof(t_circular))))
		return (NULL);
	new->arg = (s == NULL) ? NULL : ft_strdup(s);
	new->index = i++;
	new->onArg = (new->index == 1) ? 1 : 0;
	new->select = 0;
	new->lenArg = (s == NULL) ? 0 : ft_strlen(s);
	new->next = new;
	new->prev = new;
	return (new);
}

void		lst_add_elem_back(t_circular **alst, t_circular *new_elem)
{
	t_circular	*curr;

	curr = *alst;
	if (new_elem != NULL && *alst != NULL)
	{
		while (curr->next != *alst)
			curr = curr->next;
		curr->next = new_elem;
		new_elem->prev = curr;
		new_elem->next = (*alst);
		(*alst)->prev = new_elem;
	}
	else
		*alst = new_elem;
}

size_t	list_size(t_circular *lst)
{
	t_circular	*tmp;
	int			ret;

	tmp = lst->next;
	ret = 0;
	if (tmp == lst)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
		if (tmp == lst)
			return (ret);
	}
	return (ret);
}

void	list_del_one(t_circular *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	ft_strdel(&elem->arg);
	free(elem);
}

int		delete_elem(t_circular **lst)
{
	t_circular	*temp;

	temp = (*lst)->next;
	if (temp->next == *lst)
	{
		list_del_one(temp);
		return (1);
	}
	while (temp)
	{
		if (temp->onArg == 1)
		{
			list_del_one(temp);
			if (temp->next->arg != NULL)
				temp->next->onArg = 1;
			else
				temp->next->next->onArg = 1;
			return (1);
		}
		temp = temp->next;
		if (temp == *lst)
			break ;
	}
	return (-1);
}

void	del_circular_list(t_circular **lst)
{
	t_circular	*nextElem;
	t_circular	*tmp;

	tmp = *lst;
	nextElem = NULL;
	if (tmp)
	{
		while (tmp)
		{
			nextElem = tmp->next;
			if (tmp->arg)
				ft_strdel(&tmp->arg);
			if (tmp)
				free(tmp);
			tmp = nextElem;
			if (tmp == *lst)
				return ;
		}
	}
}
