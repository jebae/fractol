/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:41 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_check_create_context(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clCreateContext ");
	if (ret == CL_INVALID_PLATFORM)
		return (clh_print_err("invalid platform\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_INVALID_DEVICE)
		return (clh_print_err("invalid device\n"));
	else if (ret == CL_DEVICE_NOT_AVAILABLE)
		return (clh_print_err("device not available\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}
