/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:53:41 by rmehadje          #+#    #+#             */
/*   Updated: 2023/10/31 17:22:15 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define HEIGHT 1200
# define WIDTH 1200
# define MAXITERATIONS 1000

typedef struct s_fractol
{
	void			*window;
	void			*context;
	mlx_t			*mlx;
	mlx_image_t		*image;
	double			imagnum;
	double			realnum;
	int				iterations;
	double			xmax;
	double			res;
	int				i;
	int				j;
	double			xmin;
	double			ymax;
	double			ymin;
	double			conr;
	double			realz;
	double			zimag;
	double			conmag;
	double			sqrealz;
	double			sqzimag;
	double			newrealz;
	double			newzimag;
	int				shouldraw;
	double			repeatedx;
	double			repeatedy;
	uint32_t		x;
	uint32_t		y;
	uint32_t		color;
}	t_fractol;

void		ft_updatez(t_fractol *w);
void		ft_hookit(mlx_key_data_t	keydata, void *param);
double		ft_atof(char *str, t_fractol	*w);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
double		ft_powow(int n);
int			ft_isnum(int c);
int			ft_swiftexit(t_fractol	*w);
int			ft_spaces(int c);
int			valid_input(char *str);
int			ft_clean(mlx_t *mlx, t_fractol *w);
void		ft_initw(t_fractol *w, char **C, mlx_t *mlx, int argc);
void		ft_julia(void *param);
int			ft_joline(float r, float i, float cr, float ic);
void		ft_mandelbroke(t_fractol	*w, double x, double y);
void		ft_mandelbrot(void *param);
void		ft_scroll(double xdelta, double ydelta, void *param);
void		upnorth(t_fractol	*w);
void		retreat(t_fractol	*w);
void		flankleft(t_fractol	*w);
void		flankright(t_fractol	*w);

#endif