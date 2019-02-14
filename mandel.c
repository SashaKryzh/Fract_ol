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
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	int		k;

	zx = 0.0;
	zy = 0.0;
	zx2 = 0.0;
	zy2 = 0.0;
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
	int		i; // Counter !!!
	int		j; // Counter !!!
	double	c_x; // Curent
	double	c_y; // Curent

	int		xres = 1920; // Set size
	int		yres = 1080; //(xres * (im_max - im_min) / (re_max - re_min)); // Set size

	double re_min = -2.5;
	double re_max = 1.5;
	double im_min = -2.0;
	double im_max = im_min + (re_max - re_min) * yres / xres;

	double	re_fact = (re_max - re_min) / xres; // Pixel width
	double	im_fact = (im_max - im_min) / yres; // Pixel height

	i = 0;
	while (i < yres)
	{
		c_y = im_max - i * im_fact;
		j = 0;
		while (j < xres)
		{
			c_x = re_min + j * re_fact;
			m_pixel_fill(fract, j, i, iter(fract, c_x, c_y));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(IMGWIN_PAR, 0, 0);
}
