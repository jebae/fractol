#include "fractol.h"

static void			fill_img(int *img, t_render_helper *render_helper, t_palette *palette)
{
	int			color;
	double		entry_x;
	int			x;
	int			y;

	y = 0;
	entry_x = render_helper->z.r;
	while (y < HEIGHT)
	{
		x = 0;
		render_helper->z.r = entry_x;
		while (x < WIDTH)
		{
			color = render_helper->iteration(render_helper->z,\
				*(render_helper->c), palette);
			img[x + y * WIDTH] = color;
			x++;
			render_helper->z.r += render_helper->delta;
		}
		y++;
		render_helper->z.i += render_helper->delta;
	}
}

void				render_fractal(t_render_helper *render_helper,\
	t_marker *marker)
{
	int		*img_buf;

	img_buf = (int *)get_img_buffer(marker->p_img);
	fill_img(img_buf, render_helper, marker->palette);
	mlx_put_image_to_window(marker->p_mlx, marker->p_win, marker->p_img,\
		0, 0);
}
