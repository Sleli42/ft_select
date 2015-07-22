/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 04:08:55 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/22 23:59:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// t_circular	*root_init(void)
// {
// 	t_circular	*root;

// 	if (!(root = (t_circular *)malloc(sizeof(t_circular))))
// 		return (NULL);
// 	root->arg = NULL;
// 	root->onArg = 0;
// 	root->select = 0;
// 	root->lenArg = 0;
// 	root->prev = root;
// 	root->next = root;
// 	return (root);
// }

t_circular	*create_circular_list(int ac, char **av)
{
	t_circular	*lst;
	int			i;

	lst = NULL;
	i = 1;
	while (i < ac)
		lst_add_elem_back(&lst, lst_create_elem(av[i])), i++;
	return (lst);
}

// void	lst_add_elem_back(t_circular *root, char *s)
// {
// 	t_circular	*new;

// 	if (!(new = (t_circular *)malloc(sizeof(t_circular))))
// 		return ;
// 	new->arg = ft_strdup(s);
// 	new->onArg = 0;
// 	new->select = 0;
// 	new->lenArg = ft_strlen(s);
// 	new->prev = root->prev;
// 	new->next = root;
// 	root->next->prev = new;
// 	root->next = new;
//}

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

size_t		lst_size(t_circular *lst)
{
	t_circular *tmp;
	size_t	i;

	i = 0;
	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			tmp = tmp->next, i++;
			if (tmp == lst)
				break ;
		}
	}
	return (i);
}

void		lst_add_elem_back(t_circular **alst, t_circular *new_elem)
{
	t_circular	*curr;
	int			len;

	curr = *alst;
	if (new_elem != NULL)
	{
		if (*alst == NULL)
			*alst = new_elem;
		else
		{
			len = (int)lst_size(curr);
			curr->prev = new_elem;
			new_elem->next = curr;
			while (len-- > 0)
				curr = curr->next;
			curr->next = new_elem;
			new_elem->prev = curr;
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
