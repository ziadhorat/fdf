/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:47:38 by zmahomed          #+#    #+#             */
/*   Updated: 2019/08/27 13:41:46 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"

# define DEC_T 100
# define DEC_L 100
# define SIZE_W 20
# define SIZE_H 20

# define WINDOW_SIZE_H 1000
# define WINDOW_SIZE_W 2000

# define MOVE_UP -100
# define MOVE_DOWN 100
# define MOVE_LEFT -100
# define MOVE_RIGHT 100

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

# define MOVE_ROT_X_U -M_PI / 64
# define MOVE_ROT_X_D M_PI / 64
# define MOVE_ROT_Y_U -M_PI / 64
# define MOVE_ROT_Y_D M_PI / 64
# define MOVE_ROT_Z_U -M_PI / 64
# define MOVE_ROT_Z_D M_PI / 64

# define k_ESC 53

# define k_UP 126
# define k_DOWN 125
# define k_LEFT 123
# define k_RIGHT 124

# define k_ZOOM_IN 69
# define k_ZOOM_OUT 78

# define k_ROT_X_U 86
# define k_ROT_X_D 83
# define k_ROT_Y_U 87
# define k_ROT_Y_D 84
# define k_ROT_Z_U 88
# define k_ROT_Z_D 85

typedef struct	s_point {
	double	x;
	double	y;
	double	z;
	double	s;
	int		z_color;
}				t_point;

typedef struct	s_line {
	t_point	**points;
	int		len;
}				t_line;

typedef struct	s_map {
	t_line	**lines;
	int		len;
}				t_map;

typedef struct	s_env {
	void	*mlx;
	void	*win;
	t_map	*map;
	t_point	center;
	void	*img;
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
}				t_env;

typedef struct	s_matrice {
	double a1;
	double a2;
	double a3;
	double a4;
	double b1;
	double b2;
	double b3;
	double b4;
	double c1;
	double c2;
	double c3;
	double c4;
	double d1;
	double d2;
	double d3;
	double d4;
}				t_matrice;

t_map			*ft_parse_map(char **av, int fd);
int				ft_points(char *line, int nb_line, t_point ***array_points);
void			ft_parse_points (char *nb_str);
int				ft_map_line(char *map);
void			draw_windows(char *title, int weight, int height, t_env *e);
void			draw_map(t_env *e);
void			fdf_exit(void);
void			fdf_malloc_error(void);
void			fdf_map_error(void);
void			fdf_arg_error(void);
void			ft_cal_rotation(t_env *e, double rot, char axe);
void			ft_cal_translat(t_env *e, double x, double y, double z);
void			ft_cal_scale(t_env *e, double s);
t_matrice		*ft_matrice_rotation_x(double beta);
t_matrice		*ft_matrice_rotation_y(double beta);
t_matrice		*ft_matrice_rotation_z(double beta);
t_matrice		*ft_matrice_translation(double tx, double ty, double tz);
t_matrice		*ft_matrice_scale(double s);
int				k_hook(int kcode, t_env *e);
int				get_color(t_point *point1, t_point *point2);
void			get_center(t_env *e);
void			draw_reload(t_env *e);
int				point_in_window(t_point point1, t_point point2);
void			adapt_map(t_env *e);
int				point_out_window(t_point *point1);

#endif
