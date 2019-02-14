/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:44:45 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/07 14:44:45 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, void *param)
{
	if (key == ESC)
	{
		exit(0);
	}
	return (0);
}

void	init_win(t_fract *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		"Fract_ol");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	fract->img_p = mlx_get_data_addr(fract->img_ptr,
		&fract->bpp, &fract->size_line, &fract->endian);
}

void	pixel_fill(t_fract *fract, int color, int x, int y)
{
	mlx_pixel_put(fract->mlx_ptr, fract->win_ptr, x, y, color);
}

void	Mandelbrot_set(t_fract *fract)
{
	double xmin = -2.0;
	double xmax = 1.5;
	double ymin = -2.0;
	double ymax = 2.0;

	int xres = 1500; // Set size
	int	yres = (xres * (ymax - ymin) / (xmax - xmin)); // Set size

	double	dx = (xmax - xmin) / xres; // Pixel width
	double	dy = (ymax - ymin) / yres; // Pixel height

	double	x; // Curent
	double	y; // Curent

	double	u; // Iterated
	double	v; // Iterated
	double	u2;
	double	v2;

	int i; // Counter
	int j; // Counter

	int	k; // Iterations

	j = 0;
	while (j < yres)
	{
		y = ymax - j * dy;
		i = 0;
		while (i < xres)
		{
			x = xmin + i * dx;
			u = 0.0;
			v = 0.0;
			u2 = pow(u, 2);
			v2 = pow(v, 2);
			k = 0;
			while (k < 65555 && u2 + v2 < 4.0)
			{
				v = 2 * u * v + y;
				u = u2 - v2 + x;
				u2 = pow(u, 2);
				v2 = pow(v, 2);
				k++;
			}
			i++;
			if (k > 65555)
			{
				pixel_fill(fract, 0, i, j);
			}
			else
			{
				pixel_fill(fract, 2147483647, i, j);
			}
		}
		j++;
	}
}

void	magic(t_fract *fract)
{
	Mandelbrot_set(fract);
	mlx_hook(fract->win_ptr, 2, 5, key_hook, (void *)fract);
	mlx_loop(fract->mlx_ptr);
}

int		main(void)
{
	t_fract	fract;

	init_win(&fract);
	magic(&fract);
	return (0);
}
