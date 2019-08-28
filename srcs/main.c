/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:13 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/28 14:45:42 by zmahomed         ###   ########.fr       */
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
	ft_putstr("Move Y: k: UP, DOWN\nMove X: k: LEFT, RIGHT\n\
\nRotate X: (kpad) 1, 4\nRotate Y: (kpad) 2, 5\n\
Rotate Z: (kpad) 3, 6\n\
\nZoom:\nZoom IN: (kpad) +\nZoom OUT: (kpad) -\n");
}

int		cross_exit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	free(e);
	exit(0);
	return (0);
}

int		main(int argc, char **av)
{
	t_env	*e;
	t_map	*map;

	if (argc == 2)
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			fdf_malloc_error();
		map = ft_parse_map(av, 0);
		if (map->len == 0 || map->lines[0]->len == 0)
			fdf_map_error();
		e->map = map;
		get_center(e);
		display_controls();
		draw_windows("FDF", WINDOW_SIZE_W, WINDOW_SIZE_H, e);
		adapt_map(e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, 17, 0, cross_exit, e);
		mlx_hook(e->win, 2, 3, k_hook, e);
		mlx_loop(e->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
