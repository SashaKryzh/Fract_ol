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

void	calc_c(t_fract *f, double *cx, double *cy)
{
	if (f->mouse_x == 0 && f->mouse_y == 0)
	{
		*cx = -0.8;
		*cy = 0.156;
	}
	else
	{
		*cx = f->re_min + f->mouse_x * f->re_fact;
		*cy = f->im_max - f->mouse_y * f->im_fact;
	}
}

int		julia(t_fract *f, double zx, double zy)
{
	double	cx;
	double	cy;
	double	zx2;
	double	zy2;
	int k;

	calc_c(f, &cx, &cy);
	zx2 = pow(zx, 2);
	zy2 = pow(zy, 2);
	k = 0;
	while (k < f->max_iter && zx2 + zy2 <= 4)
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

void	init_vars(t_fract *f)
{
	f->x_res = IMG_WIDTH;
	f->y_res = IMG_HEIGHT;
	if (f->fract == &mandel)
	{
		f->re_min = -3.0;
		f->re_max = 2.0;
		f->im_min = -1.5;
		f->im_max = 1.5;
	}
	else
	{
		f->re_min = -2.0;
		f->re_max = 2.0;
		f->im_min = -1.2;
		f->im_max = 1.2;
	}
	f->re_fact = (f->re_max - f->re_min) / f->x_res;
	f->im_fact = (f->im_max - f->im_min) / f->y_res;
	zoom(f);
}

void	Julia_Mandel(t_fract *f)
{
	double	xy[2];
	int		i;
	int		j;

	init_vars(f);
	i = 0;
	while (i < f->y_res)
	{
		xy[1] = f->im_max - i * f->im_fact;
		j = 0;
		while (j < f->x_res)
		{
			xy[0] = f->re_min + j * f->re_fact;
			m_pixel_fill(f, j, i, f->fract(f, xy[0], xy[1]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(IMGWIN_PARAMS, 0, 0);
}
