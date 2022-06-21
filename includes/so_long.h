/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:26:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/21 23:16:54 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/printf_fd/include/printf_fd.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <math.h>

/* Keycode importants:
	w = 119
	a = 97
	s = 115
	d = 100
	esc = 65307
*/

/* Typedefs */

typedef struct s_gen	t_gen;
typedef struct s_map	t_map;
typedef struct s_win	t_win;
typedef struct s_hook	t_hook;

/* Structs */

struct s_gen
{
	t_win	*win;
	t_map	*map;
	t_hook	*hook;
	void	(*init_values)(t_gen *gen);
};

struct s_hook
{
	void	(*moviments)(t_gen *gen);
};

struct s_map
{
	int		(*t_check_map)(t_gen *gen, char **av);
	char	**str;
	int		walls;
	int		player;
	int		collectable;
	int		exit;
	int		empty;
};

struct s_win
{
	void	*mlx;
	void	*win;
	void	(*create_win)(t_win *win);
};

/* Functions */

void	init_values(t_gen *gen);
int		check_map(t_gen *gen, char **av);
char	**map_to_str(char **map, int fd, int counter);
void	hook_loops(t_gen *gen);
void	exit_prog(t_gen	*gen, char	*str, int i);
void	create_window(t_win *obj);

#endif