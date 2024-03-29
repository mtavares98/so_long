/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:08:14 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/26 13:09:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	algorithm(t_cp *cp, int x, int y)
{
	cp->map[y][x] = 'P';
	if (x - 1 > -1 && (cp->map[y][x - 1] == 'C' || cp->map[y][x - 1] == '0'))
		algorithm(cp, x - 1, y);
	if (y - 1 > -1 && (cp->map[y - 1][x] == 'C' || cp->map[y - 1][x] == '0'))
		algorithm(cp, x, y - 1);
	if (x + 1 < cp->len_x && \
	(cp->map[y][x + 1] == 'C' || cp->map[y][x + 1] == '0'))
		algorithm(cp, x + 1, y);
	if (y + 1 < cp->len_y && \
	(cp->map[y + 1][x] == 'C' || cp->map[y + 1][x] == '0'))
		algorithm(cp, x, y + 1);
	return ;
}

static void	free_map(t_cp *cp)
{
	int	i;

	if (cp->map)
	{
		i = -1;
		while (cp->map[++i])
			free(cp->map[i]);
		free(cp->map);
	}
}

static t_cp	cp_init(t_gen *gen)
{
	int		i;
	t_cp	cp;

	cp.len_y = -1;
	while (gen->map.str[++cp.len_y])
		;
	cp.map = malloc(sizeof(char *) * (cp.len_y + 1));
	cp.len_x = -1;
	while (gen->map.str[0][++cp.len_x])
		;
	i = -1;
	while (++i < cp.len_y)
	{
		cp.map[i] = ft_strdup(gen->map.str[i]);
		if (!cp.map)
		{
			free_map(&cp);
			exit_prog(gen, "Malloc failed copying the map\n", 1);
		}
	}
	cp.map[i] = NULL;
	return (cp);
}

int	check_path_map(t_cp *cp, int x, int y)
{
	if (cp->map[y][x] == 'C')
	{
		free_map(cp);
		return (1);
	}
	if (cp->map[y][x] == 'E')
	{
		if (cp->map[y][x - 1] != 'P' && cp->map[y - 1][x] != 'P' \
		&& cp->map[y][x + 1] != 'P' && cp->map[y + 1][x] != 'P')
		{
			free_map(cp);
			return (1);
		}
	}
	if (cp->map[y][x] != '0' && cp->map[y][x] != '1' && cp->map[y][x] != 'E' \
	&& cp->map[y][x] != 'P' && cp->map[y][x] != 'C' && cp->map[y][x] != 'X')
	{
		free_map(cp);
		return (1);
	}
	return (0);
}

int	prep_alg(t_gen *gen)
{
	t_cp	cp;
	int		x;
	int		y;
	int		i;

	cp = cp_init(gen);
	x = gen->map.player_x;
	y = gen->map.player_y;
	algorithm(&cp, x, y);
	y = -1;
	while (cp.map[++y])
	{
		x = -1;
		while (cp.map[y][++x])
		{
			i = check_path_map(&cp, x, y);
			if (i)
				return (i);
		}
	}
	free_map(&cp);
	return (0);
}
