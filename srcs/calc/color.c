#include "fractol.h"

static float		get_mu(float abs_value, int n)
{
	return ((n + 2 - log2(log(abs_value))) / MAX_ITERATION);
}

float				get_color(t_palette *palette, float abs_value, int n)
{
	float		mu;

	mu = get_mu(abs_value, n);
	return (pick_color(palette, mu));
}
