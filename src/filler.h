/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:11:25 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/07/24 20:11:26 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdbool.h>
# include "libft.h"
# include <unistd.h>

typedef struct	s_cell
{
	int			x;
	int			y;
}				t_cell;

typedef	struct	s_map
{
	int			amount;
	int			sign;
	int			x;
	int			y;
	int			m;
	int			n;
	int			i;
	int			j;
	int			il;
	int			ir;
	int			ju;
	int			jd;
	int			nu;
	int			nd;
	int			ml;
	int			mr;
	int			ym;
	char		**mat;
	char		**tok;
}				t_map;

bool			is_x(char ch);
bool			is_o(char ch);
int				get_last_digit(char *str);
void			finish_game(t_map *map);
void			print_answer(int j, int i);

void			get_edges(t_map *map);
void			make_j_edges(t_map *map);
void			make_i_edges(t_map *map);
void			make_n_edges(t_map *map);
void			make_m_edges(t_map *map);

void			skip_plateau(char **line);
void			determine_player(char *line, char *player, t_map *map);
void			make_player(char **line, t_map *map);
void			free_traces(t_map *map, t_cell **cells);

int				get_cell_distanse(int x, int y, t_map map);
int				putcheck(int xb, int yb, t_map map, t_cell *cells);
int				token_dist(int xb, int yb, t_map map, t_cell *cells);
void			get_xy_edges(t_cell *cmin, t_cell *cmax, t_map *map);
void			put_figure(t_map *map, t_cell *cells);

#endif
