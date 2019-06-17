/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_queue_err2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:37 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:37 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_check_finish(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clFinish ");
	if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clh_print_err("invalid command queue\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_enqueue_write_buffer(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clEnqueueWriteBuffer ");
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
