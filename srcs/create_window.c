/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:10:48 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/20 19:53:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_window(t_win *win)
{
	int	x;
	int	y;

	x = 140;
	y = 150;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, x, y, "MyGame");
}
