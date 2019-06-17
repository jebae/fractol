/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_change_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:38:28 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:38:29 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_if_different(t_dispatcher *dispatcher,\
	void (*render)(t_dispatcher *))
{
	if (dispatcher->render != render)
		dispatcher->render = render;
	return ;
}

void			event_change_type(int keycode, t_dispatcher *dispatcher)
{
	dispatcher->coord_helper = init_coord_helper();
	if (keycode == KEY_1)
		return (change_if_different(dispatcher, &render_mandelbrot));
	else if (keycode == KEY_2)
	{
		dispatcher->c = (t_complex){-0.8, 0.156};
		return (change_if_different(dispatcher, &render_julia));
	}
	else if (keycode == KEY_3)
		return (change_if_different(dispatcher, &render_burning_ship));
	return ;
}
