#include "fractol.h"

void		render_julia(t_dispatcher *dispatcher)
{
	t_render_helper		render_helper;

	render_helper.z = dispatcher->coord_helper.entry_point;
	render_helper.c = &(dispatcher->c);
	render_helper.delta = dispatcher->coord_helper.delta;
	if (dispatcher->is_parallel == 1)
		parallel_render_julia(&(dispatcher->clhelper),\
			&render_helper, &(dispatcher->marker));
	else
	{
		render_helper.iteration = &mandelbrot_iteration;
		render_fractal(&render_helper, &(dispatcher->marker));
	}
}
