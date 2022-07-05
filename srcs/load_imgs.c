/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:05:36 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/05 15:23:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_imgs(t_gen *gen)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	gen->img.img[0] = mlx_xpm_file_to_image(gen->win.mlx, "img/00.xpm", \
	&width, &height);
	gen->img.img[1] = mlx_xpm_file_to_image(gen->win.mlx, "img/01.xpm", \
	&width, &height);
	gen->img.img[2] = mlx_xpm_file_to_image(gen->win.mlx, "img/02.xpm", \
	&width, &height);
	gen->img.img[3] = mlx_xpm_file_to_image(gen->win.mlx, "img/03.xpm", \
	&width, &height);
	gen->img.img[4] = mlx_xpm_file_to_image(gen->win.mlx, "img/04.xpm", \
	&width, &height);
	if (gen->map.enemy)
		gen->img.img[5] = mlx_xpm_file_to_image(gen->win.mlx, "img/05.xpm", \
	&width, &height);
}

static void	load_img(t_gen *gen, int x, int y)
{
	if (gen->map.str[y][x] == '1')
		mlx_put_image_to_window(gen->win.mlx, \
		gen->win.win, gen->img.img[2], x * 32, y * 32);
	else if (gen->map.str[y][x] == '0')
		mlx_put_image_to_window(gen->win.mlx, \
		gen->win.win, gen->img.img[3], x * 32, y * 32);
	if (gen->map.str[y][x] == 'C')
		mlx_put_image_to_window(gen->win.mlx, \
		gen->win.win, gen->img.img[4], x * 32, y * 32);
	else if (gen->map.str[y][x] == 'P')
		mlx_put_image_to_window(gen->win.mlx, \
		gen->win.win, gen->img.img[1], x * 32, y * 32);
	else if (gen->map.str[y][x] == 'E')
		mlx_put_image_to_window(gen->win.mlx, \
		gen->win.win, gen->img.img[0], x * 32, y * 32);
	else if (gen->map.str[y][x] == 'X')
		mlx_put_image_to_window(gen->win.mlx, \
		gen->win.win, gen->img.img[5], x * 32, y * 32);
}

void	map_to_img(t_gen *gen)
{
	int	x;
	int	y;

	get_imgs(gen);
	y = -1;
	while (gen->map.str[++y])
	{
		x = -1;
		while (gen->map.str[y][++x])
			load_img(gen, x, y);
	}
}
