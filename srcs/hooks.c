/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:40:27 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/28 16:03:07 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	hook(t_gen *gen)
{
	exit_prog(gen, "You've exited the game\n", 0);
	return (0);
}

static int	key_hook(int keycode, t_gen *gen)
{
	if (!gen->map.end)
		exit_prog(gen, "You win\n", 0);
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
	mlx_loop(gen->win.mlx);
}
