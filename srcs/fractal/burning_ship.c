#include "fractol.h"

void				render_burning_ship(t_complex z, float delta,\
	t_marker *marker)
{
	t_render_helper		render_helper;

	render_helper.z = &z;
	render_helper.c = &z;
	render_helper.delta = delta;
	render_helper.iteration = &burning_ship_iteration;
	render_fractal(&render_helper, marker);
}
