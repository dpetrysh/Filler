/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:25:00 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/07/29 16:25:06 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_edges(t_map *map)
{
	make_i_edges(map);
	make_j_edges(map);
	make_m_edges(map);
	make_n_edges(map);
}

void	make_j_edges(t_map *map)
{
	int x;
	int y;

	map->ju = -1;
	map->jd = -1;
	y = -1;
	while (map->ju == -1 && ++y < map->j)
	{
		x = -1;
		while (++x < map->i)
			if (map->tok[y][x] == '*')
				map->ju = y;
	}
	y = map->j;
	while (map->jd == -1 && --y >= 0)
	{
		x = -1;
		while (++x < map->i)
			if (map->tok[y][x] == '*')
				map->jd = y;
	}
}

void	make_i_edges(t_map *map)
{
	int x;
	int y;

	map->il = -1;
	map->ir = -1;
	x = -1;
	while (map->il == -1 && ++x < map->i)
	{
		y = -1;
		while (++y < map->j)
			if (map->tok[y][x] == '*')
				map->il = x;
	}
	x = map->i;
	while (map->ir == -1 && --x >= 0)
	{
		y = -1;
		while (++y < map->j)
			if (map->tok[y][x] == '*')
				map->ir = x;
	}
}

void	make_n_edges(t_map *map)
{
	int x;
	int y;

	map->nu = -1;
	map->nd = -1;
	y = -1;
	while (map->nu == -1 && ++y < map->n)
	{
		x = -1;
		while (++x < map->m)
			if (!map->sign && is_o(map->mat[y][x]))
				map->nu = y;
			else if (map->sign && is_x(map->mat[y][x]))
				map->nu = y;
	}
	y = map->n;
	while (map->nd == -1 && --y >= 0)
	{
		x = -1;
		while (++x < map->m)
			if (!map->sign && is_o(map->mat[y][x]))
				map->nd = y;
			else if (map->sign && is_x(map->mat[y][x]))
				map->nd = y;
	}
}

void	make_m_edges(t_map *map)
{
	int x;
	int y;

	map->ml = -1;
	map->mr = -1;
	x = -1;
	while (map->ml == -1 && ++x < map->m)
	{
		y = -1;
		while (++y < map->n)
			if (!map->sign && is_o(map->mat[y][x]))
				map->ml = x;
			else if (map->sign && is_x(map->mat[y][x]))
				map->ml = x;
	}
	x = map->m;
	while (map->mr == -1 && --x >= 0)
	{
		y = -1;
		while (++y < map->n)
			if (!map->sign && is_o(map->mat[y][x]))
				map->mr = x;
			else if (map->sign && is_x(map->mat[y][x]))
				map->mr = x;
	}
}
