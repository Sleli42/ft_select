/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:53:36 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/11 23:53:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_index(t_clist *lst)
{
	t_select	*tmp;
	int			index;

	tmp = lst->head;
	index = 0;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->index = index;
		index += 1;
		tmp = tmp->next;
	}
}

char	**ft_dupenv(char **env)
{
	char		**dup;
	int			i;

	dup = NULL;
	i = 0;
	if (env && env[i])
	{
		if (!(dup = (char **)malloc(sizeof(char *) * (int)ft_tablen(env) + 1)))
			return (NULL);
		while (env && env[i])
		{
			dup[i] = ft_strdup(env[i]);
			i++;
		}
		dup[i] = NULL;
		return (dup);
	}
	else if (!env || !env[i])
		return (create_simple_env());
	return (NULL);
}

void	parse_cursor_row(t_data *data, char *buff)
{
	char	tmp[2];
	int		ct;
	int		i;

	ct = 0;
	i = 1;
	while (buff[i] && buff[i] != ';')
		tmp[ct++] = buff[i++];
	tmp[ct] = 0;
	data->curr_row = ft_atoi(tmp);
}

char	*get_cursor_row_loop(char *buff)
{
	char	*cpy;
	int		ct;

	cpy = ft_strnew(6);
	ct = 0;
	while (*buff != '\n')
	{
		if ((read(0, buff, 6)) == -1)
			write(1, "Read error\n", 12);
		if (buff[0] == '\033')
		{
			buff++;
			while (buff[ct])
			{
				cpy[ct] = buff[ct];
				ct++;
			}
			cpy[ct] = 0;
			return (cpy);
		}
	}
	return (cpy);
}

void	get_cursor_row(t_data *data)
{
	int		fd;
	char	*buff;
	char	*cpy;

	buff = ft_memset(ft_strnew(6), 0, 6);
	if ((fd = open("/dev/tty", O_RDWR)) == -1)
		write(1, "Open error\n", 12);
	ft_putstr_fd("\033[6n", fd);
	cpy = get_cursor_row_loop(buff);
	parse_cursor_row(data, cpy);
	close(fd);
	ft_strdel(&cpy);
}
