#include "fractol.h"

void		event_parallel(t_dispatcher *dispatcher)
{
	dispatcher->is_parallel ^= 1;
}
