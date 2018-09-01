/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:21:20 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/23 17:00:01 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_player(char *str)
{
	char	**exp;
	int		pl;

	exp = ft_strsplit(str, ' ');
	if (exp[2][1] == '1')
		pl = 1;
	else
		pl = 2;
	if (pl == 1)
	{
		g_file.sym = 'O';
		g_file.enem = 'X';
	}
	else
	{
		g_file.sym = 'X';
		g_file.enem = 'O';
	}
	g_file.pl = pl;
	ft_memdel((void **)exp);
}

void	size_of_map(char *str)
{
	char	**explode;

	explode = ft_strsplit(str, ' ');
	g_file.size_map[0] = ft_atoi(explode[1]);
	g_file.size_map[1] = ft_atoi(explode[2]);
	if (g_file.tru == 0)
		g_file.map = (char**)malloc(sizeof(char*) * (g_file.size_map[0] + 1));
	g_file.map[g_file.size_map[0]] = 0;
	ft_memdel((void **)explode);
}

void	check_map(char *str)
{
	char	**exp;

	exp = ft_strsplit(str, ' ');
	g_file.map[g_file.j] = ft_strdup(exp[1]);
	g_file.j++;
	ft_memdel((void **)exp);
}

void	size_of_token(char *str)
{
	char	**exp;

	exp = ft_strsplit(str, ' ');
	g_file.size_tok[0] = ft_atoi(exp[1]);
	g_file.size_tok[1] = ft_atoi(exp[2]);
	if (g_file.tru == 0)
		g_file.token = (char**)malloc(sizeof(char*) * (g_file.size_tok[0] + 1));
	g_file.token[g_file.size_tok[0]] = 0;
	ft_memdel((void **)exp);
}

void	check_token(char *str)
{
	g_file.token[g_file.i] = ft_strdup(str);
	g_file.i++;
}
