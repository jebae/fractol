/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:38:54 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:38:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			event_zoom(int key, int x, int y, void *param)
{
	t_dispatcher				*dispatcher;
	t_coord_helper				*coord_helper;
	t_complex_coord_zoom_args	args;

	dispatcher = (t_dispatcher *)param;
	coord_helper = &(dispatcher->coord_helper);
	if (key == MOUSE_DOWN)
		args.zoom = ZOOM_SCALE;
	else if (key == MOUSE_UP)
		args.zoom = 1 / ZOOM_SCALE;
	else
		return (0);
	args.entry_point = &(coord_helper->entry_point);
	args.focus = &((t_complex){
		args.entry_point->r + coord_helper->delta * x,
		args.entry_point->i + coord_helper->delta * y
	});
	coord_helper->width /= args.zoom;
	coord_helper->height /= args.zoom;
	coord_helper->entry_point = complex_coord_zoom(&args);
	coord_helper->delta = coord_helper->width / WIDTH;
	dispatcher->render(dispatcher);
	render_board(dispatcher);
	return (0);
}
