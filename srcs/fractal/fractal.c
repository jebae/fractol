#include "fractol.h"

void			render_fractal(t_render_helper *render_helper,\
	t_marker *marker)
{
	int			i;
	float		entry_x;
	t_coord		win_coord;

	win_coord.y = 0;
	entry_x = render_helper->z->r;
	while (win_coord.y < HEIGHT)
	{
		win_coord.x = 0;
		render_helper->z->r = entry_x;
		while (win_coord.x < WIDTH)
		{
			i = render_helper->iteration(\
				*(render_helper->z), *(render_helper->c));
			if (i == MAX_ITERATION)
				marker->color = BLACK;
			else
				marker->color = BLUE - 1 * i;
			marker->mark_pixel(marker, &win_coord, NULL);
			win_coord.x++;
			render_helper->z->r += render_helper->delta;
		}
		win_coord.y++;
		render_helper->z->i += render_helper->delta;
	}
}
