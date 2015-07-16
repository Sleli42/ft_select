/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/16 05:06:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		all = init_all(ac, av);
		print_list(all->lst);
		del_circular_list(all->lst);
	}
	return (0);
}

void	print_list(t_circular *lst)
{
	t_circular *tmp;

	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			printf("%s\n", tmp->arg);
			tmp = tmp->next;
		}
	}
}

// int		ft_outc(int c)
// {
// 	ft_putchar(c);
// 	return(c);
// }

// int		main(int ac, char **av, char **env)
// {
// 	struct termios	term;
// 	char			*buff;
// 	char			*term_name;
// 	char			*res;
// 	// int				fd;

// 	(void)ac;
// 	(void)av;
// 	(void)env;
// 	// fd = init_tty();
// 	buff = (char *)malloc(sizeof(char *));
// 	if ((term_name = getenv("TERM")) == NULL)
// 		return (-1);
// 	printf("My term: %s\n", term_name);
// 	if (tgetent(buff, term_name) == -1)
// 	{
// 		printf("terminfo database could not be found\n");
// 		return (0);
// 	}
// 	if (tcgetattr(0, &term) == -1)
// 		return (-1);
// 	if ((res = tgetstr("cl", NULL)) == NULL)
// 		return (-1);
// 	tputs(res, 0, ft_outc);
// 	// if (tcgetattr(fd, &term) == -1)
// 	// 	printf("error tcgetattr\n");
// 	// else
// 	// {
// 	// 	if (term.c_lflag & ICANON)
// 	// 		printf("term is on canonical mode\n");
// 	// }
// 	return (0);
// }
