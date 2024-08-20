/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:26:30 by rmehadje          #+#    #+#             */
/*   Updated: 2023/09/28 13:06:14 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_powow(int n)
{
	double		res;

	res = 1;
	while (n != 0)
	{
		if (n > 0)
		{
			res = res * 10;
			n--;
		}
		if (n < 0)
		{
			res = res / 10;
			n++;
		}
	}
	return (res);
}

int	ft_isnum(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	ft_swiftexit(t_fractol	*w)
{
	write (1, "please write the correct input", 31);
	mlx_terminate(w->mlx);
	free (w);
	exit (0);
}

int	ft_spaces(int c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	valid_input(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i++] == '.')
			c++;
		else
			return (0);
	}
	if (c > 1 || c == i)
		return (0);
	return (1);
}
