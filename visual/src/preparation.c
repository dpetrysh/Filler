/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:18:59 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/03 14:19:00 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

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

void	determine_player(char **line, t_inf *inf)
{
	if (ft_strstr(*line, "p1"))
	{
		inf->flags.player = 1;
		inf->sign = 0;
	}
	if (ft_strstr(*line, "p2"))
	{
		inf->flags.player = 1;
		inf->sign = 1;
	}
	free(*line);
}

void	make_info(t_inf *inf)
{
	inf->sign = 0;
	inf->m = 0;
	inf->n = 0;
	inf->bpp = 4;
	inf->sizeline = 0;
	inf->endian = 0;
	inf->flags.player = 0;
	inf->flags.plateau = 0;
	inf->flags.go_on = 0;
}

void	make_map(t_inf *inf, char **line)
{
	int l;
	int h;

	inf->n = ft_atoi(*line + 8);
	inf->m = ft_atoi(*line + get_last_digit(*line));
	free(*line);
	l = (WIN_LEN - BOARDER) / inf->m;
	h = (WIN_HEI - BOARDER) / inf->n;
	inf->dim = l > h ? h : l;
	inf->map = (char **)malloc(sizeof(char *) * inf->n);
	inf->flags.plateau = 1;
}
