#ifndef FRACTOL_H
# define FRACTOL_H

# include "draw.h"
# include <stdio.h> // remove after

# define MAX_ITERATION	100
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define BLUE			0x0000FF
# define GREEN			0x00FF00

/*
** utils
*/
void		init_width_height(float *width, float *height);

/*
** fractal
*/
void		render_fractal(float width, float height, t_complex *c, t_marker *marker);

/*
** mandelbrot
*/
void		render_mandelbrot(float width, float height, t_marker *marker);

#endif