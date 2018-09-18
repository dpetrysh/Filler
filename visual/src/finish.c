/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:16:08 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 14:16:09 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		exit_vis(void)
{
	exit(1);
}

void	free_map(t_inf *inf)
{
	int i;

	i = -1;
	while (++i < inf->n)
		free(inf->map[i]);
}

void	print_string(t_inf *inf, int x, int y)
{
	char *ch;

	mlx_string_put(inf->env.mlx, inf->env.win, x, y, 0xFFFFFF,
		"dpetrysh.filler vs bot:");
	mlx_string_put(inf->env.mlx, inf->env.win, x + 65, y + 20, 0xFFFFFF,
		ch = ft_itoa(inf->my_score));
	free(ch);
	mlx_string_put(inf->env.mlx, inf->env.win, x + 195, y + 20, 0xFFFFFF,
		ch = ft_itoa(inf->oponents_score));
	free(ch);
}

void	show_results(t_inf *inf, char **line)
{
	int y;
	int x;

	if (!inf->sign)
		inf->my_score = ft_atoi(*line + 10);
	else
		inf->oponents_score = ft_atoi(*line + 10);
	free(*line);
	get_next_line(0, line);
	if (inf->sign)
		inf->my_score = ft_atoi(*line + 10);
	else
		inf->oponents_score = ft_atoi(*line + 10);
	free(*line);
	inf->flags.go_on = 1;
	y = (3 * WIN_HEI + inf->n * inf->dim) / 4;
	x = (WIN_LEN - BOARDER) / 2;
	print_string(inf, x, y);
}
