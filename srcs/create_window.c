/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:10:48 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/22 15:19:18 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_window(t_gen	*gen)
{
	int	x;
	int	y;

	x = 140;
	y = 150;
	gen->win.mlx = mlx_init();
	gen->win.win = mlx_new_window(gen->win.mlx, x, y, "MyGame");
}
