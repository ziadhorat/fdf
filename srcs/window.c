/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:43:04 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/21 12:51:43 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fdf.h"

void	ft_start_window(t_env env)
{
	mlx_string_put(env.mlx_data.mlx_id, env.mlx_data.window_id,
					env.options.width - 130, env.options.height - 80,
					0x00FFFFFF, "> Size+");
	mlx_string_put(env.mlx_data.mlx_id, env.mlx_data.window_id,
					env.options.width - 130, env.options.height - 65,
					0x00FFFFFF, "< Size-");
	mlx_string_put(env.mlx_data.mlx_id, env.mlx_data.window_id,
					env.options.width - 130, env.options.height - 40,
					0x00FFFFFF, "+ Zoom+");
	mlx_string_put(env.mlx_data.mlx_id, env.mlx_data.window_id,
					env.options.width - 130, env.options.height - 25,
					0x00FFFFFF, "- Zoom-");
	mlx_loop(env.mlx_data.mlx_id);
}

void	ft_generate_window(t_env *env)
{
	if (env->options.width <= 0 || env->options.height <= 0 ||
			env->options.width >= 1920 || env->options.height >= 1080)
		ft_throw_error();
	env->mlx_data.mlx_id = mlx_init();
	env->mlx_data.window_id = mlx_new_window(env->mlx_data.mlx_id,
											env->options.width,
											env->options.height,
											WINDOW_TITLE);
	mlx_key_hook(env->mlx_data.window_id, ft_listen_key, env);
	env->init = 1;
}
