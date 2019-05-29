#include "fractol.h"

void		init_width_height(float *width, float *height)
{
	*width = 5;
	*height = (*width * HEIGHT) / WIDTH;
}