/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_burning_ship.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:40:55 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:40:56 by jebae            ###   ########.fr       */
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
		sizeof(double), &(render_helper->delta)) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 3,\
		sizeof(int), &width) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	if (clk_set_kernel_arg(kernel, 4,\
		sizeof(int), &(render_helper->palette_type)) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

void			parallel_render_burning_ship(t_clkit *clkit,\
	t_render_helper *render_helper, t_marker *marker)
{
	if (set_kernel_arg(clkit->kernels[BURNING_SHIP],\
		&(clkit->mems[0]), render_helper) == FRACTOL_FAIL)
		return ;
	parallel_render(BURNING_SHIP, clkit, marker);
}
