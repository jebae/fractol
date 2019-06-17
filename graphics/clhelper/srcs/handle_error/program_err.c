/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:09 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_check_create_program(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clCreateProgramWithSource ");
	if (ret == CL_INVALID_CONTEXT)
		return (clh_print_err("invalid context\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_build_program(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clBuildProgram ");
	if (ret == CL_INVALID_PROGRAM)
		return (clh_print_err("invalid program\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_INVALID_DEVICE)
		return (clh_print_err("invalid device\n"));
	else if (ret == CL_INVALID_BINARY)
		return (clh_print_err("invalid binary\n"));
	else if (ret == CL_INVALID_BUILD_OPTIONS)
		return (clh_print_err("invalid build options\n"));
	else if (ret == CL_INVALID_OPERATION)
		return (clh_print_err("invalid operation\n"));
	else if (ret == CL_COMPILER_NOT_AVAILABLE)
		return (clh_print_err("compiler not available\n"));
	else if (ret == CL_BUILD_PROGRAM_FAILURE)
		return (clh_print_err("build program failed\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clh_print_err("out of host memory\n"));
	return (CLHELPER_SUCCESS);
}

int			clh_check_get_program_build_info(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clh_print_err("clGetProgramBuildInfo ");
	if (ret == CL_INVALID_DEVICE)
		return (clh_print_err("invalid device\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clh_print_err("invalid value\n"));
	else if (ret == CL_INVALID_PROGRAM)
		return (clh_print_err("invalid program\n"));
	return (CLHELPER_SUCCESS);
}
