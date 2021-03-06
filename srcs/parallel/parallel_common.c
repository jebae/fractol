/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:40:57 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:40:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			enqueue_ndrange_kernel(\
	cl_command_queue cmd_queue, cl_kernel kernel)
{
	t_enqueue_ndrange_kernel_args	args;
	static const size_t				global_work_size = WIDTH * HEIGHT;

	args.cmd_queue = cmd_queue;
	args.kernel = kernel;
	args.work_dim = 1;
	args.global_work_size = &global_work_size;
	args.local_work_size = NULL;
	if (clk_enqueue_ndrange_kernel(&args) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

int			enqueue_read_buffer(cl_command_queue cmd_queue,\
	cl_mem mem, int *host_buf)
{
	t_enqueue_buffer_args		args;

	args.cmd_queue = cmd_queue;
	args.mem = mem;
	args.offset = 0;
	args.size = sizeof(*host_buf) * WIDTH * HEIGHT;
	args.host_buf = host_buf;
	if (clk_enqueue_read_buffer(&args) == CLKIT_FAIL)
		return (FRACTOL_FAIL);
	return (FRACTOL_SUCCESS);
}

void		parallel_render(int fractal_name, t_clkit *clkit,\
	t_marker *marker)
{
	int		*host_buf;

	host_buf = (int *)get_img_buffer(marker->p_img);
	if (enqueue_ndrange_kernel(clkit->cmd_queues[0],\
		clkit->kernels[fractal_name]) == FRACTOL_FAIL)
		return ;
	if (enqueue_read_buffer(clkit->cmd_queues[0],\
		clkit->mems[0], host_buf) == FRACTOL_FAIL)
		return ;
	if (clk_flush(clkit->cmd_queues[0]) == CLKIT_FAIL)
		return ;
	if (clk_finish(clkit->cmd_queues[0]) == CLKIT_FAIL)
		return ;
	mlx_put_image_to_window(marker->p_mlx, marker->p_win, marker->p_img,\
		0, 0);
}
