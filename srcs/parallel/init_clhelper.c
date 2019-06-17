#include "fractol.h"

static int			create_buffer(t_clhelper *clhelper)
{
	t_create_buffer_args		args;

	clhelper->mems = (cl_mem *)ft_memalloc(\
		sizeof(cl_mem) * NUM_CL_MEMS);
	args.context = clhelper->context;
	args.host_ptr = NULL;
	args.flags = CL_MEM_WRITE_ONLY;
	args.size = sizeof(int) * WIDTH * HEIGHT;
	return (clh_create_buffer(&(clhelper->mems[0]), &args));
}

static int			create_kernels(t_clhelper *clhelper)
{
	clhelper->kernels = (cl_kernel *)ft_memalloc(\
		sizeof(cl_kernel) * NUM_CL_KERNELS);
	if (clh_create_kernel(&(clhelper->kernels[MANDELBROT]),\
		clhelper->program, "mandelbrot") == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_create_kernel(&(clhelper->kernels[JULIA]),\
		clhelper->program, "julia") == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	if (clh_create_kernel(&(clhelper->kernels[BURNING_SHIP]),\
		clhelper->program, "burning_ship") == CLHELPER_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

static int			handle_fail(char *src)
{
	ft_memdel((void **)&src);
	return (FRACTOL_FAIL);
}

int					init_clhelper(t_clhelper *clhelper,\
	char **kernel_srcs, size_t num_kernel_files)
{
	char			*src;

	src = NULL;
	if (clh_set_device(clhelper, CL_DEVICE_TYPE_GPU) == CLHELPER_FAIL)
		return (handle_fail(src));
	clh_get_device_info(clhelper);
	if (clh_create_context(clhelper) == CLHELPER_FAIL)
		return (handle_fail(src));
	if (clh_create_cmd_queues(clhelper) == CLHELPER_FAIL)
		return (handle_fail(src));
	if (create_buffer(clhelper) == CLHELPER_FAIL)
		return (handle_fail(src));
	src = clh_concat_kernel_src(kernel_srcs, num_kernel_files);
	if (clh_create_program(&(clhelper->program),\
		clhelper->context, src) == CLHELPER_FAIL)
		return (handle_fail(src));
	if (clh_build_program(clhelper->program,\
		&(clhelper->devices[0])) == CLHELPER_FAIL)
		return (handle_fail(src));
	if (create_kernels(clhelper) == FRACTOL_FAIL)
		return (handle_fail(src));
	ft_memdel((void **)&src);
	return (FRACTOL_SUCCESS);
}
