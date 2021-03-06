/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:05:36 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/19 05:40:02 by mtavares         ###   ########.fr       */
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
	else
		gen->img.img[5] = NULL;
}

void	destroy_imgs(t_gen *gen)
{
	int	i;

	i = 2;
	while (++i < 5 + (gen->map.enemy > 0))
	{
		mlx_destroy_image(gen->win.mlx, gen->img.img[i]);
		gen->img.img[i] = NULL;
	}
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
			mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[(gen->map.str[y][x] == '1') * 0 + \
		(gen->map.str[y][x] == '0') + (gen->map.str[y][x] == 'P') * 2 \
		+ (gen->map.str[y][x] == 'C') * 3 + (gen->map.str[y][x] == 'E') * 4 + \
		(gen->map.str[y][x] == 'X') * 5], x * 32, y * 32);
	}
}
