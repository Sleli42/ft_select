/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/28 04:18:59 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char		*key_hook(void)
{
	char	buff[3] = {0};

	read(1, buff, 3);
	if (K_UP)
		return ("K_UP");
	if (K_DOWN)
		return ("K_DOWN");
	return (NULL);
}

void	main_loop(t_all *all)
{
	char	*key;

	tputs_termcap("cl");
	tputs_termcap("vi");
	tputs_termcap("ho");
	// while (1091111096051)
	// {
	display_list(&all->lst);
	while (1091111096051)
	{
		key = key_hook();
		if (key != NULL)
		{
			move_cursor_updown(key, &all->lst);
			tputs_termcap("cl");
			display_list(&all->lst);
			/* move
			 cursor */
		}
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
	reset_term(all->default_term);
	return (0);
}

void	reset_term(t_termios *default_term)
{
	if (tcgetattr(0, default_term) == -1)
   		return ;
	default_term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, default_term) == -1)
   		return ;
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
