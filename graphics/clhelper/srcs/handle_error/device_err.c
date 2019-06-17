/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:46 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:46 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_check_get_device_ids(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clGetDeviceIDs ");
	if (ret == CL_INVALID_PLATFORM)
		return (clh_print_err("invalid platform\n"));
	else if (ret == CL_INVALID_DEVICE_TYPE)
		return (clh_print_err("invalid device type\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_DEVICE_NOT_FOUND)
		return (clh_print_err("device not found\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_get_device_info(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clGetDeviceInfo ");
	if (ret == CL_INVALID_DEVICE)
		return (clh_print_err("invalid device\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	return (CLHELPER_SUCCESS);
}
