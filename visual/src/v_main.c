/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:53:07 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/07/30 20:53:08 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int	key_hook(int key, t_inf *inf)
{
	if (key == 53)
	{
		inf->dim = 0;
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_inf	inf;

	make_info(&inf);
	inf.env.mlx = mlx_init();
	inf.env.win = mlx_new_window(inf.env.mlx, WIN_LEN, WIN_HEI, "mlx42");
	mlx_loop_hook(inf.env.mlx, read_input, &inf);
	mlx_hook(inf.env.win, 2, 5, key_hook, &inf);
	mlx_hook(inf.env.win, 17, 1L << 17, exit_vis, &inf);
	mlx_loop(inf.env.mlx);
	return (0);
}
