#include "fractol.h"

static void		change_palette(t_dispatcher *dispatcher,\
	int palette_type, t_palette (*f)(void))
{
	t_marker	*marker;

	if (dispatcher->palette_type == palette_type)
		return ;
	dispatcher->palette_type = palette_type;
	marker = &(dispatcher->marker);
    delete_color_scheme(marker->palette);
    *(marker->palette) = f();
	dispatcher->render(dispatcher);
}

void		event_palette_red(t_dispatcher *dispatcher)
{
	change_palette(dispatcher, PALETTE_R, &fractal_palette_red);
}

void		event_palette_green(t_dispatcher *dispatcher)
{
	change_palette(dispatcher, PALETTE_G, &fractal_palette_green);
}

void		event_palette_blue(t_dispatcher *dispatcher)
{
	change_palette(dispatcher, PALETTE_B, &fractal_palette_blue);
}
