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

# include "math.h"
# include "mlx.h"

# include "libft.h"

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

#endif
