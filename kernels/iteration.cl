int			mandelbrot_iteration(double2 z, double2 c,\
	__constant uchar3 *color_scheme)
{
	int			i;
	double		aa;
	double		bb;
	double		two_ab;

	i = 0;
	while (i < MAX_ITERATION)
	{
		aa = z.x * z.x;
		bb = z.y * z.y;
		two_ab = 2 * z.x * z.y;
		if (aa + bb > 4)
			return (get_color(aa + bb, i, color_scheme));
		z.x = aa - bb + c.x;
		z.y = two_ab + c.y;
		i++;
	}
	return (BLACK);
}

int			burning_ship_iteration(double2 z, double2 c,\
	__constant uchar3 *color_scheme)
{
	int			i;
	double		aa;
	double		bb;
	double		two_ab;

	i = 0;
	while (i < MAX_ITERATION)
	{
		aa = z.x * z.x;
		bb = z.y * z.y;
		two_ab = 2 * z.x * z.y;
		if (aa + bb > 4)
			return (get_color(aa + bb, i, color_scheme));
		z.x = ABS(aa - bb + c.x);
		z.y = ABS(two_ab) + c.y;
		i++;
	}
	return (BLACK);
}
