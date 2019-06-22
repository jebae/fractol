/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clkit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:27:45 by jebae             #+#    #+#             */
/*   Updated: 2019/06/22 16:27:47 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			create_buffer(t_clkit *clkit)
{
	t_create_buffer_args		args;

	clkit->mems = (cl_mem *)ft_memalloc(\
		sizeof(cl_mem) * NUM_CL_MEMS);
	args.context = clkit->context;
	args.host_ptr = NULL;
	args.flags = CL_MEM_WRITE_ONLY;
	args.size = sizeof(int) * WIDTH * HEIGHT;
	return (clk_create_buffer(&(clkit->mems[0]), &args));
}

static int			create_kernels(t_clkit *clkit)
{
	clkit->kernels = (cl_kernel *)ft_memalloc(\
		sizeof(cl_kernel) * NUM_CL_KERNELS);
	if (clk_create_kernel(&(clkit->kernels[MANDELBROT]),\
		clkit->program, "mandelbrot") == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_create_kernel(&(clkit->kernels[JULIA]),\
		clkit->program, "julia") == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_create_kernel(&(clkit->kernels[BURNING_SHIP]),\
		clkit->program, "burning_ship") == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

static int			handle_fail(char *src)
{
	ft_memdel((void **)&src);
	return (FRACTOL_FAIL);
}

int					init_clkit(t_clkit *clkit,\
	char **kernel_srcs, size_t num_kernel_files)
{
	char			*src;

	src = NULL;
	if (clk_set_device(clkit, CL_DEVICE_TYPE_CPU) == CLKIT_FAIL)
		return (handle_fail(src));
	clk_get_device_info(clkit);
	if (clk_create_context(clkit) == CLKIT_FAIL)
		return (handle_fail(src));
	if (clk_create_cmd_queues(clkit) == CLKIT_FAIL)
		return (handle_fail(src));
	if (create_buffer(clkit) == CLKIT_FAIL)
		return (handle_fail(src));
	src = clk_concat_kernel_src(kernel_srcs, num_kernel_files);
	if (clk_create_program(&(clkit->program),\
		clkit->context, src) == CLKIT_FAIL)
		return (handle_fail(src));
	if (clk_build_program(clkit->program,\
		&(clkit->devices[0])) == CLKIT_FAIL)
		return (handle_fail(src));
	if (create_kernels(clkit) == FRACTOL_FAIL)
		return (handle_fail(src));
	ft_memdel((void **)&src);
	return (FRACTOL_SUCCESS);
}
