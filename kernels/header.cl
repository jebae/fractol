#define MAX_ITERATION			100
#define BLACK					0x000000
#define NUM_COLOR_CTRL_POINT	6
#define ABS(N) ((N < 0) ? -(N) : (N))

constant double			color_ctrl_point[NUM_COLOR_CTRL_POINT] = {
	0.0,
	0.16,
	0.42,
	0.6425,
	0.8575,
	1.0
};
