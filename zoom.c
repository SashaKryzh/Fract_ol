
#include "fractol.h"

double	interpolation(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

void	zoom(t_fract *f)
{
	double inter;

	inter = 1.0 / f->scale;
	f->re_min = interpolation(-2, f->re_min, inter);
	f->im_min = interpolation(0, f->im_min, inter);
	f->re_max = interpolation(-2, f->re_max, inter);
	f->im_max = interpolation(0, f->im_max, inter);
}
