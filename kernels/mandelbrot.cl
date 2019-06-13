__kernel void		mandelbrot(__global int *out,\
	double2 entry, double delta, int width, int palette_type)
{
	int			idx = get_global_id(0);
	int			r = idx % width;
	int			i = idx / width;
	double2		z;

	z.x = entry.x + delta * r;
	z.y = entry.y + delta * i;
	out[idx] = mandelbrot_iteration(z, z, color_schemes[palette_type]);
}
