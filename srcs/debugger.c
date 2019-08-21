/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:42:21 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/21 11:42:27 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_list	*ft_debug_points(t_list *element)
{
	t_point	*point;

	point = (t_point*)(element->content);
	ft_putstr("[DEBUG] Point at x=");
	ft_putnbr(point->x);
	ft_putstr("; y=");
	ft_putnbr(point->y);
	ft_putstr("; h=");
	ft_putnbr(point->h);
	ft_putstr("; index=");
	ft_putnbr(point->index);
	ft_putstr("\n");
	return (element);
}
