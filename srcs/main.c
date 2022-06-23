/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/23 13:07:50 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_gen	gen;

	gen.init_values = init_values;
	gen.init_values(&gen);
	if (ac != 2)
		exit_prog(&gen, "Wrong number of arguments\n", 1);
	gen.map.check_map(&gen, av);
	gen.win.create_window(&gen);
	gen.hook.hooks(&gen);
}
