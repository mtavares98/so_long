/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:40:27 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/26 16:41:19 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	animate(t_gen *gen)
{
	static int	frame;
	char		*str;
	int			i;

	print_map(gen, frame);
	frame++;
	str = ft_itoa(gen->steps);
	if (!str)
		exit_prog(gen, "Allocation failed in itoa\n", 1);
	i = -1;
	while (++i < gen->map.len_x)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[12], i * 32, 0);
	mlx_string_put(gen->win.mlx, gen->win.win, 32, 32, 0x00000000, str);
	free(str);
	if (frame == 60)
		frame = 0;
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
