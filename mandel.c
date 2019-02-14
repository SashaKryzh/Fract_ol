/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:53:24 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/14 11:53:24 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	m_pixel_fill(t_fract *f, int x, int y, int k)
{
	if (k >= f->max_iter)
		pixel_fill(f, x, y, 0);
	else
		pixel_fill(f, x, y, color_calc(k));
}

int		iter(t_fract *f, double x, double y)
{
	double zx;
	double zy;
	double zx2;
	double zy2;
	int k;

	zx = 0.0;
	zy = 0.0;
	zx2 = pow(zx, 2);
	zy2 = pow(zy, 2);
	k = 0;
	while (k < f->max_iter && zx2 + zy2 < 4.0)
	{
		zy = 2 * zx * zy + y;
		zx = zx2 - zy2 + x;
		zx2 = pow(zx, 2);
		zy2 = pow(zy, 2);
		k++;
	}
	return (k);
}

void	Mandelbrot_set(t_fract *fract)
{
	double xmin = -2.5;
	double xmax = 1.5;
	double ymin = -2.0;
	double ymax = 2.0;

	int xres = 1000; // Set size
	int	yres = (xres * (ymax - ymin) / (xmax - xmin)); // Set size

	double	dx = (xmax - xmin) / xres; // Pixel width
	double	dy = (ymax - ymin) / yres; // Pixel height

	double	x; // Curent
	double	y; // Curent

	int i; // Counter !!!
	int j; // Counter !!!

	fract->max_iter = 100;

	i = 0;
	while (i < yres)
	{
		y = ymax - i * dy;
		j = 0;
		while (j < xres)
		{
			x = xmin + j * dx;
			m_pixel_fill(fract, j, i, iter(fract, x, y));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0, 0);
}
