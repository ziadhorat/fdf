/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:48:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/27 13:27:43 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_getnbr(char *str)
{
	int nbr;
	int neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1, str++;
	nbr = 0;
	while ((*str >= '0') && (*str <= '9'))
		nbr = (nbr * 10) + *str++ - '0';
	return ((neg == 1) ? -nbr : nbr);
}

int		ft_points(char *line, int nb_line, t_point ***array_points)
{
	char	**array_str;
	t_point	*a_point;
	int		i;

	array_str = ft_strsplit(line, ' ');
	i = 0;
	while (array_str[i] != 0)
		i++;
	if (!((*array_points) = (t_point**)malloc(sizeof(t_point) * i)))
		fdf_malloc_error();
	i = 0;
	while (array_str[i] != 0)
	{
		a_point = (t_point*)malloc(sizeof(t_point));
		a_point->x = i * SIZE_W;
		a_point->y = nb_line * SIZE_H;
		a_point->z = ft_getnbr(array_str[i]);
		a_point->s = 1;
		a_point->z_color = a_point->z;
		(*array_points)[i] = a_point;
		i++;
	}
	ft_freestrarr(array_str);
	return (i);
}

int		ft_map_line(char *map)
{
	int		fd;
	int		nb_lines;
	char	buf;

	fd = 0;
	nb_lines = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		fdf_map_error();
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nb_lines++;
	}
	close(fd);
	return (nb_lines);
}

t_map	*ft_parse_map(char **av, int fd)
{
	char	*line;
	int		nb_line;
	t_map	*map;
	t_line	*line_map;
	t_point	**array_points;

	nb_line = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))) ||
		!(map->lines = (t_line**)malloc(sizeof(t_line) * ft_map_line(av[1]))))
		fdf_malloc_error();
	map->len = 0;
	if ((fd = open(av[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(line_map = (t_line*)malloc(sizeof(t_line))))
				fdf_malloc_error();
			line_map->len = ft_points(line, nb_line, &array_points);
			line_map->points = array_points;
			map->lines[nb_line] = line_map;
			nb_line++;
			free(line);
		}
		map->len = nb_line;
	}
	return (map);
}
