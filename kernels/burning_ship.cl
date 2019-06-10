__kernel void		burning_ship(__global int *out,\
	t_complex entry, float delta, int width)
{
	int			idx = get_global_id(0);
	int			r = idx % width;
	int			i = idx / width;
	t_complex	z;

	z.r = entry.r + delta * r;
	z.i = entry.i + delta * i;
	out[idx] = burning_ship_iteration(z, z);
}
