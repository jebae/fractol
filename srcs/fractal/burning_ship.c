#include "fractol.h"

void		render_burning_ship(t_dispatcher *dispatcher)
{
	t_render_helper		render_helper;

	render_helper.z = dispatcher->coord_helper.entry_point;
	render_helper.c = &(render_helper.z);
	render_helper.delta = dispatcher->coord_helper.delta;
	if (dispatcher->is_parallel == 1)
		parallel_render_burning_ship(&(dispatcher->clhelper),\
			&render_helper, &(dispatcher->marker));
	else
	{
		render_helper.iteration = &burning_ship_iteration;
		render_fractal(&render_helper, &(dispatcher->marker));
	}
}
