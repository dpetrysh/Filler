/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:03:50 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/01 18:03:51 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <stdbool.h>
# include "mlx.h"
# include "libft.h"

# define WIN_LEN 1000
# define WIN_HEI 1000
# define BOARDER 200

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

typedef	struct		s_flag
{
	bool			player;
	bool			plateau;
	bool			go_on;
}					t_flag;

typedef	struct		s_inf
{
	bool			sign;
	int				bpp;
	int				sizeline;
	int				endian;
	int				m;
	int				n;
	int				dim;
	int				my_score;
	int				oponents_score;
	unsigned int	*can;
	t_flag			flags;
	t_env			env;
	char			**map;
}					t_inf;

int					get_last_digit(char *str);
void				determine_player(char **line, t_inf *inf);
void				make_info(t_inf *inf);
void				make_map(t_inf *inf, char **line);

int					read_input(t_inf *inf);
void				make_square(int i, int j, t_inf *inf);
void				make_canvas(t_inf *inf);
void				fill_map(t_inf *inf, char **line);
unsigned int		get_color(int i, int j, t_inf *inf);

int					exit_vis(void);
void				free_map(t_inf *inf);
void				print_string(t_inf *inf, int x, int y);
void				show_results(t_inf *inf, char **line);

#endif
