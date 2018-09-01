/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:16:39 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/23 16:57:51 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		insert_fig(int x, int y)
{
	int		touch;
	int		i;
	int		j;

	touch = 0;
	i = -1;
	while (++i < g_file.size_tok[0])
	{
		j = -1;
		while (++j < g_file.size_tok[1])
		{
			if ((y + j) >= g_file.size_map[1] || (x + i) >= g_file.size_map[0])
				return (0);
			if (g_file.token[i][j] == '*')
			{
				if (g_file.map[x + i][y + j] == g_file.enem)
					return (0);
				if (g_file.map[x + i][y + j] == g_file.sym)
					touch++;
			}
			if (touch > 1)
				return (0);
		}
	}
	return ((touch == 1) ? (1) : (0));
}

void	put_coord(int x, int y)
{
	g_file.i = 0;
	if (g_file.tru == 0)
		g_file.tru = 1;
	g_file.j = 0;
	ft_putnbr(x);
	write(1, " ", 1);
	ft_putnbr(y);
	write(1, "\n", 1);
}

void	ft_insert(void)
{
	int		i;
	int		j;

	g_file.coord[0] = 0;
	g_file.coord[1] = 0;
	g_file.best_dest = -1;
	i = -1;
	while (++i < g_file.size_map[0])
	{
		j = -1;
		while (++j < g_file.size_map[1])
		{
			if (insert_fig(i, j) == 1)
				search_coord(i, j);
		}
	}
	put_coord(g_file.coord[0], g_file.coord[1]);
}
