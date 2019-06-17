/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:32:10 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:32:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

static void		release_kernels(cl_kernel *kernels, cl_uint num_kernels)
{
	cl_int		ret;
	cl_uint		i;

	i = 0;
	while (i < num_kernels)
	{
		ret = clReleaseKernel(kernels[i]);
		clh_check_release_kernel(ret);
		i++;
	}
}

static void		release_mems(cl_mem *mems, cl_uint num_mems)
{
	cl_int		ret;
	cl_uint		i;

	i = 0;
	while (i < num_mems)
	{
		ret = clReleaseMemObject(mems[i]);
		clh_check_release_mem_object(ret);
		i++;
	}
}

static void		release_cmd_queues(cl_command_queue *cmd_queues,\
	cl_uint num_devices)
{
	cl_int		ret;
	cl_uint		i;

	i = 0;
	while (i < num_devices)
	{
		ret = clReleaseCommandQueue(cmd_queues[i]);
		clh_check_release_cmd_queue(ret);
		i++;
	}
}

void			clh_release_all(t_clhelper *clhelper,\
	cl_uint num_kernels, cl_uint num_mems)
{
	cl_int		ret;

	release_kernels(clhelper->kernels, num_kernels);
	ret = clReleaseProgram(clhelper->program);
	clh_check_release_program(ret);
	release_mems(clhelper->mems, num_mems);
	release_cmd_queues(clhelper->cmd_queues, clhelper->num_devices);
	ret = clReleaseContext(clhelper->context);
	clh_check_release_context(ret);
}

void			clh_free_all(t_clhelper *clhelper)
{
	ft_memdel((void **)(&clhelper->devices));
	ft_memdel((void **)(&clhelper->cmd_queues));
	ft_memdel((void **)(&clhelper->mems));
	ft_memdel((void **)(&clhelper->kernels));
}
