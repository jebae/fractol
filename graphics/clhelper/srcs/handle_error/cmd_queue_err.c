/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_queue_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:25 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_check_create_cmd_queue(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clCreateCommandQueue ");
	if (ret == CL_INVALID_CONTEXT)
		return (clh_print_err("invalid context\n"));
	else if (ret == CL_INVALID_DEVICE)
		return (clh_print_err("invalid device\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_INVALID_QUEUE_PROPERTIES)
		return (clh_print_err("invalud queue properties\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_enqueue_read_buffer(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clEnqueueReadBuffer ");
	if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clh_print_err("invalid command queue\n"));
	else if (ret == CL_INVALID_CONTEXT)
		return (clh_print_err("invalid context\n"));
	else if (ret == CL_INVALID_MEM_OBJECT)
		return (clh_print_err("invalid mem object\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_INVALID_EVENT_WAIT_LIST)
		return (clh_print_err("invalid event wait list\n"));
	else if (ret == CL_MEM_OBJECT_ALLOCATION_FAILURE)
		return (clh_print_err("mem object allocation failed\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

static int	clh_check_enqueue_ndrange_kernel2(cl_int ret)
{
	if (ret == CL_MEM_OBJECT_ALLOCATION_FAILURE)
		return (clh_print_err("mem object allocation failed\n"));
	else if (ret == CL_INVALID_EVENT_WAIT_LIST)
		return (clh_print_err("invalid event wait list\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_enqueue_ndrange_kernel(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clEnqueueNDRangeKernel ");
	if (ret == CL_INVALID_PROGRAM_EXECUTABLE)
		return (clh_print_err("invalid program executable\n"));
	else if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clh_print_err("invalid command queue\n"));
	else if (ret == CL_INVALID_KERNEL)
		return (clh_print_err("invalid kernel\n"));
	else if (ret == CL_INVALID_CONTEXT)
		return (clh_print_err("invalid context\n"));
	else if (ret == CL_INVALID_KERNEL_ARGS)
		return (clh_print_err("invalid kernel args\n"));
	else if (ret == CL_INVALID_WORK_DIMENSION)
		return (clh_print_err("invalid work dimension\n"));
	else if (ret == CL_INVALID_WORK_GROUP_SIZE)
		return (clh_print_err("invalid work group size\n"));
	else if (ret == CL_INVALID_WORK_ITEM_SIZE)
		return (clh_print_err("invalid work item size\n"));
	else if (ret == CL_INVALID_GLOBAL_OFFSET)
		return (clh_print_err("invalid global offset\n"));
	else if (ret == CL_OUT_OF_RESOURCES)
		return (clh_print_err("out of resources\n"));
	return (clh_check_enqueue_ndrange_kernel2(ret));
}

int			clh_check_flush(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clFlush ");
	if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clh_print_err("invalid command queue\n"));
	else if (ret == CL_OUT_OF_RESOURCES)
		return (clh_print_err("out of resources\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}
