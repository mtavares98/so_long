/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:36 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/20 21:24:49 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_to_str(char **map, int fd, int counter)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		map = map_to_str(map, fd, 1 + counter);
	if (!map && counter != 0)
		map = malloc((counter + 1) * (sizeof(char *)));
	if (!map)
		return (NULL);
	map[counter] = str;
	return (map);
}
