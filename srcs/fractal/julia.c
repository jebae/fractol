#include "fractol.h"

void		render_julia(t_coord_helper *coord_helper, t_clhelper *clhelper,\
	t_marker *marker, t_complex *c)
{
	t_render_helper		render_helper;

	render_helper.z = coord_helper->entry_point;
	render_helper.c = c;
	render_helper.delta = coord_helper->delta;
	if (clhelper == NULL)
	{
		render_helper.iteration = &mandelbrot_iteration;
		render_fractal(&render_helper, marker);
	}
	else
		parallel_render_julia(clhelper, &render_helper, marker);
}
