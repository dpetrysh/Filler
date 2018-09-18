/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:36:53 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 13:36:54 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_cell_distanse(int x, int y, t_map map)
{
	int i;
	int j;
	int d;
	int dist;

	dist = 1000;
	i = -1;
	while (map.mat[++i])
	{
		j = -1;
		while (map.mat[i][++j])
		{
			d = ABS(y - i) + ABS(x - j);
			if (!map.sign && (map.mat[i][j] == 'x' ||
				map.mat[i][j] == 'X') && dist > d)
				dist = d;
			else if (map.sign && (map.mat[i][j] == 'o' ||
				map.mat[i][j] == 'O') && dist > d)
				dist = d;
		}
	}
	return (dist);
}

int		putcheck(int xb, int yb, t_map map, t_cell *cells)
{
	int		l;
	int		count;
	char	ch;

	count = 0;
	l = -1;
	while (++l < map.amount)
	{
		ch = map.mat[yb + cells[l].y][xb + cells[l].x];
		if (!map.sign && is_o(ch))
			++count;
		else if (!map.sign && is_x(ch))
			return (0);
		else if (map.sign && is_x(ch))
			++count;
		else if (map.sign && is_o(ch))
			return (0);
	}
	if (count == 1)
		return (1);
	return (0);
}

int		token_dist(int xb, int yb, t_map map, t_cell *cells)
{
	int k;
	int dist;

	k = -1;
	dist = 0;
	while (++k < map.amount)
	{
		dist += get_cell_distanse(xb + cells[k].x, yb + cells[k].y, map);
	}
	return (dist);
}

void	get_xy_edges(t_cell *cmin, t_cell *cmax, t_map *map)
{
	get_edges(map);
	if (-map->il > map->ml - map->ir)
		cmin->x = -map->il;
	else
		cmin->x = map->ml - map->ir;
	if (map->m - map->ir > map->mr - map->il)
		cmax->x = map->mr - map->il + 1;
	else
		cmax->x = map->m - map->ir;
	if (-map->ju > map->nu - map->jd)
		cmin->y = -map->ju - 1;
	else
		cmin->y = map->nu - map->jd - 1;
	if (map->n - map->jd > map->nd - map->ju)
		cmax->y = map->nd - map->ju + 1;
	else
		cmax->y = map->n - map->jd;
	map->ym = cmin->y;
}

void	put_figure(t_map *map, t_cell *cells)
{
	t_cell	cmin;
	t_cell	cmax;
	int		x;
	int		d;
	int		dist;

	get_xy_edges(&cmin, &cmax, map);
	dist = 100000;
	while (++cmin.y < cmax.y)
	{
		x = cmin.x - 1;
		while (++x < cmax.x)
			if (putcheck(x, cmin.y, *map, cells))
				if ((d = token_dist(x, cmin.y, *map, cells)) < dist)
				{
					map->x = x;
					map->y = cmin.y;
					dist = d;
				}
	}
	if (map->x < cmin.x || map->x >= cmax.x || map->y >= cmax.y ||
		map->y <= map->ym)
		finish_game(map);
}
