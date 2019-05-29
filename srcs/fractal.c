#include "fractol.h"

static int		iteration(t_complex z, t_complex *c)
{
	int			i;
	float		aa;
	float		bb;
	float		two_ab;

	i = 0;
	while (i < MAX_ITERATION)
	{
		aa = pow(z.r, 2);
		bb = pow(z.i, 2);
		two_ab = 2 * z.r * z.i;
		if (aa + bb > 4)
			return (i);
		z.r = aa - bb + c->r;
		z.i = two_ab + c->i;
		i++;
	}
	return (i);
}

void			render_fractal(float width, float height, t_complex *c, t_marker *marker)
{
	int			i;
	float		x_min;
	float		delta;
	t_complex	z;
	t_coord		win_coord;

	x_min = -1 * width / 2;
	z.i = -1 * height / 2;
	delta = width / WIDTH;
	win_coord.y = -1;
	while (win_coord.y++ < HEIGHT)
	{
		win_coord.x = -1;
		z.r = x_min;
		while (win_coord.x++ < WIDTH)
		{
			i = iteration(z, &z);
			if (i == MAX_ITERATION)
			{
				marker->color = BLACK;
				marker->mark_pixel(marker, &win_coord, NULL);
			}
			else
			{
				marker->color = WHITE - 1 * i;
				marker->mark_pixel(marker, &win_coord, NULL);
			}
			z.r += delta;
		}
		z.i += delta;
	}
}