/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:10:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/05 00:08:24 by mtavares         ###   ########.fr       */
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
		gen->map.player++;
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

	i = 0;
	while (gen->map.str[++i])
	{
		j = 0;
		while (gen->map.str[i][++j] != '\0')
		{
			if (count_comp(gen, i, j) == 1)
				return (1);
		}
	}
	if (gen->map.exit < 1 || gen->map.collectable < 1 || \
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
	if (i < 2)
		return (2);
	return (0);
}

static int	map_closed(t_gen *gen)
{
	int	i;
	int	j;

	i = -1;
	while (gen->map.str[++i])
		;
	j = -1;
	i--;
	while (gen->map.str[i][++j])
		if (gen->map.str[0][j] != '1' || gen->map.str[i][j] != '1')
			return (1);
	i = 0;
	j--;
	while (gen->map.str[++i])
		if (gen->map.str[i][0] != '1' || gen->map.str[i][j] != '1')
			return (1);
	return (0);
}

int	check_map(t_gen *gen, char **av)
{
	int		i;
	char	*str;
	int		fd;

	str = ft_strrchr(av[1], '.');
	if (!str || strncmp(str, ".ber", 5))
		exit_prog(gen, "Wrong extension name\n", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_prog(gen, "File doesn't exits\n", 1);
	gen->map.str = map_to_str(gen->map.str, fd, 0);
	if (!gen->map.str)
		exit_prog(gen, "File's empty\n", 1);
	close(fd);
	i = map_rect(gen);
	if (i == 1)
		exit_prog(gen, "Map isn't rectangular\n", 1);
	if (i == 2)
		exit_prog(gen, "Does't have sufficient height\n", 1);
	if (map_closed(gen))
		exit_prog(gen, "Map is not closed\n", 1);
	if (have_comp(gen))
		exit_prog(gen, \
	"It requires one player, exit and colectable or have invalid chars\n", 1);
	return (1);
}
