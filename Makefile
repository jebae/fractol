NAME = fractol

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = -lmlx\
	-L ./graphics/clhelper -lclhelper\
	-L ./graphics/draw -ldraw\
	-L ./graphics/gmath -lgmath\
	-L ./graphics/libft -lft\

INCLUDES = -I ./include\
	-I ./graphics/clhelper/include\
	-I ./graphics/draw/includes\
	-I ./graphics/gmath/includes\
	-I ./graphics/libft/includes\

FRAMEWORKS = -framework OpenGL\
	-framework AppKit\
	-framework OpenCL\

SRCS = srcs/fractal/*.c\
	srcs/init/*.c\
	srcs/calc/*.c\
	srcs/parallel/*.c\
	srcs/utils/*.c\
	srcs/events/*.c\
	srcs/board/*.c\
	srcs/main.c\

all : $(NAME)

$(NAME) : $(LIBS) $(SRCS)
	$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(FRAMEWORKS) $(SRCS) -o $(NAME)

$(LIBS) :
	$(MAKE) -C ./graphics/libft all
	$(MAKE) -C ./graphics/gmath all
	$(MAKE) -C ./graphics/draw all
	$(MAKE) -C ./graphics/clhelper all

clean :
	$(MAKE) -C ./graphics/libft clean
	$(MAKE) -C ./graphics/gmath clean
	$(MAKE) -C ./graphics/draw clean
	$(MAKE) -C ./graphics/clhelper clean

fclean :
	$(MAKE) -C ./graphics/libft fclean
	$(MAKE) -C ./graphics/gmath fclean
	$(MAKE) -C ./graphics/draw fclean
	$(MAKE) -C ./graphics/clhelper fclean
	rm -rf $(NAME)

re : fclean all
