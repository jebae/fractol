#include "fractol.h"

static void		render_fractal_type_status(void *p_mlx, void *p_win,\
	void (*render_type)(t_dispatcher *))
{
	mlx_string_put(p_mlx, p_win, 5, 260, SKYBLUE, "Type");
	if (render_type == &render_mandelbrot)
		mlx_string_put(p_mlx, p_win, 90, 260, RED, "Mandelbrot");
	else if (render_type == &render_julia)
		mlx_string_put(p_mlx, p_win, 90, 260, RED, "Julia");
	else if (render_type == &render_burning_ship)
		mlx_string_put(p_mlx, p_win, 90, 260, RED, "Burning ship");
}

static void		render_palette_type_status(t_marker *marker)
{
	static t_coord		offset = (t_coord){90, 295};

	mlx_string_put(marker->p_mlx, marker->p_win, 5, 290, SKYBLUE, "Color");
	render_color_scheme(marker, &offset);
}

static void		render_parallel_status(void *p_mlx, void *p_win,\
	int is_parallel)
{
	mlx_string_put(p_mlx, p_win, 5, 320, SKYBLUE, "Parallel");
	if (is_parallel)
		mlx_string_put(p_mlx, p_win, 90, 320, RED, "ON");
	else
		mlx_string_put(p_mlx, p_win, 90, 320, RED, "OFF");
}

static void		render_julia_effect_status(void *p_mlx, void *p_win,\
	int julia_effect)
{
	mlx_string_put(p_mlx, p_win, 5, 350, SKYBLUE, "Julia");
	if (julia_effect)
		mlx_string_put(p_mlx, p_win, 90, 350, RED, "ON");
	else
		mlx_string_put(p_mlx, p_win, 90, 350, RED, "OFF");
}

void			render_status(t_dispatcher *dispatcher)
{
	void		*p_mlx;
	void		*p_win;

	p_mlx = dispatcher->marker.p_mlx;
	p_win = dispatcher->marker.p_win;
	render_fractal_type_status(p_mlx, p_win, dispatcher->render);
	render_palette_type_status(&(dispatcher->marker));
	render_parallel_status(p_mlx, p_win, dispatcher->is_parallel);
	render_julia_effect_status(p_mlx, p_win, dispatcher->julia_effect);
}
