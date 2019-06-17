/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:38 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_create_program(cl_program *program, cl_context context,\
	char *src)
{
	cl_int		ret;

	*program = clCreateProgramWithSource(context, 1,\
		(const char **)&src, NULL, &ret);
	return (clh_check_create_program(ret));
}
