#include "fractol.h"

void		render_julia(t_complex z, t_complex *c, float delta,\
	t_marker *marker)
{
	t_render_helper		render_helper;

	render_helper.z = &z;
	render_helper.c = c;
	render_helper.delta = delta;
	render_helper.iteration = &mandelbrot_iteration;
	render_fractal(&render_helper, marker);
}
