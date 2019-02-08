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

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	char			*img_p;
	int				bpp;
	int				size_line;
	int				endian;
}					t_fract;

# define ESC 53

#endif
