/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:52:23 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/23 17:16:19 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		*next_coord(int x, int y)
{
	int		i;
	int		j;
	int		*coord;

	coord = (int*)malloc(sizeof(int) * 2);
	coord[0] = -1;
	coord[1] = -1;
	i = x - 1;
	while (++i < g_file.size_map[0])
	{
		j = -1;
		if (i == x)
			j = y;
		while (++j < g_file.size_map[1])
		{
			if (g_file.map[i][j] == g_file.enem)
			{
				coord[0] = i;
				coord[1] = j;
				return (coord);
			}
		}
	}
	return (coord);
}

void	sum_dest(int x, int y, int *coord, int *begin_coord)
{
	int		v1;
	int		v2;
	int		sum;

	v1 = x - coord[0];
	v2 = y - coord[1];
	if (v1 < 0)
		v1 = -v1;
	if (v2 < 0)
		v2 = -v2;
	sum = v1 + v2;
	if (g_file.best_dest == -1)
	{
		g_file.best_dest = sum;
		g_file.coord[0] = begin_coord[0];
		g_file.coord[1] = begin_coord[1];
	}
	else if (g_file.best_dest > sum)
	{
		g_file.best_dest = sum;
		g_file.coord[0] = begin_coord[0];
		g_file.coord[1] = begin_coord[1];
	}
}

void	consider_dest(int x, int y, int a1, int a2)
{
	int		*coord_enem;
	int		*begin_coord;

	begin_coord = (int*)malloc(sizeof(int) * 2);
	begin_coord[0] = a1;
	begin_coord[1] = a2;
	coord_enem = next_coord(0, 0);
	sum_dest(x, y, coord_enem, begin_coord);
	coord_enem = next_coord(coord_enem[0], coord_enem[1]);
	while (coord_enem[0] != -1)
	{
		sum_dest(x, y, coord_enem, begin_coord);
		coord_enem = next_coord(coord_enem[0], coord_enem[1]);
	}
}

void	search_coord(int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_file.size_tok[0])
	{
		j = -1;
		while (++j < g_file.size_tok[1])
		{
			if (g_file.token[i][j] == '*')
				consider_dest(x + i, y + j, x, y);
		}
	}
}
