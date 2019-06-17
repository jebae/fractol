/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:36:25 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:36:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_board(t_dispatcher *dispatcher)
{
	render_usage(dispatcher->marker.p_mlx, dispatcher->marker.p_win);
	render_status(dispatcher);
}
