/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:29:45 by jebae             #+#    #+#             */
/*   Updated: 2019/06/22 16:29:47 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		delete_color_scheme(t_palette *palette)
{
	ft_memdel((void **)&(palette->color_ctrl_point));
	ft_memdel((void **)&(palette->color_scheme));
}
