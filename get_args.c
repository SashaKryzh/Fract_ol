/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 09:43:28 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/15 09:43:28 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_args(t_fract *f, int ac, char *av[])
{
	if (ac == 2)
	{
		if (ft_strequ(av[1], "1"))
		{
			f->fract = &julia;
			f->filename = "Fract_ol - Julia";
		}
		else if (ft_strequ(av[1], "2"))
		{
			f->fract = &mandel;
			f->filename = "Fract_ol - Mandelbrot";
		}
	}
	if (f->fract)
		return ;
	ft_putstr("Usage: ./fractol [id]\n");
	ft_putstr("1 - Julia set\n");
	ft_putstr("2 - Mandelbrot set\n");
	exit(1);
}
