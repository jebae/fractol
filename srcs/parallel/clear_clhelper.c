#include "fractol.h"

void		clear_clhelper(t_clhelper *clhelper)
{
	clh_release_all(clhelper, NUM_CL_KERNELS, NUM_CL_MEMS);
	clh_free_all(clhelper);
}
