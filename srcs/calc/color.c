#include "fractol.h"

static double		get_mu(double abs_value, int n)
{
	return ((n + 2 - log2(log(abs_value))) / MAX_ITERATION);
}

int					get_color(t_palette *palette, double abs_value, int n)
{
	double		mu;

	mu = get_mu(abs_value, n);
	return (pick_color(palette, mu));
}
