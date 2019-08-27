/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:13 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/27 09:35:44 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env *e)
{
	draw_reload(e);
	return (0);
}

void	display_controls(void)
{
	ft_putstr("\
Translation:\n\
	Y: Key: UP, DOWN\n\
	X: Key: LEFT, RIGHT\n\
\n\
Rotation:\n\
	X: Keypad: 1, 4\n\
	Y: Keypad: 2, 5\n\
	Z: Keypad: 3, 6\n\
\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -\n\
");
}

int		main(int argc, char **argv)
{
	t_env	*e;
	t_map	*map;

	if (argc == 2)
	{
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
		mlx_hook(e->win, 2, 3, key_hook, e);
		mlx_loop(e->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
