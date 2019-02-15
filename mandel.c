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

int		julia(t_fract *f, double zx, double zy)
{
	double	cx;
	double	cy;
	double	zx2;
	double	zy2;
	int k;

	cx = -0.8;
	cy = 0.156;
	zx2 = pow(zx, 2);
	zy2 = pow(zy, 2);
	k = 0;
	while (k < f->max_iter && zx2 + zy2 < 4)
	{
		zy = 2 * zx * zy + cy;
		zx = zx2 - zy2 + cx;
		zx2 = pow(zx, 2);
		zy2 = pow(zy, 2);
		k++;
	}
	return (k);
}

int		mandel(t_fract *f, double x0, double y0)
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
	while (k < f->max_iter && zx2 + zy2 <= 4.0)
	{
		zy = 2 * zx * zy + y0;
		zx = zx2 - zy2 + x0;
		zx2 = pow(zx, 2);
		zy2 = pow(zy, 2);
		k++;
	}
	return (k);
}

void	Julia_Mandel(t_fract *f)
{
	double	xy[2];
	int		i;
	int		j;

	int		xres = 1000; // Set size
	int		yres = 1000;//(xres * (im_max - im_min) / (re_max - re_min)); // Set size

	double re_min = -2.5;
	double re_max = 1.5;
	double im_min = -2.0;
	double im_max = im_min + (re_max - re_min) * yres / xres;

	double	re_fact = (re_max - re_min) / xres; // Pixel width
	double	im_fact = (im_max - im_min) / yres; // Pixel height

	i = 0;
	while (i < yres)
	{
		xy[1] = im_max - i * im_fact;
		j = 0;
		while (j < xres)
		{
			xy[0] = re_min + j * re_fact;
			m_pixel_fill(f, j, i, f->fract(f, xy[0], xy[1]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(IMGWIN_PARAMS, 0, 0);
}
