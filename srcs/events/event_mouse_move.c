/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:38:40 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:38:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		event_mouse_move(int x, int y, void *param)
{
	t_dispatcher		*dispatcher;
	t_complex			*entry_point;
	double				delta;

	dispatcher = (t_dispatcher *)param;
	if (dispatcher->render != &render_julia ||\
		dispatcher->julia_effect == 0)
		return (0);
	entry_point = &(dispatcher->coord_helper.entry_point);
	delta = dispatcher->coord_helper.delta;
	dispatcher->c = (t_complex){
		entry_point->r + delta * x,
		entry_point->i + delta * y
	};
	dispatcher->render(dispatcher);
	render_board(dispatcher);
	return (0);
}
