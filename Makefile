# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 16:34:16 by jebae             #+#    #+#              #
#    Updated: 2019/06/22 16:34:17 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
    printf "$(KGRN)[fractol]$(KNRM) compile $(1)\n"
    $(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
    $(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# program name
NAME = fractol

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ./graphics/libft

GMATH_PATH = ./graphics/gmath

DRAW_PATH = ./graphics/draw

CLKIT_PATH = ./graphics/clkit

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\
	-I $(GMATH_PATH)/includes\
	-I $(DRAW_PATH)/includes\
	-I $(CLKIT_PATH)/includes\

LIBS = -lmlx\
	-L $(LIBFT_PATH) -lft\
	-L $(GMATH_PATH) -lgmath\
	-L $(DRAW_PATH) -ldraw\
	-L $(CLKIT_PATH) -lclkit\

FRAMEWORKS = -framework OpenGL\
	-framework AppKit\
	-framework OpenCL\

# srcs
SRC_BOARD = render_board.c\
	render_color_scheme.c\
	render_status.c\
	render_usage.c\

SRC_CALC = color.c\
	iteration.c\

SRC_EVENTS = event_change_palette.c\
	event_change_type.c\
	event_exit.c\
	event_julia_effect.c\
	event_keypress.c\
	event_mouse_move.c\
	event_parallel.c\
	event_translate.c\
	event_zoom.c\

SRC_FRACTAL = burning_ship.c\
	fractal.c\
	julia.c\
	mandelbrot.c\

SRC_INIT = init.c\

SRC_PARALLEL = clear_clkit.c\
	init_clkit.c\
	parallel_burning_ship.c\
	parallel_common.c\
	parallel_julia.c\
	parallel_mandelbrot.c\

SRC_UTILS = mlx_utils.c\

SRC_MAIN = main.c

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_MAIN:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_BOARD:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_CALC:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_EVENTS:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_FRACTAL:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_INIT:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_PARALLEL:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_UTILS:.c=.o))

# compile objs
HEADERS = $(INCDIR)/fractol.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(LIBFT_PATH)/includes/get_next_line.h\
	$(GMATH_PATH)/includes/gmath.h\
	$(DRAW_PATH)/includes/draw.h\
	$(CLKIT_PATH)/includes/clkit.h\

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/board/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/calc/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/events/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/fractal/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/init/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/parallel/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/utils/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : deps pre_build $(OBJDIR) $(OBJS) post_build
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(FRAMEWORKS) $(OBJS) -o $(NAME)

deps :
	@$(MAKE) -C $(LIBFT_PATH) all
	@$(MAKE) -C $(GMATH_PATH) all
	@$(MAKE) -C $(DRAW_PATH) all
	@$(MAKE) -C $(CLKIT_PATH) all

pre_build :
	@printf "$(KGRN)[fractol] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[fractol] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(GMATH_PATH) clean
	@$(MAKE) -C $(DRAW_PATH) clean
	@$(MAKE) -C $(CLKIT_PATH) clean
	@rm -rf $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(GMATH_PATH) fclean
	@$(MAKE) -C $(DRAW_PATH) fclean
	@$(MAKE) -C $(CLKIT_PATH) fclean
	@rm -rf $(OBJS)

re : fclean all

.PHONY : all deps pre_build post_build clean fclean re
