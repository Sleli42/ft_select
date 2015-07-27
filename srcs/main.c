/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/28 01:17:47 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	key_hook(void)
{
	char	buff[3] = {0};

	if (K_UP)
	{
		printf("k_UP ok\n");
		return (1);
	}
	if (*buff == 4)
		return (-1);
	return (0);
}

void	main_loop(t_all *all)
{
	tputs_termcap("cl");
	tputs_termcap("ho");
	while (1091111096051)
	{
		tputs_termcap("vi");
		display_screen(all->lst);
		/* condition d'arret */
	}
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		all = init_all(ac, av);
		main_loop(all);
	//	display_screen(all);
		// print_list(all->lst);
	//	del_circular_list(all->lst);
	}
	return (0);
}

/* memo key

up = buff[0] = 27, buff[1] = 91, buff[2] = 65;
down = buff[0] = 27, buff[1] = 91, buff[2] = 66;
right = buff[0] = 27, buff[1] = 91, buff[2] = 67;
left = buff[0] = 27, buff[1] = 91, buff[2] = 68;

*/



void	key_hook_hook(void)
{
	 char     buffer[3];

  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
    {
      printf("C'est une fleche !\n");
      printf("'%c' - '%c' - '%c'\n", buffer[0], buffer[1], buffer[2]);
      return ;
    }
    else if (buffer[0] == 4)
    {
      printf("Ctlr+d, on quitte !\n");
      return ;
    }
  }
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
