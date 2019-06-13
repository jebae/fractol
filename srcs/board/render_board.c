#include "fractol.h"

void		render_board(t_dispatcher *dispatcher)
{
	render_usage(dispatcher->marker.p_mlx, dispatcher->marker.p_win);
	render_status(dispatcher);
}
