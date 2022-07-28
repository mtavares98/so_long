/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:11 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/28 16:02:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_steps(t_gen *gen, int steps)
{
	char	*str;
	int		i;
	int		x;

	i = -1;
	x = ft_strlen(gen->map.str[0]);
	str = ft_itoa(steps);
	while (++i <= x)
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[0], i * 32, 0);
	mlx_string_put(gen->win.mlx, gen->win.win, 32, 32, 0x00000000, str);
	free(str);
}

static void	update_map(t_gen *gen, int keycode)
{
	mlx_put_image_to_window(gen->win.mlx, gen->win.win, gen->img.img[2], \
	(gen->map.player_x - (keycode == A) + (keycode == D)) * 32, \
	(gen->map.player_y - (keycode == W) + (keycode == S)) * 32);
	mlx_put_image_to_window(gen->win.mlx, gen->win.win, gen->img.img[1], \
	(gen->map.player_x) * 32, (gen->map.player_y) * 32);
}

static void	moveplayer(t_gen *gen, int keycode, char *next_move, int steps)
{
	if (*next_move == 'X')
		exit_prog(gen, "You lost\n", 0);
	if (!gen->map.collectable && *next_move == 'E')
	{
		printf_fd(1, "Press any key to left the game\n");
		gen->map.end = 0;
		return ;
	}
	*next_move = 'P';
	gen->map.str[gen->map.player_y][gen->map.player_x] = '0';
	update_map(gen, keycode);
	gen->map.player_x += -(keycode == A) + (keycode == D);
	gen->map.player_y += -(keycode == W) + (keycode == S);
	print_steps(gen, steps);
}

void	check_mov(t_gen *gen, int keycode)
{
	static int	steps = 0;
	char		*next_move;

	next_move = &gen->map.str[gen->map.player_y - (keycode == W) + \
	(keycode == S)][gen->map.player_x - (keycode == A) + (keycode == D)];
	if (*next_move == 'C')
		gen->map.collectable--;
	if (*next_move != '1' && (*next_move != 'E' || !gen->map.collectable))
		moveplayer(gen, keycode, next_move, ++steps);
	return ;
}
