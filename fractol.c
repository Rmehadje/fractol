/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:40:10 by rmehadje          #+#    #+#             */
/*   Updated: 2023/10/31 16:18:15 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	ft_atof(char *str, t_fractol	*w)
{
	w->i = 0;
	w->res = 0;
	while (str[w->i] && str[w->i] != '.')
		w->i++;
	if (str[w->i] == '.')
		w->i++;
	w->j = 0;
	while (str[w->i] && ft_isnum(str[w->i]) && !ft_spaces(str[w->i++]))
		w->j--;
	while (str[--w->i])
	{
		if (str[w->i] == '.' || str[w->i] == '+' || str[w->i] == '-'
			|| ft_spaces(str[w->i]))
		{
			if (str[w->i] == '-')
				w->res *= -1;
			continue ;
		}
		w->res = w->res + ft_powow(w->j++) * (str[w->i] - '0');
	}
	if (!valid_input(str))
		ft_swiftexit(w);
	return (w->res);
}

void	ft_hookit(mlx_key_data_t	keydata, void	*param)
{
	t_fractol	*w;

	w = (t_fractol *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		upnorth(w);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		retreat(w);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		flankleft(w);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		flankright(w);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(w->mlx);
		free (w);
		exit (0);
	}
	w->shouldraw = 1;
}

void	ft_updatez(t_fractol *w)
{
	w->sqrealz = w->realz * w->realz;
	w->sqzimag = w->zimag * w->zimag;
	w->newrealz = w->sqrealz - w->sqzimag + w->conr;
	w->newzimag = 2 * w->realz * w->zimag + w->conmag;
	w->realz = w->newrealz;
	w->zimag = w->newzimag;
	w->iterations++;
}

int32_t	main(int argc, char **argv)
{
	t_fractol	*w;
	mlx_t		*mlx;

	mlx = NULL;
	if (argc > 1)
	{
		w = (t_fractol *)malloc(sizeof(t_fractol));
		w->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", 1);
		if (ft_clean(mlx, w) && w)
		{
			mlx_scroll_hook(w->mlx, ft_scroll, w);
			mlx_key_hook(w->mlx, ft_hookit, w);
			ft_initw(w, argv, mlx, argc);
			mlx_loop(w->mlx);
		}
		mlx_terminate(w->mlx);
		free (w);
		return (EXIT_SUCCESS);
	}
	else
	{
		write(1, "please chose m for mandelbrot"
			"or j - 0.75 0.11 for the julia set\n", 66);
		return (EXIT_FAILURE);
	}
}
