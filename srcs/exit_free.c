/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 00:54:35 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/20 22:29:07 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_prog(t_gen *gen, char	*str, int i)
{
	int	j;

	if (i == 0)
		printf_fd(1, "%s", str);
	else
		printf_fd(1, "Error\n%s", str);
	if (gen->win->win)
		mlx_destroy_window(gen->win->mlx, gen->win->win);
	if (gen->map->str)
	{
		j = -1;
		while (gen->map->str[++j])
			free(gen->map->str[j]);
		free(gen->map->str);
	}
	if (gen->hook)
		free(gen->hook);
	if (gen->map)
		free(gen->map);
	if (gen->win)
		free(gen->win);
	exit(i);
}
