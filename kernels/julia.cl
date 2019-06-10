__kernel void		julia(__global int *out,\
	t_complex entry, t_complex c, float delta, int width)
{
	int			idx = get_global_id(0);
	int			r = idx % width;
	int			i = idx / width;
	t_complex	z;

	z.r = entry.r + delta * r;
	z.i = entry.i + delta * i;
	out[idx] = mandelbrot_iteration(z, c);
}
