/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:26:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/05 00:07:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/printf_fd/include/printf_fd.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <math.h>

# ifndef W
#  define W 119
# endif

# ifndef S
#  define S 115
# endif

# ifndef A
#  define A 97
# endif

# ifndef D
#  define D 100
# endif

/* Keycode importants:
	w = 119
	a = 97
	s = 115
	d = 100
	esc = 65307
*/

/* Typedefs */

typedef struct s_gen	t_gen;
typedef void			(*t_generic)(t_gen *gen);
typedef int				(*t_cm)(t_gen *gen, char **av);

/* Structs */

struct s_hook
{
	t_generic	hooks;
};
typedef struct s_hook	t_hook;

struct s_map
{
	int			player_x;
	int			player_y;
	char		**str;
	int			enemy;
	int			walls;
	int			player;
	int			collectable;
	int			exit;
	int			empty;
	int			other;
	int			end;
	t_cm		check_map;
};
typedef struct s_map	t_map;

struct s_win
{
	void		*mlx;
	void		*win;
	t_generic	create_window;
};
typedef struct s_win	t_win;

struct s_img
{
	void		**img;
	t_generic	load_img;
};

typedef struct s_img	t_img;

struct s_gen
{
	t_win		win;
	t_map		map;
	t_hook		hook;
	t_img		img;
	t_generic	init_values;

};

/* Functions */

void	exit_prog(t_gen	*gen, char	*str, int i);
void	init_values(t_gen *gen);
int		check_map(t_gen *gen, char **av);
void	move_player(t_gen *gen, int keycode);
char	**map_to_str(char **map, int fd, int counter);
void	map_to_img(t_gen *gen);
void	hook_loops(t_gen *gen);
void	create_window(t_gen *gen);

#endif