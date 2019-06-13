#include "fractol.h"

int     main(void)
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

	dispatcher.is_parallel = 0;
	dispatcher.julia_effect = 0;
	dispatcher.coord_helper = init_coord_helper();
	dispatcher.render = &render_mandelbrot;
	init_clhelper(&(dispatcher.clhelper), (char **)kernel_srcs,\
		sizeof(kernel_srcs) / sizeof(char *));
	init_mlx(&dispatcher);
	dispatcher.render(&dispatcher);
	render_board(&dispatcher);
	mlx_loop(dispatcher.marker.p_mlx);
	return (0);
}
