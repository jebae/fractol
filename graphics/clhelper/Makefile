NAME = libclhelper.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ../libft/includes\
	-I ./include\

SRCS = srcs/handle_error/*.c\
	srcs/prerequisites/*.c\
	srcs/utils/*.c\
	srcs/memory/*.c\
	srcs/kernel/*.c\
	srcs/cmd_queue/*.c\
	srcs/release/*.c\

LIBS = -L ../libft/libft.a

OBJS = platform_err.o\
	device_err.o\
	context_err.o\
	cmd_queue_err.o\
	cmd_queue_err2.o\
	memory_err.o\
	program_err.o\
	kernel_err.o\
	release_err.o\
	handle_error_utils.o\
	set_device.o\
	get_device_info.o\
	create_context.o\
	create_cmd_queue.o\
	create_buffer.o\
	create_program.o\
	build_program.o\
	get_program_build_info.o\
	concat_kernel_src.o\
	create_kernel.o\
	set_kernel_arg.o\
	enqueue_ndrange_kernel.o\
	enqueue_read_buffer.o\
	enqueue_write_buffer.o\
	flush.o\
	finish.o\
	release_all.o\

all : $(NAME)

$(NAME) : $(LIBS) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBS) :
	$(MAKE) -C ../libft all

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

clean :
	$(MAKE) -C ../libft clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C ../libft fclean
	rm -rf $(NAME)

re : fclean all
