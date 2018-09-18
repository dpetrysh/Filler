/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:33:38 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 13:33:39 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_plateau(char **line)
{
	get_next_line(0, line);
	if (ft_strstr(*line, "Plateau"))
		free(*line);
}

void	determine_player(char *line, char *player, t_map *map)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, player))
		map->sign = 0;
	if (ft_strstr(line, "p2") && ft_strstr(line, player))
		map->sign = 1;
}

void	make_player(char **line, t_map *map)
{
	while (get_next_line(0, line) && !ft_strstr(*line, "Plateau"))
	{
		determine_player(*line, "dpetrysh.filler", map);
		free(*line);
	}
}

void	free_traces(t_map *map, t_cell **cells)
{
	int i;

	i = -1;
	while (map->mat[++i])
		free(map->mat[i]);
	i = -1;
	while (map->tok[++i])
		free(map->tok[i]);
	free(*cells);
	free(map->tok);
}
