/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_clhelper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:40:49 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:40:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		clear_clhelper(t_clhelper *clhelper)
{
	clh_release_all(clhelper, NUM_CL_KERNELS, NUM_CL_MEMS);
	clh_free_all(clhelper);
}
