/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:42:37 by rmehadje          #+#    #+#             */
/*   Updated: 2023/09/23 17:29:00 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initw(t_fractol *w, char **C, mlx_t *mlx, int argc)
{
	w->shouldraw = 1;
	(void) mlx;
	if (C[1][0] == 'm' && argc == 2)
	{
		w->xmin = -2.5;
		w->xmax = 1.5;
		w->ymin = -2.0;
		w->ymax = 2.0;
		mlx_loop_hook(w->mlx, ft_mandelbrot, w);
	}
	else if (C[1][0] == 'j' && argc == 4)
	{
		w->xmin = -2.0;
		w->xmax = 2.0;
		w->ymin = -2.0;
		w->ymax = 2.0;
		w->conr = ft_atof(C[2], w);
		w->conmag = ft_atof(C[3], w);
		mlx_loop_hook(w->mlx, ft_julia, w);
	}
	else
		ft_swiftexit(w);
}

int	ft_clean(mlx_t *mlx, t_fractol *w)
{
	(void) mlx;
	if (!(w->mlx))
	{
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	w->image = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	if (!(w->image))
	{
		mlx_close_window(w->mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(w->mlx, w->image, 0, 0) == -1)
	{
		mlx_close_window(w->mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	return (1);
}
