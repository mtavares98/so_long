/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:56:52 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/22 15:57:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_values(t_gen *gen)
{
	gen->hook.hooks = hook_loops;
	gen->map.player = 0;
	gen->map.collectable = 0;
	gen->map.exit = 0;
	gen->map.check_map = check_map;
	gen->map.str = NULL;
	gen->map.walls = 0;
	gen->map.empty = 0;
	gen->map.enemy = 0;
	gen->map.other = 0;
	gen->map.player_x = 0;
	gen->map.player_y = 0;
	gen->map.end = 1;
	gen->win.create_window = create_window;
	gen->win.mlx = NULL;
	gen->win.win = NULL;
	gen->img.load_img = map_to_img;
	gen->img.img = NULL;
}
