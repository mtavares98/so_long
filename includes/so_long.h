/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:26:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/26 18:16:43 by mtavares         ###   ########.fr       */
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

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define DOWN 2
# define UP 3
# define LEFT 4
# define RIGHT 5
# define WALL 12
# define EMPTY 0
# define EXIT 1

/* Keycode importants:
	w = 119
	a = 97
	s = 115
	d = 100
	esc = 65307
*/

/* Typedefs */

typedef struct s_gen		t_gen;
typedef struct s_check_path	t_cp;
typedef struct s_map		t_map;
typedef struct s_win		t_win;
typedef struct s_img		t_img;

/* Structs */

struct s_map
{
	int		player_x;
	int		player_y;
	int		len_x;
	int		len_y;
	char	**str;
	int		enemy;
	int		walls;
	int		player;
	int		collectable;
	int		exit;
	int		empty;
	int		other;
};
struct s_win
{
	void		*mlx;
	void		*win;
};

struct s_img
{
	void		**img;
};

struct s_gen
{
	t_win		win;
	t_map		map;
	t_img		img;
	int			steps;
};

struct s_check_path
{
	int		len_x;
	int		len_y;
	char	**map;
};

/* Functions */

void	exit_prog(t_gen	*gen, char	*str, int i);
void	init_values(t_gen *gen);
int		prep_alg(t_gen *gen);
int		check_map(t_gen *gen, char **av);
void	check_mov(t_gen *gen, int keycode);
char	**map_to_str(char **map, int fd, int counter);
void	map_to_img(t_gen *gen);
void	print_map(t_gen *gen, int index_x, int index_c);
void	hook_loops(t_gen *gen);
void	create_window(t_gen *gen);

#endif
