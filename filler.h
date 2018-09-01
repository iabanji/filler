/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:36:43 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/23 17:39:06 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_data
{
	int			coord[2];
	int			best_dest;
	int			j;
	int			pl;
	char		enem;
	char		sym;
	int			tru;
	int			i;
	int			size_map[2];
	int			size_tok[2];
	char		**map;
	char		**token;
}				t_data;

t_data			g_file;

void			ft_readmap(void);
void			analys_str(char *str);
void			check_player(char *str);
void			size_of_map(char *str);
void			check_map(char *str);
void			size_of_token(char *str);
void			check_token(char *str);
void			ft_insert(void);
void			search_coord(int x, int y);

#endif
