# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 17:02:16 by gicamerl          #+#    #+#              #
#    Updated: 2018/04/27 13:22:45 by gicamerl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Non-file targets
.PHONY: all norme clean fclean re

# Empty variables 
INCS		=	%%%%
HT			=	%%%%
DOCP		=	%%%%

# Compiler and binaries
CC			=	/usr/bin/gcc
AR			=	/usr/bin/ar
RANLIB		=	/usr/bin/ranlib
RM			=	/bin/rm
MKDIR		=	/bin/mkdir

# Colors
GREEN		=	\033[0;32m
BLUE		=	\033[0;34m
RED			=	\033[0;31m
WHITE		=	\033[1;37m

# Target Library
NAME		= 	libmlx.a

# Directories
SRCD		=	src/
INCD		=	include/
OBJD		= 	obj/

#Source and Objects
SRC			= mlx_init.c \
	  mlx_new_window.c \
	  mlx_pixel_put.c \
	  mlx_loop.c \
	  mlx_mouse_hook.c \
	  mlx_key_hook.c \
	  mlx_expose_hook.c \
	  mlx_loop_hook.c \
	  mlx_int_anti_resize_win.c \
	  mlx_int_wait_first_expose.c \
	  mlx_int_get_visual.c \
	  mlx_flush_event.c \
	  mlx_string_put.c \
	  mlx_get_data_addr.c \
	  mlx_put_image_to_window.c \
	  mlx_get_color_value.c \
	  mlx_clear_window.c \
	  mlx_int_str_to_wordtab.c \
	  mlx_destroy_window.c \
	  mlx_hook.c \
	  mlx_rgb.c \
	  mlx_destroy_image.c \
	  mlx_new_image.c \
	  mlx_xpm.c \
	  mlx_int_param_event.c \
	  mlx_int_set_win_event_mask.c \
	  mlx_int_do_nothing.c \

SRCS		=	$(addprefix $(SRCD), $(SRC))
OBJ			=	$(addprefix $(OBJD), $(SRC:.c=.o))

# Flags and Header
CFLAGS		=	-O2 -I$(INCS)

HEADER		=	$(INCD)mlx.h \
				$(INCD)mlx_int.h

# Default make
all: $(OBJD) $(NAME) $(DOCP)

$(NAME): $(SRCS) $(OBJ) $(HEADER) Makefile
	@$(AR) rc $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@printf "$(GREEN) [LIB]$(WHITE) Building $(NAME)\n"

# Create minilibx obj dir
$(OBJD):
	@$(MKDIR) -p $(OBJD)
	@$(MKDIR) -p $(dir $(OBJ))
	@printf "$(GREEN) [OBJ]$(WHITE) Creating minilibx obj dir\n"

# Create objects
$(OBJD)%.o: $(SRCD)%.c
	@$(CC) $(CFLAGS) -I$(INCD) -c $< -o $@
	@printf "$(GREEN) [OBJ]$(WHITE) Building $@\n"

# Make a copy of the lib
do_cp:
	@cp $(NAME) libmlx_$(HT).a
	@printf "$(GREEN) [LIB]$(WHITE) Create libmlx_$(HT).a\n"

# Norminette
norme:
	norminette $(INCD)

# Clean objects
clean:
	@if [ -e $(OBJD) ]; \
	then \
		$(RM) -rf $(OBJD); \
		printf "$(BLUE) [OBJ]$(WHITE) Clean minilibx objects\n"; \
	else \
		printf "$(BLUE) [OBJ]$(WHITE) No minilibx objects\n"; \
	fi;

# Clean in depth
fclean: clean
	@if [ -e $(NAME) ] || [ -e libmlx_$(HT).a ]; \
	then \
		$(RM) -f $(NAME) libmlx_$(HT).a; \
		printf "$(RED) [LIB]$(WHITE) Clean build files\n"; \
	else \
		printf "$(RED) [LIB]$(WHITE) No build files\n"; \
	fi;

# Remake
re: fclean all
