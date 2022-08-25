/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:05:36 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/24 22:24:11 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_imgs(t_gen *gen, int *w, int *h)
{
	char	*str;
	int		i;
	int		num;

	str = ft_strdup("imgs/00.xpm");
	if (!str)
		exit_prog(gen, "Something wrong with ft_strdup\n", 1);
	i = -1;
	num = -1;
	while (++i < 15)
	{
		if (++num > 9)
		{
			num = 0;
			str[5] += 1;
		}
		str[6] = num + 48;
		gen->img.img[i] = mlx_xpm_file_to_image(gen->win.mlx, str, w, h);
		if (!gen->img.img[i])
		{
			free(str);
			exit_prog(gen, "Allocation for the image failed\n", 1);
		}
	}
	free(str);
}

void	map_to_img(t_gen *gen)
{
	int	x;
	int	y;
	int	width;
	int	height;

	width = 32;
	height = 32;
	gen->img.img = ft_calloc(sizeof(void *), (16));
	if (!gen->img.img)
		exit_prog(gen, "Memory allocations failed\n", 1);
	get_imgs(gen, &width, &height);
	y = -1;
	while (gen->map.str[++y])
	{
		x = -1;
		while (gen->map.str[y][++x])
			mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[(gen->map.str[y][x] == '1') * 12 + \
		(gen->map.str[y][x] == '0') * 0 + (gen->map.str[y][x] == 'P') * 2 \
		+ (gen->map.str[y][x] == 'C') * 6 + (gen->map.str[y][x] == 'E') + \
		(gen->map.str[y][x] == 'X') * 13], x * 32, y * 32);
	}
}
