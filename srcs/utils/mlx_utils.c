/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:41:17 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:41:18 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*get_img_buffer(void *p_img)
{
	static int		bpp = MLX_BPP;
	static int		size_line = WIDTH;
	static int		endian = MLX_ENDIAN;

	return (mlx_get_data_addr(p_img, &bpp, &size_line, &endian));
}
