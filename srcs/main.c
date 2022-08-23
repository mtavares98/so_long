/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:09:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/23 18:35:56 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	static t_gen	gen;

	if (ac != 2)
		exit_prog(&gen, "Wrong number of arguments\n", 1);
	check_map(&gen, av);
	create_window(&gen);
	map_to_img(&gen);
	hook_loops(&gen);
}
