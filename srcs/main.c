/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:13 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/28 10:08:08 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		number_count(char *line)
{
	int		i;
	int		numcount;

	i = 0;
	numcount = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
		{
			if (line[i] >= '0' && line[i] <= '9')
				if (line[i + 1] == ' ' || line[i + 1] == '\0' || line[i + 1] == 'x')
					numcount++;
		}
		else
		{
			free(line);
			fdf_map_error();
		}
		i++;
	}
	return (numcount);
}

void	mapcheck(char **argv)
{
	int		fd;
	char	*line;
	int		linelen;
	int		i;

	linelen = 0;
	if (ft_strcmp(&argv[1][ft_strlen(argv[1])-4], ".fdf"))
		fdf_map_error();
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = number_count(line);
		if (linelen == 0)
			linelen = number_count(line);
		free(line);
		if (i != linelen)
			fdf_map_error();
	}
}

int		expose_hook(t_env *e)
{
	draw_reload(e);
	return (0);
}

void	display_controls(void)
{
	ft_putstr("Move Y: Key: UP, DOWN\nMove X: Key: LEFT, RIGHT\n\
\nRotate X: (Keypad) 1, 4\nRotate Y: (Keypad) 2, 5\n\
Rotate Z: (Keypad) 3, 6\n\
\nZoom:\nZoom IN: (Keypad) +\nZoom OUT: (Keypad) -\n");
}

int		cross_exit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	free(e);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	t_map	*map;

	if (argc == 2)
	{
//		mapcheck(argv);
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			fdf_malloc_error();
		map = ft_parse_map(argv, 0);
		if (map->len == 0 || map->lines[0]->len == 0)
			fdf_map_error();
		e->map = map;
		get_center(e);
		display_controls();
		draw_windows("FDF", WINDOW_SIZE_W, WINDOW_SIZE_H, e);
		adapt_map(e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, 17, 0, cross_exit, e);
		mlx_hook(e->win, 2, 3, key_hook, e);
		mlx_loop(e->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
