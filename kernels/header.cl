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

constant uchar3			color_schemes[3][NUM_COLOR_CTRL_POINT] = {
	{
		(uchar3)(100, 0, 7),
		(uchar3)(203, 32, 107),
		(uchar3)(255, 237, 255),
		(uchar3)(0, 255, 170),
		(uchar3)(0, 0, 2),
		(uchar3)(100, 0, 7)
	},
	{
		(uchar3)(7, 100, 0),
		(uchar3)(107, 203, 32),
		(uchar3)(255, 255, 237),
		(uchar3)(170, 0, 255),
		(uchar3)(2, 0, 0),
		(uchar3)(7, 100, 0)
	},
	{
		(uchar3)(0, 7, 100),
		(uchar3)(32, 107, 203),
		(uchar3)(237, 255, 255),
		(uchar3)(255, 170, 0),
		(uchar3)(0, 2, 0),
		(uchar3)(0, 7, 100)
	}
};
