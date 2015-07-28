/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 04:08:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/28 04:10:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_circular	*create_circular_list(int ac, char **av)
{
	t_circular	*lst;
	int			i;
	int			first;

	lst = NULL;
	i = 1;
	first = 0;
	while (i < ac)
	{
		if (first == 0)
			lst_add_elem_back(&lst, lst_create_elem(av[i], 1)), i++;
		else
			lst_add_elem_back(&lst, lst_create_elem(av[i], 0)), i++;
		first++;
	}
	return (lst);
}

t_circular		*lst_create_elem(char *s, int onArg)
{
	t_circular		*new;

	if (!(new = (t_circular *)malloc(sizeof(t_circular))))
		return (NULL);
	new->arg = (s == NULL) ? NULL : ft_strdup(s);
	new->onArg = onArg;
	new->select = 0;
	new->lenArg = ft_strlen(s);
	new->next = new;
	new->prev = new;
	return (new);
}

void		lst_add_elem_back(t_circular **alst, t_circular *new_elem)
{
	t_circular	*curr;

	curr = *alst;
	if (new_elem != NULL)
	{
		if (*alst == NULL)
			*alst = new_elem;
		else
		{
			while (curr->next != *alst)
				curr = curr->next;
			curr->next = new_elem;
			new_elem->prev = curr;
			new_elem->next = *alst;
			(*alst)->prev = new_elem;
		}
	}
	else
		return ;
}

void	del_circular_list(t_circular *lst)
{
	t_circular	*nextElem;
	t_circular	*tmp;

	tmp = lst;
	nextElem = NULL;
	if (tmp)
	{
		while (tmp)
		{
			nextElem = tmp->next;
			if (tmp->arg)
				free(tmp->arg);
			if (tmp)
				free(tmp);
			tmp = nextElem;
		}
	}
}
