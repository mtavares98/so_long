/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:20:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/26 18:20:02 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_gen *gen, int index_x, int index_c)
{
	int	i;
	int	j;

	i = 0;
	while (++i < gen->map.len_y)
	{
		j = -1;
		while (++j < gen->map.len_x)
		{
			if (gen->map.str[i][j] == 'C')
				mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[index_c], j * 32, i * 32);
			else if (gen->map.str[i][j] == 'X')
				mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
				gen->img.img[index_x], j * 32, i * 32);
		}
	}
}
