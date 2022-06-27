/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:39:43 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/27 21:16:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_imgs(t_gen *gen)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = 16;
	height = 16;
	gen->img.img = malloc(sizeof(void *) * (5));
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
	y = -1;
	while (gen->map.str[++y])
	{
		x = -1;
		while (gen->map.str[y][++x])
		{
			if (gen->map.str[y][x] == 1)
				mlx_put_image_to_window(gen->win.mlx, gen->win.win, gen->img.img[0], x * 16, y * 16);
		}
	}
}
