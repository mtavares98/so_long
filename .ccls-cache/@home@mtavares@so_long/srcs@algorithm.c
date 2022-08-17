#include "../includes/so_long.h"

static void algo(t_cp *cp, int x, int y)
{
	cp->map[y][x] = 'P';
	if (x - 1 > -1 && cp->map[y][x - 1] != '1' && cp->map[y][x - 1] != 'P')
		algo(cp, x - 1, y);
	if (y - 1 > -1 && cp->map[y - 1][x] != '1' && cp->map[y - 1][x] != 'P')
		algo(cp, x, y - 1);
	if (x + 1 < cp->len_x && cp->map[y][x + 1] != '1' && cp->map[y][x + 1] != 'P')
		algo(cp, x + 1, y);
	if (y + 1 < cp->len_y && cp->map[y + 1][x] != '1' && cp->map[y + 1][x] != 'P')
		algo(cp, x, y + 1);
	return;
}

static void free_map(t_cp *cp)
{
	int i;

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

int pre_algo(t_gen *gen)
{
	t_cp cp;
	int x;
	int y;

	cp = cp_init(gen);
	x = gen->map.player_x;
	y = gen->map.player_y;
	
	algo(&cp, x, y);
	y = -1;
	while (cp.map[++y])
	{
		x = -1;
		while (cp.map[y][++x])
			if (cp.map[y][x] == 'E' || cp.map[y][x] == 'C')
			{
				free_map(&cp);
				return (1);
			}
	}
	free_map(&cp);
	return (0);
}
