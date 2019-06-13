#include "fractol.h"

static void		event_translate_left(t_dispatcher *dispatcher)
{
	t_coord_helper	*coord_helper;

	coord_helper = &(dispatcher->coord_helper);
	coord_helper->entry_point.r -= coord_helper->delta * 10;
}

static void		event_translate_right(t_dispatcher *dispatcher)
{
	t_coord_helper	*coord_helper;

	coord_helper = &(dispatcher->coord_helper);
	coord_helper->entry_point.r += coord_helper->delta * 10;
}

static void		event_translate_up(t_dispatcher *dispatcher)
{
	t_coord_helper	*coord_helper;

	coord_helper = &(dispatcher->coord_helper);
	coord_helper->entry_point.i -= coord_helper->delta * 10;
}

static void		event_translate_down(t_dispatcher *dispatcher)
{
	t_coord_helper	*coord_helper;

	coord_helper = &(dispatcher->coord_helper);
	coord_helper->entry_point.i += coord_helper->delta * 10;
}

void			event_translate(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_LEFT)
		event_translate_left(dispatcher);
	else if (keycode == KEY_RIGHT)
		event_translate_right(dispatcher);
	else if (keycode == KEY_UP)
		event_translate_up(dispatcher);
	else if (keycode == KEY_DOWN)
		event_translate_down(dispatcher);
	return ;
}
