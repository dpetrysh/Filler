/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:29:10 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 13:29:12 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_cells(char **a, t_map *map)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
			if (a[i][j] == '*')
				++count;
	}
	map->amount = count;
	return (count);
}

t_cell	*cell_coordinates(char **a, int amount)
{
	int		k;
	int		i;
	int		j;
	t_cell	*cells;

	cells = (t_cell *)malloc(sizeof(t_cell) * amount);
	k = -1;
	i = -1;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
			if (a[i][j] == '*')
			{
				cells[++k].x = j;
				cells[k].y = i;
			}
	}
	return (cells);
}

void	make_mat(t_map *map, char **line)
{
	int i;

	i = -1;
	free(*line);
	while (get_next_line(0, line) && !ft_strstr(*line, "Piece"))
	{
		map->mat[++i] = ft_strdup(*line + 4);
		free(*line);
	}
	map->mat[map->n] = NULL;
}

void	make_tok(t_map *map, char **line)
{
	int i;

	i = -1;
	free(*line);
	map->tok = (char **)malloc(sizeof(char *) * (map->j + 1));
	while (++i < map->j && get_next_line(0, line))
	{
		map->tok[i] = ft_strdup(*line);
		free(*line);
	}
	map->tok[i] = NULL;
}

int		main(void)
{
	t_map	map;
	t_cell	*cells;
	char	*line;

	make_player(&line, &map);
	map.n = ft_atoi(line + 8);
	map.m = ft_atoi(line + get_last_digit(line));
	free(line);
	map.mat = (char **)malloc(sizeof(char *) * (map.n + 1));
	while (get_next_line(0, &line) > 0 && !ft_strstr(line, "=="))
	{
		make_mat(&map, &line);
		map.j = ft_atoi(line + 6);
		map.i = ft_atoi(line + get_last_digit(line));
		make_tok(&map, &line);
		cells = cell_coordinates(map.tok, count_cells(map.tok, &map));
		put_figure(&map, cells);
		print_answer(map.y, map.x);
		skip_plateau(&line);
		free_traces(&map, &cells);
	}
	free(map.mat);
	return (0);
}
