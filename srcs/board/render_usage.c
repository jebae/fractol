#include "fractol.h"

void		render_usage(void *p_mlx, void *p_win)
{
	mlx_string_put(p_mlx, p_win, 5, 5, YELLOW, "[<^v>]");
	mlx_string_put(p_mlx, p_win, 5, 35, YELLOW, "[rgb]");
	mlx_string_put(p_mlx, p_win, 5, 65, YELLOW, "[1]");
	mlx_string_put(p_mlx, p_win, 5, 95, YELLOW, "[2]");
	mlx_string_put(p_mlx, p_win, 5, 125, YELLOW, "[3]");
	mlx_string_put(p_mlx, p_win, 5, 155, YELLOW, "[P]");
	mlx_string_put(p_mlx, p_win, 5, 185, YELLOW, "[J]");
	mlx_string_put(p_mlx, p_win, 5, 215, YELLOW, "[ESC]");
	mlx_string_put(p_mlx, p_win, 80, 5, GREEN, "Move");
	mlx_string_put(p_mlx, p_win, 80, 35, GREEN, "Change color scheme");
	mlx_string_put(p_mlx, p_win, 80, 65, GREEN, "Mandelbrot");
	mlx_string_put(p_mlx, p_win, 80, 95, GREEN, "Julia");
	mlx_string_put(p_mlx, p_win, 80, 125, GREEN, "Burning ship");
	mlx_string_put(p_mlx, p_win, 80, 155, GREEN, "Parallel");
	mlx_string_put(p_mlx, p_win, 80, 185, GREEN, "Julia effect");
	mlx_string_put(p_mlx, p_win, 80, 215, GREEN, "Exit");
}
