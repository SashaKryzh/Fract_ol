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

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1200
# define IMG_WIDTH WIN_WIDTH
# define IMG_HEIGHT WIN_HEIGHT

# define IMGWIN_PARAMS f->mlx_ptr, f->win_ptr, f->img_ptr

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	char			*img_p;
	int				bpp;
	int				size_line;
	int				endian;

	int				(*fract)();
	int				max_iter;
	double			scale;

	int				mouse_x;
	int				mouse_y;

	int				x_res;
	int				y_res;
	float			re_min;
	float			re_max;
	float			im_min;
	float			im_max;
	double			re_fact;
	double			im_fact;

	char			*filename;
}					t_fract;

void				get_args(t_fract *f, int ac, char *av[]);

/*
**	Fractols
*/

void				Julia_Mandel(t_fract *fract);
int					julia(t_fract *f, double zx, double zy);
int					mandel(t_fract *f, double x0, double y0);

void				zoom(t_fract *f);

/*
**	Utils
*/

int					color_calc(int k);
void				pixel_fill(t_fract *fract, int x, int y, int color);

/*
**	Hooks
*/

int					key_hook(int key, void *param);
int					mouse_press(int key, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
int					close_hook(void *param);

# define ESC 53
# define PLUS 24
# define MINUS 27
# define ARR_UP 126
# define ARR_DOWN 125

#define LEFT_B 1
#define SCRL_UP 4
#define SCRL_DOWN 5

#endif
