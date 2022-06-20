/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:56:52 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/20 22:32:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_values(t_gen *gen)
{
	gen->hook = malloc(sizeof(t_hook));
	if (!gen->hook)
		exit_prog(gen, "Allocation failed for hook\n", 1);
	gen->hook->moviments = hook_loops;
	gen->map = malloc(sizeof(t_map));
	if (!gen->map)
		exit_prog(gen, "Allocation failed for map\n", 1);
	gen->map->character = 0;
	gen->map->collectable = 0;
	gen->map->exit = 0;
	gen->map->t_check_map = check_map;
	gen->map->str = NULL;
	gen->map->walls = 0;
	gen->win = malloc(sizeof(t_win));
	if (!gen->win)
		exit_prog(gen, "Allocation failed for win\n", 1);
	gen->win->create_win = create_window;
	gen->win->mlx = NULL;
	gen->win->win = NULL;
}
