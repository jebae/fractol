__kernel void		burning_ship(__global int *out,\
	double2 entry, double delta, int width, int palette_type)
{
	int			idx = get_global_id(0);
	int			r = idx % width;
	int			i = idx / width;
	double2		z;

	z.x = entry.x + delta * r;
	z.y = entry.y + delta * i;
	out[idx] = burning_ship_iteration(z, z, color_schemes[palette_type]);
}
