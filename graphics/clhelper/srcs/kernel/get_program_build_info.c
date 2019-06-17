/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program_build_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:41 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_get_program_build_info(cl_program program,\
	cl_device_id device)
{
	cl_int		ret;
	size_t		value_size;
	char		*log;

	ret = clGetProgramBuildInfo(program, device,\
		CL_PROGRAM_BUILD_LOG, 0, NULL, &value_size);
	if (clh_check_get_program_build_info(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	ret = clGetProgramBuildInfo(program, device,\
		CL_PROGRAM_BUILD_LOG, 0, NULL, &value_size);
	if (clh_check_get_program_build_info(ret) == CLHELPER_FAIL)
		return (CLHELPER_FAIL);
	log = (char *)ft_memalloc(sizeof(char) * value_size);
	ret = clGetProgramBuildInfo(program, device,\
		CL_PROGRAM_BUILD_LOG, value_size, log, NULL);
	if (ft_strlen(log) > 0)
		clh_print_err(log);
	ft_memdel((void **)&log);
	return (clh_check_get_program_build_info(ret));
}
