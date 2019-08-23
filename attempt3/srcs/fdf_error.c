/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:00 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/23 09:52:45 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_exit(void)
{
	exit(1);
}

void	fdf_malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	fdf_exit();
}

void	fdf_map_error(void)
{
	ft_putstr_fd("map error\n", 2);
	fdf_exit();
}

void	fdf_arg_error(void)
{
	ft_putstr_fd("Not enough arguments.\n", 2);
	fdf_exit();
}
