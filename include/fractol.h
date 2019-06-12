#ifndef FRACTOL_H
# define FRACTOL_H

# include "draw.h"
# include "clhelper.h"
# include <stdio.h> // remove after

# define FRACTOL_SUCCESS		1
# define FRACTOL_FAIL			-1

# define KEY_EVENT				2
# define MOUSE_EVENT			6
# define KEY_MASK				(1L << 0)
# define MOUSE_MASK				(1L << 6)

# define MOUSE_UP				4
# define MOUSE_DOWN				5
# define KEY_ESC				53
# define KEY_J					38
# define KEY_P					35
# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_R					15
# define KEY_G					5
# define KEY_B					11

# define MAX_ITERATION			100
# define ZOOM_SCALE				1.05

# define BLACK					0x000000
# define WHITE					0xFFFFFF
# define RED					0xFF0000
# define BLUE					0x0000FF
# define GREEN					0x00FF00

# define NUM_COLOR_CTRL_POINT	6

# define NUM_CL_KERNELS			3
# define NUM_CL_MEMS			2

# define MANDELBROT				0
# define JULIA					1
# define BURNING_SHIP			2

# define PALETTE_R				0
# define PALETTE_G				1
# define PALETTE_B				2

typedef struct		s_coord_helper
{
	double			width;
	double			height;
	double			delta;
	t_complex		entry_point;
}					t_coord_helper;

typedef struct		s_render_helper
{
	t_complex		z;
	t_complex		*c;
	double			delta;
	int				(*iteration)(t_complex, t_complex, t_palette *palette);
}					t_render_helper;

typedef struct		s_dispatcher
{
	int				is_parallel;
	int				julia_effect;
	int				palette_type;
	t_complex		c;
	t_coord_helper	coord_helper;
	t_clhelper		clhelper;
	t_marker		marker;
	void			(*render)(struct s_dispatcher *);
}					t_dispatcher;

/*
** init
*/
t_coord_helper		init_coord_helper();
void				init_mlx(t_dispatcher *dispatcher);

/*
** events
*/
int					event_mouse_move(int x, int y, void *param);
int					event_zoom(int key, int x, int y, void *param);
int					event_keypress(int keycode, void *param);
void				event_julia_effect(t_dispatcher *dispatcher);
void				event_parallel(t_dispatcher *dispatcher);
void				event_change_type(int keycode, t_dispatcher *dispatcher);
void				event_translate(int keycode, t_dispatcher *dispatcher);
void				event_palette_red(t_dispatcher *dispatcher);
void				event_palette_green(t_dispatcher *dispatcher);
void				event_palette_blue(t_dispatcher *dispatcher);
void				event_exit(t_dispatcher *dispatcher);

/*
** fractal
*/
void				render_fractal(t_render_helper *render_helper,\
	t_marker *marker);
void				render_mandelbrot(t_dispatcher *dispatcher);
void				render_julia(t_dispatcher *dispatcher);
void				render_burning_ship(t_dispatcher *dispatcher);

/*
** calc
*/
int					mandelbrot_iteration(t_complex z, t_complex c, t_palette *palette);
int					burning_ship_iteration(t_complex z, t_complex c, t_palette *palette);
int					get_color(t_palette *palette, double abs_value, int n);

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
int					enqueue_write_color_scheme(cl_command_queue cmd_queue,\
	cl_mem mem, t_color *color_scheme);
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
