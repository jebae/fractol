__kernel void		mandelbrot(__global int *out,\
	t_complex entry, float delta, int width)
{
	int			idx = get_global_id(0);
	int			r = idx % width;
	int			i = idx / width;
	t_complex	z;

	z.r = entry.r + delta * r;
	z.i = entry.i + delta * i;
	out[idx] = mandelbrot_iteration(z, z);
}
