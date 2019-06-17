/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_device.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:46 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:31:47 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

static int		allocate_devices(cl_device_id **devices,\
	cl_uint num_devices)
{
	*devices = (cl_device_id *)ft_memalloc(\
		sizeof(cl_device_id) * num_devices);
	if (*devices == NULL)
		return (clh_print_err("Allocating memory to devices failed\n"));
	return (CLHELPER_SUCCESS);
}

static int		set_gpu(t_clhelper *clhelper)
{
	cl_int		ret;

	clhelper->num_devices = 1;
	if (allocate_devices(&(clhelper->devices),\
		clhelper->num_devices) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ret = clGetDeviceIDs(clhelper->platform, CL_DEVICE_TYPE_GPU,\
		clhelper->num_devices, clhelper->devices, NULL);
	return (clh_check_get_device_ids(ret));
}

static int		set_cpu(t_clhelper *clhelper)
{
	cl_int		ret;

	clhelper->num_devices = 1;
	if (allocate_devices(&(clhelper->devices),\
		clhelper->num_devices) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ret = clGetDeviceIDs(clhelper->platform, CL_DEVICE_TYPE_CPU,\
		clhelper->num_devices, clhelper->devices, NULL);
	return (clh_check_get_device_ids(ret));
}

static int		set_all(t_clhelper *clhelper)
{
	cl_int		ret;

	ret = clGetDeviceIDs(clhelper->platform, CL_DEVICE_TYPE_ALL,\
		0, NULL, &(clhelper->num_devices));
	if (clh_check_get_device_ids(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	if (allocate_devices(&(clhelper->devices),\
		clhelper->num_devices) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ret = clGetDeviceIDs(clhelper->platform, CL_DEVICE_TYPE_ALL,\
		clhelper->num_devices, clhelper->devices, NULL);
	return (clh_check_get_device_ids(ret));
}

int				clh_set_device(t_clhelper *clhelper, cl_device_type type)
{
	cl_int			ret;

	ret = clGetPlatformIDs(1, &(clhelper->platform), NULL);
	if (clh_check_get_platform_ids(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	if (type == CL_DEVICE_TYPE_ALL)
		return (set_all(clhelper));
	else if (type == CL_DEVICE_TYPE_GPU)
		return (set_gpu(clhelper));
	else if (type == CL_DEVICE_TYPE_CPU)
		return (set_cpu(clhelper));
	return (clh_print_err("Wrong device type\n"));
}
