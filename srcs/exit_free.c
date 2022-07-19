/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:54:35 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/19 04:29:39 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_mlx(t_gen *gen, int i)
{
	int	j;

	if (gen->img.img)
	{
		j = -1;
		while (gen->img.img[++j])
			mlx_destroy_image(gen->win.mlx, gen->img.img[j]);
		free(gen->img.img);
	}
	if (gen->win.win)
		mlx_destroy_window(gen->win.mlx, gen->win.win);
	if (gen->win.mlx)
		free(gen->win.mlx);
	exit(i);
}

void	exit_prog(t_gen *gen, char	*str, int i)
{
	int	j;

	if (i == 0)
		printf_fd(1, "%s", str);
	else
		printf_fd(1, "Error\n%s", str);
	if (gen->map.str)
	{
		j = -1;
		while (gen->map.str[++j])
			free(gen->map.str[j]);
		free(gen->map.str);
	}
	free_mlx(gen, i);
}
