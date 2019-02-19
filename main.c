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

void	init_win(t_fract *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		fract->filename);
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	fract->img_p = mlx_get_data_addr(fract->img_ptr,
		&fract->bpp, &fract->size_line, &fract->endian);
}

void	magic(t_fract *fract)
{
	fract->max_iter = 100;
	fract->scale = 1.0;
	Julia_Mandel(fract);
	mlx_hook(fract->win_ptr, 2, 5, key_hook, (void *)fract);
	mlx_hook(fract->win_ptr, 6, 5, mouse_move, (void *)fract);
	mlx_hook(fract->win_ptr, 17, 5, close_hook, (void *)fract);
	mlx_loop(fract->mlx_ptr);
}

int		main(int ac, char *av[])
{
	t_fract	fract;

	ft_bzero(&fract, sizeof(fract));
	get_args(&fract, ac, av);
	init_win(&fract);
	magic(&fract);
	return (0);
}
