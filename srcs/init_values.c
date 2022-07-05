/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:56:52 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/05 00:18:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_values(t_gen *gen)
{
	int	i;

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
	gen->img.img = malloc(sizeof(void *) * (7));
	if (!gen->img.img)
		exit_prog(gen, "Memory allocations failed\n", 1);
	i = -1;
	while (++i < 7)
		gen->img.img[i] = NULL;
}
