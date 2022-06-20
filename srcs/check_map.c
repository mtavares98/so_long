/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:10:03 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/20 22:38:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(t_gen *gen, char **av)
{
	char	*str;
	int		fd;

	str = ft_strrchr(av[1], '.');
	if (strncmp(str, ".ber", 5))
		exit_prog(gen, "Wrong extension name\n", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_prog(gen, "File doesn't exits\n", 1);
	gen->map->str = map_to_str(NULL, fd, 0);
	if (!gen->map->str)
		exit_prog(gen, "File's empty\n", 1);
	close(fd);
	return (1);
}
