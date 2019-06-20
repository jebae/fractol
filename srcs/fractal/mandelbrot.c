/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:39:32 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:39:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_mandelbrot(t_dispatcher *dispatcher)
{
	t_render_helper		render_helper;

	render_helper.z = dispatcher->coord_helper.entry_point;
	render_helper.c = &(render_helper.z);
	render_helper.delta = dispatcher->coord_helper.delta;
	render_helper.palette_type = dispatcher->palette_type;
	if (dispatcher->is_parallel == 1)
		parallel_render_mandelbrot(&(dispatcher->clkit),\
			&render_helper, &(dispatcher->marker));
	else
	{
		render_helper.iteration = &mandelbrot_iteration;
		render_fractal(&render_helper, &(dispatcher->marker));
	}
}
