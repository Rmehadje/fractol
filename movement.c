/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:56:10 by rmehadje          #+#    #+#             */
/*   Updated: 2023/09/23 17:38:02 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	upnorth(t_fractol	*w)
{
	w->ymin += (w->ymax - w->ymin) * -0.1;
	w->ymax += (w->ymax - w->ymin) * -0.1;
}

void	retreat(t_fractol	*w)
{
	w->ymin -= (w->ymax - w->ymin) * -0.1;
	w->ymax -= (w->ymax - w->ymin) * -0.1;
}

void	flankright(t_fractol	*w)
{
	w->xmin -= (w->xmax - w->xmin) * -0.1;
	w->xmax -= (w->xmax - w->xmin) * -0.1;
}

void	flankleft(t_fractol	*w)
{
	w->xmin += (w->xmax - w->xmin) * -0.1;
	w->xmax += (w->xmax - w->xmin) * -0.1;
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol		*w;
	mlx_t			*mlx;
	double			s;

	w = (t_fractol *)param;
	mlx = (mlx_t *)param;
	s = 0.05;
	xdelta = 0;
	w->repeatedx = w->xmax - w->xmin;
	w->repeatedy = w->ymax - w->ymin;
	if (ydelta < 0)
	{
		w->xmin += w->repeatedx * s;
		w->xmax -= w->repeatedx * s;
		w->ymin += w->repeatedy * s;
		w->ymax -= w->repeatedy * s;
	}
	else if (ydelta > 0)
	{
		w->xmin -= w->repeatedx * s;
		w->xmax += w->repeatedx * s;
		w->ymax += w->repeatedy * s;
		w->ymin -= w->repeatedy * s;
	}
	w->shouldraw = 1;
}
