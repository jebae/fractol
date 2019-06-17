/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:49 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:31:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_create_context(t_clhelper *clhelper)
{
	cl_int		ret;

	clhelper->context = clCreateContext(NULL, clhelper->num_devices,\
		clhelper->devices, NULL, NULL, &ret);
	return (clh_check_create_context(ret));
}
