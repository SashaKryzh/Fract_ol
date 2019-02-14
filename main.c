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

void	magic(t_fract *fract)
{
	fract->max_iter = 100;
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
