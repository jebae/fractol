#ifndef FRACTOL_H
# define FRACTOL_H

# include "draw.h"
# include "clhelper.h"
# include <stdio.h> // remove after

# define FRACTOL_SUCCESS		1
# define FRACTOL_FAIL			-1

# define MAX_ITERATION			100

# define BLACK					0x000000
# define WHITE					0xFFFFFF
# define RED					0xFF0000
# define BLUE					0x0000FF
# define GREEN					0x00FF00

# define NUM_COLOR_CTRL_POINT	6

# define NUM_CL_KERNELS			3
# define NUM_CL_MEMS			1

# define KERNEL_MANDELBROT		0
# define KERNEL_JULIA			1
# define KERNEL_BURNING_SHIP	2

typedef struct		s_coord_helper
{
	float			width;
	float			height;
	float			delta;
	t_complex		entry_point;
}					t_coord_helper;

typedef struct		s_render_helper
{
	t_complex		z;
	t_complex		*c;
	float			delta;
	int				(*iteration)(t_complex, t_complex, t_palette *palette);
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
void				render_mandelbrot(t_coord_helper *coord_helper, t_clhelper *clhelper,\
	t_marker *marker);
void				render_julia(t_coord_helper *coord_helper, t_clhelper *clhelper,\
	t_marker *marker, t_complex *c);
void				render_burning_ship(t_coord_helper *coord_helper, t_clhelper *clhelper,\
	t_marker *marker);

/*
** calc
*/
int					mandelbrot_iteration(t_complex z, t_complex c, t_palette *palette);
int					burning_ship_iteration(t_complex z, t_complex c, t_palette *palette);
float				get_color(t_palette *palette, float abs_value, int n);

/*
** parallel
*/
int					init_clhelper(t_clhelper *clhelper,\
	char **kernel_srcs, size_t num_kernel_files);
void				clear_clhelper(t_clhelper *clhelper);
int					enqueue_ndrange_kernel(\
	cl_command_queue cmd_queue, cl_kernel kernel);
int					enqueue_read_buffer(cl_command_queue cmd_queue,\
	cl_mem mem, int *host_buf);
void				parallel_render(int fractal_name, t_clhelper *clhelper,\
	t_render_helper *render_helper, t_marker *marker);
void				parallel_render_mandelbrot(t_clhelper *clhelper,\
	t_render_helper *render_helper, t_marker *marker);
void				parallel_render_julia(t_clhelper *clhelper,\
	t_render_helper *render_helper, t_marker *marker);
void				parallel_render_burning_ship(t_clhelper *clhelper,\
	t_render_helper *render_helper, t_marker *marker);

/*
** utils
*/
char				*get_img_buffer(void *p_img);

#endif
