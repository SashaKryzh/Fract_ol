/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:26:22 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/14 10:26:22 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_calc(int k)
{
	int		c;
	char	*n;

	n = (char *)&c;
	if (k > 20)
		return (16711680);
	return (2147483647);
}

void	pixel_fill(t_fract *f, int x, int y, int color)
{
	int		where;
	uint8_t *what;
	int		i;

	if (x >= IMG_WIDTH || y >= IMG_HEIGHT)
		return ;
	where = y * f->size_line + x * f->bpp / 8;
	what = (uint8_t *)&color;
	i = 0;
	while (i < 4)
	{
		f->img_p[where + i] = what[i];
		i++;
	}
}
