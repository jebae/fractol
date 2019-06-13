__kernel void		julia(__global int *out, double2 entry,\
	double2 c, double delta, int width, int palette_type)
{
	int			idx = get_global_id(0);
	int			r = idx % width;
	int			i = idx / width;
	double2		z;

	z.x = entry.x + delta * r;
	z.y = entry.y + delta * i;
	out[idx] = mandelbrot_iteration(z, c, color_schemes[palette_type]);
}
