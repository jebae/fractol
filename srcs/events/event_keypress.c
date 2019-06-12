#include "fractol.h"

int		event_keypress(int keycode, void *param)
{
	t_dispatcher	*dispatcher;

	dispatcher = (t_dispatcher *)param;
	if (keycode == KEY_ESC)
		event_exit(dispatcher);
	else if (keycode == KEY_J)
		event_julia_effect(dispatcher);
	else if (keycode >= KEY_1 && keycode <= KEY_3)
		event_change_type(keycode, dispatcher);
	else if (keycode == KEY_P)
		event_parallel(dispatcher);
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		event_translate(keycode, dispatcher);
	else if (keycode == KEY_R)
		event_palette_red(dispatcher);
	else if (keycode == KEY_G)
		event_palette_green(dispatcher);
	else if (keycode == KEY_B)
		event_palette_blue(dispatcher);
	return (0);
}
