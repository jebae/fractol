/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:20 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_build_program(cl_program program, cl_device_id *device)
{
	cl_int		ret;

	ret = clBuildProgram(program, 1, device, NULL, NULL, NULL);
	if (clh_check_build_program(ret) == CLHELPER_SUCCESS)
		return (CLHELPER_SUCCESS);
	clh_get_program_build_info(program, *device);
	return (CLHELPER_FAIL);
}
