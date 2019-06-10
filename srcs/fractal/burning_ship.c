#include "fractol.h"

void		render_burning_ship(t_coord_helper *coord_helper, t_clhelper *clhelper,\
	t_marker *marker)
{
	t_render_helper		render_helper;

	render_helper.z = coord_helper->entry_point;
	render_helper.c = &(render_helper.z);
	render_helper.delta = coord_helper->delta;
	if (clhelper == NULL)
	{
		render_helper.iteration = &burning_ship_iteration;
		render_fractal(&render_helper, marker);
	}
	else
		parallel_render_burning_ship(clhelper, &render_helper, marker);
}
