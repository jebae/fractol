#include "fractol.h"

void		render_mandelbrot(float width, float height, t_marker *marker)
{
	render_fractal(width, height, NULL, marker);
}

// -0.8f, 0.256f