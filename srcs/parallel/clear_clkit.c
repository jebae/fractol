/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_clkit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:40:49 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:40:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		clear_clkit(t_clkit *clkit)
{
	clk_release_all(clkit, NUM_CL_KERNELS, NUM_CL_MEMS);
	clk_free_all(clkit);
}
