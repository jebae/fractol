/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:37:51 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:38:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		event_exit(t_dispatcher *dispatcher)
{
	clear_clhelper(&(dispatcher->clhelper));
	delete_color_scheme(dispatcher->marker.palette);
	ft_memdel((void **)&(dispatcher->marker.palette));
	mlx_destroy_image(dispatcher->marker.p_mlx, dispatcher->marker.p_img);
	mlx_destroy_window(dispatcher->marker.p_mlx, dispatcher->marker.p_win);
	ft_putstr(KGRN "Program exit...\n" KNRM);
	exit(1);
}
