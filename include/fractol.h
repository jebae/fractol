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

typedef struct		s_coord_helper
{
	float			width;
	float			height;
	float			delta;
	t_complex		entry_point;
}					t_coord_helper;

typedef struct		s_render_helper
{
	t_complex		*z;
	t_complex		*c;
	float			delta;
	int				(*iteration)(t_complex, t_complex);
}					t_render_helper;

/*
** init
*/
t_coord_helper		init_coord_helper();

/*
** fractal
*/
void				render_fractal(t_render_helper *render_helper,\
	t_marker *marker);
void				render_mandelbrot(t_complex z, float delta,\
	t_marker *marker);
void				render_julia(t_complex z, t_complex *c, float delta,\
	t_marker *marker);
void				render_burning_ship(t_complex z, float delta,\
	t_marker *marker);

/*
** calc
*/
int					mandelbrot_iteration(t_complex z, t_complex c);
int					burning_ship_iteration(t_complex z, t_complex c);

#endif
