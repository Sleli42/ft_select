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

int			check_keys_arrows(char *buff)
{
	int		current_key;

	current_key = getkey(buff);
	if (current_key == K_ENTER)
		return (-1);
	if (current_key == K_RIGHT || current_key == K_LEFT
		|| current_key == K_UP || current_key == K_DOWN)
		return (1);
	return (0);
}

int			read_keys(void)
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
	if ((key = check_keys_arrows(buff)) < 0)
		return (0);
	else if (key > 0)
		return 1;
	ft_strdel(&buff);
	return (42);
}
