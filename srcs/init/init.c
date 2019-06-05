#include "fractol.h"

static void			init_width_height(float *width, float *height)
{
	*width = 5;
	*height = (*width * HEIGHT) / WIDTH;
}

static t_complex	init_entry_point(float width, float height)
{
	t_complex	p;

	p.r = -1 * width / 2;
	p.i = -1 * height / 2;
	return (p);
}

static float		init_delta(float width)
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
