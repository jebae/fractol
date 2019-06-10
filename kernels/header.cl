#define MAX_ITERATION			100
#define BLACK					0x000000
#define BLUE					0x0000FF
#define NUM_COLOR_CTRL_POINT	6
#define ABS(N) ((N < 0) ? -(N) : (N))

constant float			color_ctrl_point[NUM_COLOR_CTRL_POINT] = {
	0.0f,
	0.16f,
	0.42f,
	0.6425f,
	0.8575f,
	1.0f
};

constant uchar3			color_scheme[NUM_COLOR_CTRL_POINT] = {
	(uchar3)(0, 7, 100),
	(uchar3)(32, 107, 203),
	(uchar3)(237, 255, 255),
	(uchar3)(255, 170, 0),
	(uchar3)(0, 2, 0),
	(uchar3)(0, 7, 100)
};

typedef struct		s_complex
{
	float			r;
	float			i;
}					t_complex;
