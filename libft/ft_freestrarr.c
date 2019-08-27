/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:22:37 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/27 12:22:47 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrarr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
}
