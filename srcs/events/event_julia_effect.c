#include "fractol.h"

void		event_julia_effect(t_dispatcher *dispatcher)
{
	dispatcher->julia_effect ^= 1;
}
