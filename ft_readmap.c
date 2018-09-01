/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:41:30 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/23 17:15:34 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	analys_str(char *str)
{
	if (str[0] == '$')
		check_player(str);
	else if (str[0] == ' ' || str[0] == '\t')
		return ;
	else if (str[0] == 'P' && str[1] == 'l' && g_file.tru == 0)
		size_of_map(str);
	else if (str[0] == '0' && str[1] >= '0' && str[1] <= '9' && str[3] == ' ')
		check_map(str);
	else if (str[0] == 'P' && str[1] == 'i')
		size_of_token(str);
	else if (str[0] == '.' || str[0] == '*')
	{
		check_token(str);
		if (g_file.i == g_file.size_tok[0])
		{
			ft_insert();
		}
	}
	return ;
}

void	ft_readmap(void)
{
	char	*tmp;
	char	*str;
	int		num;

	g_file.j = 0;
	g_file.i = 0;
	g_file.tru = 0;
	num = 1;
	tmp = ft_strnew(1);
	while (read(0, tmp, 1))
	{
		if (tmp[0] == '\n')
		{
			analys_str(str);
			free(str);
			num = 1;
		}
		else
		{
			if (num == 1)
				str = ft_strnew(0);
			num = 0;
			str = ft_strjoin(str, tmp);
		}
	}
}
