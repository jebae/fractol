/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:13 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_check_release_kernel(cl_int ret)
{
	if (ret == CL_INVALID_KERNEL)
		return (clh_print_err("clReleaseKernel invalid kernel\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_release_program(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clReleaseProgram ");
	if (ret == CL_INVALID_PROGRAM)
		return (clh_print_err("invalid program\n"));
	else if (ret == CL_OUT_OF_RESOURCES)
		return (clh_print_err("out of resources\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_release_mem_object(cl_int ret)
{
	if (ret == CL_INVALID_MEM_OBJECT)
		return (clh_print_err("clReleaseMemObject invalid mem object\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_release_cmd_queue(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clReleaseCommandQueue ");
	if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clh_print_err("invalid command queue\n"));
	else if (ret == CL_OUT_OF_RESOURCES)
		return (clh_print_err("out of resources\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_release_context(cl_int ret)
{
	if (ret == CL_INVALID_CONTEXT)
		return (clh_print_err("clReleaseContext invalid context\n"));
	return (CLHELPER_SUCCESS);
}
