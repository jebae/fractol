#include "fractol.h"

static void			init_width_height(double *width, double *height)
{
	*width = 5;
	*height = (*width * HEIGHT) / WIDTH;
}

static t_complex	init_entry_point(double width, double height)
{
	t_complex	p;

	p.r = -1 * width / 2;
	p.i = -1 * height / 2;
	return (p);
}

static double		init_delta(double width)
{
	return (width / WIDTH);
}

t_coord_helper		init_coord_helper()
{
	t_coord_helper		coord_helper;

	init_width_height(&(coord_helper.width), &(coord_helper.height));
	coord_helper.entry_point = init_entry_point(\
		coord_helper.width, coord_helper.height);
	coord_helper.delta = init_delta(coord_helper.width);
	return (coord_helper);
}

void				init_mlx(t_dispatcher *dispatcher)
{
	t_marker	*marker;

	marker = &(dispatcher->marker);
    marker->p_mlx = mlx_init();
    marker->p_win = mlx_new_window(marker->p_mlx, WIDTH, HEIGHT, "fractol");
    marker->p_img = mlx_new_image(marker->p_mlx, WIDTH, HEIGHT);
	dispatcher->palette_type = PALETTE_B;
	marker->palette = (t_palette *)ft_memalloc(sizeof(t_palette));
    *(marker->palette) = fractal_palette_blue();
	mlx_hook(marker->p_win, MOUSE_EVENT, MOUSE_MASK,\
		&event_mouse_move, (void *)dispatcher);
	mlx_key_hook(marker->p_win, &event_keypress, dispatcher);
	mlx_mouse_hook(marker->p_win, &event_zoom, dispatcher);
}
