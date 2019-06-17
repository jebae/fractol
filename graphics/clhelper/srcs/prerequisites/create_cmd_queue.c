/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:58 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:31:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

static int		allocate_cmd_queues(cl_command_queue **cmd_queues,\
	cl_uint num_devices)
{
	*cmd_queues = (cl_command_queue *)ft_memalloc(\
		sizeof(cl_command_queue) * num_devices);
	if (*cmd_queues == NULL)
		return (clh_print_err("Allocating memory to cmd_queues failed\n"));
	return (CLHELPER_SUCCESS);
}

int				clh_create_cmd_queues(t_clhelper *clhelper)
{
	cl_uint		i;
	cl_int		ret;

	if (allocate_cmd_queues(&(clhelper->cmd_queues),\
		clhelper->num_devices) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	i = 0;
	while (i < clhelper->num_devices)
	{
		clhelper->cmd_queues[i] = clCreateCommandQueue(\
			clhelper->context, clhelper->devices[i], 0, &ret);
		if (clh_check_create_cmd_queue(ret) == CLHELPER_FAIL)
			return (CLHELPER_FAIL);
		i++;
	}
	return (CLHELPER_SUCCESS);
}
