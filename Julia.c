/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:45:30 by rmehadje          #+#    #+#             */
/*   Updated: 2023/10/19 18:41:52 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_joline(float r, float i, float cr, float ic)
{
	int			iterations;
	float		tmp;
	float		tmp2;

	iterations = 0;
	while (iterations <= MAXITERATIONS && (r * r + i * i) <= 4)
	{
		tmp = r * r - i * i + cr;
		tmp2 = 2 * r * i + ic;
		r = tmp;
		i = tmp2;
		iterations++;
	}
	return (iterations);
}

void	ft_julia(void *param)
{
	t_fractol	*w;
	double		x;
	double		y;

	w = (t_fractol *)param;
	if (w->shouldraw != 1)
		return ;
	y = 0;
	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			w->realnum = w->xmin + x / WIDTH * (w->xmax - w->xmin);
			w->imagnum = w->ymin + y / HEIGHT * (w->ymax
					- w->ymin);
			w->iterations = ft_joline(w->realnum, w->imagnum,
					w->conr, w->conmag);
			w->color = ft_pixel(w->iterations % 255, w->iterations % 1,
					w->iterations % 255, 255);
			mlx_put_pixel(w->image, x, y, w->color);
		}
	}
	w->shouldraw = 0;
}
