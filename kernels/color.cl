float		get_mu(float abs_value, int n)
{
	return ((n + 2 - log2(log(abs_value))) / MAX_ITERATION);
}

int			calc_rgb(float mu, int i, int j)
{
	int			color = 0;
	float		alpha;

	alpha = (mu - color_ctrl_point[i]) /\
		(color_ctrl_point[j] - color_ctrl_point[i]);
	color += (int)(color_scheme[i].x +\
		(color_scheme[j].x - color_scheme[i].x) * alpha);
	color <<= 8;
	color += (int)(color_scheme[i].y +\
		(color_scheme[j].y - color_scheme[i].y) * alpha);
	color <<= 8;
	color += (int)(color_scheme[i].z +\
		(color_scheme[j].z - color_scheme[i].z) * alpha);
	return (color);
}

int			get_color(float abs_value, int n)
{
	int		i;
	float	mu = get_mu(abs_value, n);

	i = 0;
	while (i < NUM_COLOR_CTRL_POINT)
	{
		if (mu >= color_ctrl_point[i] && mu < color_ctrl_point[i + 1])
			return (calc_rgb(mu, i, i + 1));
		i++;
	}
	return (BLACK);
}
