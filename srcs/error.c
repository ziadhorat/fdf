/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:42:37 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/21 11:42:38 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fdf.h"

int		ft_is_valid(char *str)
{
	while (*str)
	{
		if (*str != '-' && *str != '+' && !ft_isdigit(*str))
			return (0);
		if ((*str == '-' || *str == '+') && (!*(str + 1) ||
				!ft_isdigit(*(str + 1))))
			return (0);
		++str;
	}
	return (1);
}

void	ft_throw_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
