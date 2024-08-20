/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:28:35 by rmehadje          #+#    #+#             */
/*   Updated: 2023/09/23 17:33:53 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbroke(t_fractol	*w, double x, double y)
{
	w->realnum = w->xmin + x / WIDTH * (w->xmax - w->xmin);
	w->imagnum = w->ymin + y / HEIGHT * (w->ymax - w->ymin);
	w->conr = w->realnum;
	w->conmag = w->imagnum;
	w->iterations = 0;
	w->realz = 0.0;
	w->zimag = 0.0;
}

void	ft_mandelbrot(void *param)
{
	t_fractol		*w;
	uint32_t		x;
	uint32_t		y;

	w = (t_fractol *)param;
	if (w->shouldraw != 1)
		return ;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_mandelbroke(w, x, y);
			while (w->iterations < MAXITERATIONS && w->realz * w->realz
				+ w->zimag * w->zimag <= 4.0)
				ft_updatez(w);
			w->color = ft_pixel(w->iterations % 1, w->iterations % 40,
					w->iterations % 140, 255);
			mlx_put_pixel(w->image, x, y, w->color);
			x++;
		}
		y++;
	}
	w->shouldraw = 0;
}
