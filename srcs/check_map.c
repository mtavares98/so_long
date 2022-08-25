/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:10:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/25 22:38:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_comp(t_gen *gen, int i, int j)
{
	if (gen->map.str[i][j] == 'E')
		gen->map.exit++;
	else if (gen->map.str[i][j] == 'C')
		gen->map.collectable++;
	else if (gen->map.str[i][j] == 'P')
	{
		gen->map.player++;
		gen->map.player_x = j;
		gen->map.player_y = i;
	}
	else if (gen->map.str[i][j] == '0')
		gen->map.empty++;
	else if (gen->map.str[i][j] == '1')
		gen->map.walls++;
	else if (gen->map.str[i][j] == 'X')
		gen->map.enemy++;
	else
		return (1);
	return (0);
}

static int	have_comp(t_gen *gen)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (gen->map.str[++i])
	{
		j = -1;
		while (gen->map.str[i][++j] != '\0')
		{
			if (count_comp(gen, i, j) == 1)
				return (1);
		}
	}
	gen->map.len_x = j;
	gen->map.len_y = i;
	if (gen->map.exit != 1 || gen->map.collectable < 1 || \
	gen->map.player != 1)
		return (1);
	return (0);
}

static int	map_rect(t_gen *gen)
{
	int	i;

	i = -1;
	while (gen->map.str[++i + 1])
	{
		if (ft_strlen(gen->map.str[i]) != ft_strlen(gen->map.str[i + 1]))
			return (1);
	}
	return (0);
}

int	check_map(t_gen *gen, char **av)
{
	char	*str;
	int		fd;

	str = ft_strrchr(av[1], '.');
	if (!str || strncmp(str, ".ber", 5))
		exit_prog(gen, "Wrong extension name\n", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_prog(gen, "File doesn't exits\n", 1);
	gen->map.str = map_to_str(gen->map.str, fd, 0);
	close(fd);
	if (!gen->map.str)
		exit_prog(gen, "File's empty\n", 1);
	if (map_rect(gen))
		exit_prog(gen, "Invalid map\n", 1);
	if (have_comp(gen))
		exit_prog(gen, "Invalid map\n", 1);
	if (prep_alg(gen))
		exit_prog(gen, "Invalid map\n", 1);
	return (1);
}
