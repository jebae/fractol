/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_device_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:32:30 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:32:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

static int		get_info(cl_device_id device,\
	cl_device_info param_name)
{
	cl_int		ret;
	size_t		value_size;
	char		value[100];

	ret = clGetDeviceInfo(device, param_name, 0, NULL, &value_size);
	if (clh_check_get_device_info(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ret = clGetDeviceInfo(device, param_name, value_size, value, NULL);
	if (clh_check_get_device_info(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	put_color_str(KYEL, value);
	ft_putstr("\n");
	return (CLHELPER_SUCCESS);
}

static int		get_compute_units(cl_device_id device)
{
	cl_int		ret;
	cl_uint		compute_units;

	ret = clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS,\
		sizeof(compute_units), &compute_units, NULL);
	if (clh_check_get_device_info(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ft_putstr(KYEL);
	ft_putnbr((int)compute_units);
	ft_putstr("\n");
	ft_putstr(KNRM);
	return (CLHELPER_SUCCESS);
}

static int		get_max_work_group_size(cl_device_id device)
{
	cl_int		ret;
	size_t		max_size;

	ret = clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_GROUP_SIZE,\
		sizeof(max_size), &max_size, NULL);
	if (clh_check_get_device_info(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ft_putstr(KYEL);
	ft_putnbr((int)max_size);
	ft_putstr("\n");
	ft_putstr(KNRM);
	return (CLHELPER_SUCCESS);
}

int				clh_get_device_info(t_clhelper *clhelper)
{
	cl_uint		i;

	i = 0;
	while (i < clhelper->num_devices)
	{
		put_color_str(KGRN, "Device ");
		ft_putnbr((int)i);
		ft_putstr("\n");
		put_color_str(KGRN, "Name ");
		get_info(clhelper->devices[i], CL_DEVICE_NAME);
		put_color_str(KGRN, "Device Version ");
		get_info(clhelper->devices[i], CL_DEVICE_VERSION);
		put_color_str(KGRN, "Driver Version ");
		get_info(clhelper->devices[i], CL_DRIVER_VERSION);
		put_color_str(KGRN, "OpenCL C Version ");
		get_info(clhelper->devices[i], CL_DEVICE_OPENCL_C_VERSION);
		put_color_str(KGRN, "Compute Units ");
		get_compute_units(clhelper->devices[i]);
		put_color_str(KGRN, "Max Work Group Size ");
		get_max_work_group_size(clhelper->devices[i]);
		i++;
		if (i != clhelper->num_devices)
			ft_putstr("\n");
	}
	return (CLHELPER_SUCCESS);
}
