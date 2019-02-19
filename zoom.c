
#include "fractol.h"

double	interpolation(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

void	zoom(t_fract *f)
{
	double	inter;
	double	m_x;
	double	m_y;

	inter = 1.0 / f->scale;
	m_x = f->re_min + f->mouse_x * f->re_fact;
	m_y = f->im_max - f->mouse_y * f->im_fact;
	f->re_min = interpolation(m_x, f->re_min, inter);
	f->im_min = interpolation(m_y, f->im_min, inter);
	f->re_max = interpolation(m_x, f->re_max, inter);
	f->im_max = interpolation(m_y, f->im_max, inter);
}
