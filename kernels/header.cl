#define MAX_ITERATION			100
#define BLACK					0x000000
#define BLUE					0x0000FF
#define NUM_COLOR_CTRL_POINT	6
#define ABS(N) ((N < 0) ? -(N) : (N))

//constant float			log_two = log(2.0f);

constant float			color_ctrl_point[NUM_COLOR_CTRL_POINT] = {
	0.0f,
	0.16f,
	0.42f,
	0.6425f,
	0.8575f,
	1.0f
};

constant int3			color_scheme[NUM_COLOR_CTRL_POINT] = {
	(int3)(0, 7, 100),
	(int3)(32, 107, 203),
	(int3)(237, 255, 255),
	(int3)(255, 170, 0),
	(int3)(0, 2, 0),
	(int3)(0, 7, 100)
};

typedef struct		s_complex
{
	float			r;
	float			i;
}					t_complex;
