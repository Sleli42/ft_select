/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 04:08:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/16 05:06:21 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_circular	*create_circular_list(int ac, char **av)
{
	t_circular	*lst;
	int			i;

	lst = NULL;
	i = 1;
	while (i < ac)
		lst_add_elem_back(&lst, lst_create_elem(av[i])), i++;
	lst->next =
	return (lst);
}

t_circular		*lst_create_elem(char *s)
{
	t_circular		*new;

	if (!(new = (t_circular *)malloc(sizeof(t_circular))))
		return (NULL);
	if (s == NULL)
		new->arg = NULL;
	else
		new->arg = ft_strdup(s);
	new->onArg = 0;
	new->select = 0;
	new->lenArg = ft_strlen(s);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		lst_add_elem_back(t_circular **alst, t_circular *new_elem)
{
	t_circular *curr;

	curr = *alst;
	if (new_elem != NULL)
	{
		if (*alst == NULL)
		{
			*alst = new_elem;
			(*alst)->next = *alst;
			(*alst)->prev = *alst;
		}
		else
		{
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new_elem;
			new_elem->prev = curr;
			new_elem->next = NULL;
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
