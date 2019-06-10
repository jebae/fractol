int			mandelbrot_iteration(t_complex z, t_complex c)
{
	int			i;
	float		aa;
	float		bb;
	float		two_ab;

	i = 0;
	while (i < MAX_ITERATION)
	{
		aa = z.r * z.r;
		bb = z.i * z.i;
		two_ab = 2 * z.r * z.i;
		if (aa + bb > 4)
			return (get_color(aa + bb, i));
		z.r = aa - bb + c.r;
		z.i = two_ab + c.i;
		i++;
	}
	return (BLACK);
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
		aa = z.r * z.r;
		bb = z.i * z.i;
		two_ab = 2 * z.r * z.i;
		if (aa + bb > 4)
			return (get_color(aa + bb, i));
		z.r = ABS(aa - bb + c.r);
		z.i = ABS(two_ab) + c.i;
		i++;
	}
	return (BLACK);
}
