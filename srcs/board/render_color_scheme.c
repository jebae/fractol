/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_color_scheme.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:36:27 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:36:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_color_scheme(t_marker *marker, t_coord *offset)
{
	static int		width = 100;
	static int		height = 15;
	int				i;
	int				j;
	t_coord			coord;

	i = 0;
	while (i <= width)
	{
		marker->color = pick_color(marker->palette, (double)i / width);
		j = 0;
		while (j < height)
		{
			coord = (t_coord){offset->x + i, offset->y + j};
			marker->mark_pixel(marker, &coord, NULL);
			j++;
		}
		i++;
	}
}
