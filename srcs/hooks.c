/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:40:27 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/26 18:52:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	animate(t_gen *gen)
{
	static int	frame;
	static int	index_x = 13;
	static int	index_c = 6;

	frame++;
	if (frame == 10000)
	{
		print_map(gen, index_x, index_c);
		index_x++;
		index_c++;
		frame = 0;
		if (index_x == 15)
			index_x = 13;
		if (index_c == 12)
			index_c = 6;
	}
	return (0);
}

static int	hook(t_gen *gen)
{
	exit_prog(gen, "You've exited the game\n", 0);
	return (0);
}

static int	key_hook(int keycode, t_gen *gen)
{
	if (keycode == ESC)
		exit_prog(gen, "Exited the game\n", 0);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		check_mov(gen, keycode);
	return (0);
}

void	hook_loops(t_gen *gen)
{
	mlx_hook(gen->win.win, 2, 1L << 0, key_hook, gen);
	mlx_hook(gen->win.win, 17, 1L << 2, hook, gen);
	mlx_loop_hook(gen->win.mlx, animate, gen);
	mlx_loop(gen->win.mlx);
}
