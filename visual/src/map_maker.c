/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:13:20 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 14:13:21 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int				read_input(t_inf *inf)
{
	char	*line;

	if (!inf->flags.go_on)
	{
		get_next_line(0, &line);
		if (!inf->flags.player && ft_strstr(line, "dpetrysh.filler"))
			determine_player(&line, inf);
		else if (!inf->flags.plateau && ft_strstr(line, "Plat"))
			make_map(inf, &line);
		else if (ft_strstr(line, "01234"))
		{
			fill_map(inf, &line);
			make_canvas(inf);
			mlx_clear_window(inf->env.mlx, inf->env.win);
			mlx_put_image_to_window(inf->env.mlx, inf->env.win, inf->env.img,
				BOARDER / 2, BOARDER / 2);
			free_map(inf);
		}
		else if (ft_strstr(line, "=="))
			show_results(inf, &line);
		else
			free(line);
	}
	return (0);
}

void			make_square(int i, int j, t_inf *inf)
{
	int num;
	int is;
	int js;

	is = 0;
	while (++is < inf->dim)
	{
		js = 0;
		while (++js < inf->dim)
		{
			num = j * (WIN_LEN - BOARDER) * inf->dim + is *
				(WIN_LEN - BOARDER) + i * inf->dim + js;
			inf->can[num] = get_color(i, j, inf);
		}
	}
}

void			make_canvas(t_inf *inf)
{
	int i;
	int j;

	j = -1;
	inf->env.img = mlx_new_image(inf->env.mlx, WIN_LEN - BOARDER,
		WIN_HEI - BOARDER);
	inf->can = (unsigned int *)mlx_get_data_addr(inf->env.img, &inf->bpp,
		&inf->sizeline, &inf->endian);
	while (++j < inf->n)
	{
		i = -1;
		while (++i < inf->m)
			make_square(i, j, inf);
	}
}

void			fill_map(t_inf *inf, char **line)
{
	int i;

	free(*line);
	i = -1;
	while (++i < inf->n)
	{
		get_next_line(0, line);
		inf->map[i] = ft_strdup(*line + 4);
		free(*line);
	}
}

unsigned int	get_color(int i, int j, t_inf *inf)
{
	if (inf->map[j][i] == '.')
		return (0x222222);
	if (!inf->sign && (inf->map[j][i] == 'O' || inf->map[j][i] == 'o'))
		return (0xFF0000);
	if (!inf->sign && (inf->map[j][i] == 'X' || inf->map[j][i] == 'x'))
		return (0x0000FF);
	if (inf->sign && (inf->map[j][i] == 'O' || inf->map[j][i] == 'o'))
		return (0x0000FF);
	if (inf->sign && (inf->map[j][i] == 'X' || inf->map[j][i] == 'x'))
		return (0xFF0000);
	return (0xFF00FF);
}
