/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clhelper.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:28:21 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:28:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLHELPER_H
# define CLHELPER_H

# include <OpenCL/cl.h>
# include <fcntl.h>
# include "libft.h"

# define CLHELPER_FAIL				-1
# define CLHELPER_SUCCESS			1

typedef struct			s_clhelper
{
	cl_platform_id		platform;
	cl_device_id		*devices;
	cl_uint				num_devices;
	cl_context			context;
	cl_command_queue	*cmd_queues;
	cl_mem				*mems;
	cl_program			program;
	cl_kernel			*kernels;
}						t_clhelper;

typedef struct			s_create_buffer_args
{
	cl_context			context;
	cl_mem_flags		flags;
	size_t				size;
	void				*host_ptr;
}						t_create_buffer_args;

typedef struct			s_enqueue_ndrange_kernel_args
{
	cl_command_queue	cmd_queue;
	cl_kernel			kernel;
	cl_uint				work_dim;
	const size_t		*global_work_size;
	const size_t		*local_work_size;
}						t_enqueue_ndrange_kernel_args;

typedef struct			s_enqueue_buffer_args
{
	cl_command_queue	cmd_queue;
	cl_mem				mem;
	size_t				offset;
	size_t				size;
	void				*host_buf;
}						t_enqueue_buffer_args;

/*
** handle_error
*/
int						clh_print_err(const char *msg);
int						clh_check_get_platform_ids(cl_int ret);
int						clh_check_get_device_ids(cl_int ret);
int						clh_check_get_device_info(cl_int ret);
int						clh_check_create_context(cl_int ret);
int						clh_check_create_cmd_queue(cl_int ret);
int						clh_check_create_buffer(cl_int ret);
int						clh_check_create_program(cl_int ret);
int						clh_check_build_program(cl_int ret);
int						clh_check_get_program_build_info(cl_int ret);
int						clh_check_create_kernel(cl_int ret);
int						clh_check_set_kernel_arg(cl_int ret);
int						clh_check_enqueue_ndrange_kernel(cl_int ret);
int						clh_check_enqueue_read_buffer(cl_int ret);
int						clh_check_enqueue_write_buffer(cl_int ret);
int						clh_check_flush(cl_int ret);
int						clh_check_finish(cl_int ret);
int						clh_check_release_kernel(cl_int ret);
int						clh_check_release_program(cl_int ret);
int						clh_check_release_mem_object(cl_int ret);
int						clh_check_release_cmd_queue(cl_int ret);
int						clh_check_release_context(cl_int ret);

/*
** prerequisites
*/
int						clh_set_device(t_clhelper *clhelper,\
	cl_device_type type);
int						clh_create_context(t_clhelper *clhelper);
int						clh_create_cmd_queues(t_clhelper *clhelper);

/*
** memory
*/
int						clh_create_buffer(cl_mem *mem,\
	t_create_buffer_args *args);

/*
** kernel
*/
int						clh_create_program(cl_program *program,\
	cl_context context, char *src);
int						clh_build_program(cl_program program,\
	cl_device_id *device);
int						clh_get_program_build_info(cl_program program,\
	cl_device_id device);
int						clh_create_kernel(cl_kernel *kernel,\
	cl_program program, const char *kernel_name);
int						clh_set_kernel_arg(cl_kernel kernel,\
	cl_uint arg_index, size_t arg_size, const void *arg_value);

/*
** cmd_queue
*/
int						clh_enqueue_ndrange_kernel(\
	t_enqueue_ndrange_kernel_args *args);
int						clh_enqueue_read_buffer(\
	t_enqueue_buffer_args *args);
int						clh_enqueue_write_buffer(\
	t_enqueue_buffer_args *args);
int						clh_flush(cl_command_queue cmd_queue);
int						clh_finish(cl_command_queue cmd_queue);

/*
** release
*/
void					clh_release_all(t_clhelper *clhelper,\
	cl_uint num_kernels, cl_uint num_mems);
void					clh_free_all(t_clhelper *clhelper);

/*
** utils
*/
int						clh_get_device_info(t_clhelper *clhelper);
char					*clh_concat_kernel_src(\
	char **src_files, size_t num_files);

#endif
