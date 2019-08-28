/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:07 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/27 13:15:37 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	k_hook_rotation(int kcode, t_env *e)
{
	if (kcode == k_ROT_X_U)
		ft_cal_rotation(e, MOVE_ROT_X_U, 'x');
	else if (kcode == k_ROT_X_D)
		ft_cal_rotation(e, MOVE_ROT_X_D, 'x');
	else if (kcode == k_ROT_Y_U)
		ft_cal_rotation(e, MOVE_ROT_Y_U, 'y');
	else if (kcode == k_ROT_Y_D)
		ft_cal_rotation(e, MOVE_ROT_Y_D, 'y');
	else if (kcode == k_ROT_Z_U)
		ft_cal_rotation(e, MOVE_ROT_Z_U, 'z');
	else if (kcode == k_ROT_Z_D)
		ft_cal_rotation(e, MOVE_ROT_Z_D, 'z');
}

static	void	k_hook_translation(int kcode, t_env *e)
{
	if (kcode == k_UP)
		ft_cal_translat(e, 0, MOVE_UP, 0);
	else if (kcode == k_DOWN)
		ft_cal_translat(e, 0, MOVE_DOWN, 0);
	else if (kcode == k_LEFT)
		ft_cal_translat(e, MOVE_LEFT, 0, 0);
	else if (kcode == k_RIGHT)
		ft_cal_translat(e, MOVE_RIGHT, 0, 0);
}

static	void	k_hook_scale(int kcode, t_env *e)
{
	if (kcode == k_ZOOM_IN)
		ft_cal_scale(e, MOVE_ZOOM_IN);
	else if (kcode == k_ZOOM_OUT)
		ft_cal_scale(e, MOVE_ZOOM_OUT);
}

int				k_hook(int kcode, t_env *e)
{
	if (kcode == k_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	k_hook_rotation(kcode, e);
	k_hook_translation(kcode, e);
	k_hook_scale(kcode, e);
	draw_reload(e);
	return (0);
}
