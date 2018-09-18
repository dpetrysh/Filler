/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:30:10 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 13:30:11 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool	is_x(char ch)
{
	if (ch == 'X' || ch == 'x')
		return (1);
	return (0);
}

bool	is_o(char ch)
{
	if (ch == 'O' || ch == 'o')
		return (1);
	return (0);
}

int		get_last_digit(char *str)
{
	int i;

	i = 0;
	while (str[i + 2])
		++i;
	while (ft_isdigit(str[i]))
		--i;
	return (++i);
}

void	finish_game(t_map *map)
{
	map->x = 0;
	map->y = 0;
}

void	print_answer(int j, int i)
{
	char	*ch;

	ch = ft_itoa(j);
	write(1, ch, ft_strlen(ch));
	free(ch);
	write(1, " ", 1);
	ch = ft_itoa(i);
	write(1, ch, ft_strlen(ch));
	free(ch);
	write(1, "\n", 1);
}
