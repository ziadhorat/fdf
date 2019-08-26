/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:07 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/26 11:55:23 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	key_hook_rotation(int keycode, t_env *e)
{
	if (keycode == KEY_ROT_X_U)
		ft_cal_rotation(e, MOVE_ROT_X_U, 'x');
	else if (keycode == KEY_ROT_X_D)
		ft_cal_rotation(e, MOVE_ROT_X_D, 'x');
	else if (keycode == KEY_ROT_Y_U)
		ft_cal_rotation(e, MOVE_ROT_Y_U, 'y');
	else if (keycode == KEY_ROT_Y_D)
		ft_cal_rotation(e, MOVE_ROT_Y_D, 'y');
	else if (keycode == KEY_ROT_Z_U)
		ft_cal_rotation(e, MOVE_ROT_Z_U, 'z');
	else if (keycode == KEY_ROT_Z_D)
		ft_cal_rotation(e, MOVE_ROT_Z_D, 'z');
}

static	void	key_hook_translation(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		ft_cal_translat(e, 0, MOVE_UP, 0);
	else if (keycode == KEY_DOWN)
		ft_cal_translat(e, 0, MOVE_DOWN, 0);
	else if (keycode == KEY_LEFT)
		ft_cal_translat(e, MOVE_LEFT, 0, 0);
	else if (keycode == KEY_RIGHT)
		ft_cal_translat(e, MOVE_RIGHT, 0, 0);
}

static	void	key_hook_scale(int keycode, t_env *e)
{
	if (keycode == KEY_ZOOM_IN)
		ft_cal_scale(e, MOVE_ZOOM_IN);
	else if (keycode == KEY_ZOOM_OUT)
		ft_cal_scale(e, MOVE_ZOOM_OUT);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	key_hook_rotation(keycode, e);
	key_hook_translation(keycode, e);
	key_hook_scale(keycode, e);
	draw_reload(e);
	return (0);
}
