/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:23:22 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/19 17:23:22 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_hook(void *param)
{
	if (1 || param)
		exit(0);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fract *f;

	if (x < 0 || x > IMG_WIDTH || y < 0 || y > IMG_HEIGHT)
		return (0);
	f = (t_fract *)param;
	f->mouse_x = x;
	f->mouse_y = y;
	if (f->fract == &julia)
		Julia_Mandel(f);
	return (0);
}

int		mouse_press(int key, int x, int y, void *param)
{
	t_fract *f;

	f = (t_fract *)param;
	if (key == SCRL_UP || key == SCRL_DOWN)
	{
		if (f->scale > 0.2 || key == SCRL_UP)
			f->scale += key == SCRL_UP ? 0.1 : -0.1;
		Julia_Mandel(f);
	}
	return (0);
}

int		key_hook(int key, void *param)
{
	t_fract *f;

	f = (t_fract *)param;
	if (key == ESC)
	{
		exit(0);
	}
	if (key == PLUS || key == MINUS)
	{
		if (f->max_iter > 2 || key == PLUS)
			f->max_iter += key == PLUS ? 1 : -1;
		Julia_Mandel(f);
	}
	if (key == ARR_UP || key == ARR_DOWN)
	{
		if (f->scale > 0.2 || key == ARR_UP)
			f->scale += key == ARR_UP ? 0.1 : -0.1;
		Julia_Mandel(f);
	}
	return (0);
}
