/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:11 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/24 22:18:04 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_steps(t_gen *gen, int steps)
{
	char	*str;
	int		i;
	int		x;
	char	c;

	i = -1;
	x = ft_strlen(gen->map.str[0]);
	str = ft_itoa(steps);
	while (++i <= x)
	{
		c = gen->map.str[0][i];
		mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
		gen->img.img[(c == '1') * 12 + (c == 'X') * 13], i * 32, 0);
	}
	mlx_string_put(gen->win.mlx, gen->win.win, 32, 32, 0x00000000, str);
	free(str);
}

static void	update_map(t_gen *gen, int keycode)
{
	mlx_put_image_to_window(gen->win.mlx, gen->win.win, \
	gen->img.img[(keycode == W) * DOWN + (keycode == S) * UP + \
	(keycode == A) * LEFT + (keycode == D) * RIGHT], \
	(gen->map.player_x - (keycode == A) + (keycode == D)) * 32, \
	(gen->map.player_y - (keycode == W) + (keycode == S)) * 32);
	mlx_put_image_to_window(gen->win.mlx, gen->win.win, gen->img.img[0], \
	(gen->map.player_x) * 32, (gen->map.player_y) * 32);
}

static void	moveplayer(t_gen *gen, int keycode, char *next_move, int steps)
{
	if (*next_move == 'X')
		exit_prog(gen, "You lost\n", 0);
	if (!gen->map.collectable && *next_move == 'E')
		exit_prog(gen, "You win\n", 0);
	*next_move = 'P';
	gen->map.str[gen->map.player_y][gen->map.player_x] = '0';
	update_map(gen, keycode);
	gen->map.player_x += -(keycode == A) + (keycode == D);
	gen->map.player_y += -(keycode == W) + (keycode == S);
	print_steps(gen, steps);
}

static int	check_faced(t_gen *gen, int keycode)
{
	static int	turn = DOWN;
	int			faced;

	faced = (keycode == W) * DOWN + (keycode == S) * UP + \
	(keycode == A) * LEFT + (keycode == D) * RIGHT;
	if (faced == turn)
		return (0);
	turn = faced;
	mlx_put_image_to_window(gen->win.mlx, gen->win.win, gen->img.img[faced], \
	gen->map.player_x * 32, gen->map.player_y * 32);
	return (1);
}

void	check_mov(t_gen *gen, int keycode)
{
	static int	steps = 0;
	char		*next_move;

	if (check_faced(gen, keycode))
		return ;
	next_move = &gen->map.str[gen->map.player_y - (keycode == W) + \
	(keycode == S)][gen->map.player_x - (keycode == A) + (keycode == D)];
	if (*next_move == 'C')
		gen->map.collectable--;
	if (*next_move != '1' && (*next_move != 'E' || !gen->map.collectable))
		moveplayer(gen, keycode, next_move, ++steps);
	return ;
}
