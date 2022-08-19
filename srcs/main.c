/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/18 17:51:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_player_pos(t_gen *gen)
{
	int	i;
	int	j;

	i = -1;
	while (gen->map.str[++i])
	{
		j = -1;
		while (gen->map.str[i][++j])
		{
			if (gen->map.str[i][j] == 'P')
			{
				gen->map.player_x = j;
				gen->map.player_y = i;
				return ;
			}
		}
	}
	return ;
}

int	main(int ac, char **av)
{
	t_gen	gen;

	gen.init_values = init_values;
	gen.init_values(&gen);
	if (ac != 2)
		exit_prog(&gen, "Wrong number of arguments\n", 1);
	gen.map.check_map(&gen, av);
	get_player_pos(&gen);
	if (prep_alg(&gen))
		exit_prog(&gen, "Can't complete the map\n", 1);
	gen.win.create_window(&gen);
	gen.img.load_img(&gen);
	gen.hook.hooks(&gen);
}
