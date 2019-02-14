/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:44:56 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/07 14:44:56 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"

# include "libft.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define IMG_WIDTH WIN_WIDTH
# define IMG_HEIGHT WIN_HEIGHT

# define IMGWIN_PAR fract->mlx_ptr, fract->win_ptr, fract->img_ptr

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	char			*img_p;
	int				bpp;
	int				size_line;
	int				endian;

	int				max_iter;
}					t_fract;

/*
**	Fractols
*/

void				Mandelbrot_set(t_fract *fract);

/*
**	Utils
*/

int					color_calc(int k);
void				pixel_fill(t_fract *fract, int x, int y, int color);

# define ESC 53

#endif
