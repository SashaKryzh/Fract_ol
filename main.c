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

/*
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		fdf->filename);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	fdf->img_p = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
		&fdf->size_line, &fdf->endian);
	fdf->img = (t_cell **)ft_memalloc(sizeof(t_cell *) * fdf->h);
	if (fdf->w || fdf->h)
		fdf->segm = (IMG_WIDTH / 2) / (fdf->w > fdf->h ? fdf->w : fdf->h);
	mlx_hook(fdf->win_ptr, 2, 5, key_hook, (void *)fdf);
	mlx_loop(fdf->mlx_ptr);
*/

int		main(void)
{
	t_fract	*fract;

	return (0);
}
