/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:41:00 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:41:01 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		set_kernel_arg(cl_kernel kernel,\
	cl_mem *mem, t_render_helper *render_helper)
{
	static int		width = WIDTH;

	if (clk_set_kernel_arg(kernel, 0,\
		sizeof(cl_mem), &(mem[0])) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 1,\
		sizeof(t_complex), &(render_helper->z)) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 2,\
		sizeof(t_complex), render_helper->c) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 3,\
		sizeof(double), &(render_helper->delta)) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 4,\
		sizeof(int), &width) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 5,\
		sizeof(int), &(render_helper->palette_type)) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

void			parallel_render_julia(t_clkit *clkit,\
	t_render_helper *render_helper, t_marker *marker)
{
	if (set_kernel_arg(clkit->kernels[JULIA],\
		clkit->mems, render_helper) == FRACTOL_FAIL)
		return ;
	parallel_render(JULIA, clkit, marker);
}
