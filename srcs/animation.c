/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:20:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/26 16:50:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_collectable(t_gen *gen, int frame, int x, int y)
{
	if (frame >= 0 && frame < 10)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[6], x * 32, y * 32);
	if (frame >= 10 && frame < 20)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[7], x * 32, y * 32);
	if (frame >= 20 && frame < 30)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[8], x * 32, y * 32);
	if (frame >= 30 && frame < 40)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[9], x * 32, y * 32);
	if (frame >= 40 && frame < 50)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[10], x * 32, y * 32);
	if (frame >= 50 && frame < 60)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[11], x * 32, y * 32);
}

static void	put_enemy(t_gen *gen, int frame, int x, int y)
{
	if (frame >= 0 && frame < 10)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[13], x * 32, y * 32);
	if (frame >= 10 && frame < 20)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[14], x * 32, y * 32);
	if (frame >= 20 && frame < 30)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[13], x * 32, y * 32);
	if (frame >= 30 && frame < 40)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[14], x * 32, y * 32);
	if (frame >= 40 && frame < 50)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[13], x * 32, y * 32);
	if (frame >= 50 && frame < 60)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[14], x * 32, y * 32);
}

static void	put_others(t_gen *gen, int x, int y, int other)
{
	mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
	gen->img.img[other], x * 32, y * 32);
}

void	print_map(t_gen *gen, int frame)
{
	int	i;
	int	j;

	i = -1;
	while (++i < gen->map.len_y)
	{
		j = -1;
		while (++j < gen->map.len_x)
		{
			if (gen->map.str[i][j] == 'C')
				put_collectable(gen, frame, j, i);
			else if (gen->map.str[i][j] == 'X')
				put_enemy(gen, frame, j, i);
			else if (gen->map.str[i][j] == '0')
				put_others(gen, j, i, EMPTY);
			else if (gen->map.str[i][j] == '1')
				put_others(gen, j, i, WALL);
			else if (gen->map.str[i][j] == 'E')
				put_others(gen, j, i, EXIT);
		}
	}
}
