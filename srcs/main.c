/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:41:22 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:42:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		handle_wrong_arg(void)
{
	put_color_str(KRED, "Wrong argument\n");
	put_color_str(KGRN,\
		"Example\n- m (mandelbrot)\n- j (julia)\n- b (burning ship)\n");
	return (FRACTOL_FAIL);
}

int		check_arg(char *arg, t_dispatcher *dispatcher)
{
	if (ft_strcmp(arg, "m") == 0)
	{
		dispatcher->render = &render_mandelbrot;
		return (FRACTOL_SUCCESS);
	}
	if (ft_strcmp(arg, "j") == 0)
	{
		dispatcher->c = (t_complex){-0.8, 0.156};
		dispatcher->render = &render_julia;
		return (FRACTOL_SUCCESS);
	}
	if (ft_strcmp(arg, "b") == 0)
	{
		dispatcher->render = &render_burning_ship;
		return (FRACTOL_SUCCESS);
	}
	return (FRACTOL_FAIL);
}

int		main(int argc, char **args)
{
	t_dispatcher				dispatcher;
	static char					*kernel_srcs[] = {
		"kernels/header.cl",
		"kernels/color.cl",
		"kernels/iteration.cl",
		"kernels/mandelbrot.cl",
		"kernels/burning_ship.cl",
		"kernels/julia.cl"
	};

	if (argc != 2 || check_arg(args[1], &dispatcher) == FRACTOL_FAIL)
		return (handle_wrong_arg());
	dispatcher.is_parallel = 0;
	dispatcher.julia_effect = 0;
	dispatcher.coord_helper = init_coord_helper();
	init_clkit(&(dispatcher.clkit), (char **)kernel_srcs,\
		sizeof(kernel_srcs) / sizeof(char *));
	init_mlx(&dispatcher);
	dispatcher.render(&dispatcher);
	render_board(&dispatcher);
	mlx_loop(dispatcher.marker.p_mlx);
	return (0);
}
