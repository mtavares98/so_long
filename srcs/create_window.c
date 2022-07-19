/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:10:48 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/19 05:50:47 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_window(t_gen	*gen)
{
	int	x;
	int	y;

	y = -1;
	while (gen->map.str[++y])
		;
	y *= 32;
	x = ft_strlen(gen->map.str[1]) * 32;
	if (gen->win.mlx)
		free(gen->win.mlx);
	gen->win.mlx = mlx_init();
	if (!gen->win.mlx)
		exit_prog(gen, "Error ocurred during mlx_init\n", 1);
	if (gen->win.win)
		mlx_destroy_window(gen->win.mlx, gen->win.win);
	gen->win.win = mlx_new_window(gen->win.mlx, x, y, "MyGame");
	if (!gen->win.win)
		exit_prog(gen, "Error ocurred during mlx_new window\n", 1);
}
