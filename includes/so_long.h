/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:26:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/23 13:04:43 by mtavares         ###   ########.fr       */
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
typedef void			(*t_hooks)(t_gen *gen);
typedef void			(*t_iv)(t_gen *gen);
typedef void			(*t_cw)(t_gen *gen);
typedef int				(*t_cm)(t_gen *gen, char **av);

/* Structs */

struct s_hook
{
	t_hooks	hooks;
};
typedef struct s_hook	t_hook;

struct s_map
{
	t_cm	check_map;
	char	**str;
	int		walls;
	int		player;
	int		collectable;
	int		exit;
	int		empty;
	int		other;
};
typedef struct s_map	t_map;

struct s_win
{
	void	*mlx;
	void	*win;
	t_cw	create_window;
};
typedef struct s_win	t_win;

struct s_gen
{
	t_win	win;
	t_map	map;
	t_hook	hook;
	t_iv	init_values;

};

/* Functions */

void	init_values(t_gen *gen);
int		check_map(t_gen *gen, char **av);
char	**map_to_str(char **map, int fd, int counter);
void	hook_loops(t_gen *gen);
void	exit_prog(t_gen	*gen, char	*str, int i);
void	create_window(t_gen *gen);

#endif