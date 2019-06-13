#include "fractol.h"

static int		set_kernel_arg(cl_kernel kernel,\
	cl_mem *mem, t_render_helper *render_helper)
{
	static int		width = WIDTH;

	if (clh_set_kernel_arg(kernel, 0,\
		sizeof(cl_mem), &(mem[0])) == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_set_kernel_arg(kernel, 1,\
		sizeof(t_complex), &(render_helper->z)) == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_set_kernel_arg(kernel, 2,\
		sizeof(t_complex), render_helper->c) == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_set_kernel_arg(kernel, 3,\
		sizeof(double), &(render_helper->delta)) == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_set_kernel_arg(kernel, 4,\
		sizeof(int), &width) == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_set_kernel_arg(kernel, 5,\
		sizeof(int), &(render_helper->palette_type)) == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

void			parallel_render_julia(t_clhelper *clhelper,\
	t_render_helper *render_helper, t_marker *marker)
{
	if (set_kernel_arg(clhelper->kernels[JULIA],\
		clhelper->mems, render_helper) == FRACTOL_FAIL)
		return ;
	parallel_render(JULIA, clhelper, marker);
}
