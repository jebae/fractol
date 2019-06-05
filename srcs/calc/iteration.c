#include "fractol.h"

int			mandelbrot_iteration(t_complex z, t_complex c)
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
		z.r = aa - bb + c.r;
		z.i = two_ab + c.i;
		i++;
	}
	return (i);
}

int			burning_ship_iteration(t_complex z, t_complex c)
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
		z.r = ABS(aa - bb + c.r);
		z.i = ABS(two_ab) + c.i;
		i++;
	}
	return (i);
}
