# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 21:48:44 by gicamerl          #+#    #+#              #
#    Updated: 2018/04/26 21:48:49 by gicamerl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Non-file targets
.PHONY: all clean fclean re

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
NAME		=	libmlx.a

# Directories
SRCD		=	src/
INCD		=	include/
OBJD		= 	obj/
MBJD		=	mbj/

# Source and Objects
CSRC		= 	mlx_shaders.c \
				mlx_xpm.c \
				mlx_int_str_to_wordtab.c

MSRC		=	mlx_new_window.m \
				mlx_init_loop.m \
				mlx_new_image.m

SRCS		=	$(addprefix $(SRCD), $(CSRC))
SRCM		= 	$(addprefix $(SRCD), $(MSRC))
OBJ			=	$(addprefix $(OBJD), $(CSRC:.c=.o))
MBJ			= 	$(addprefix $(MBJD), $(MSRC:.m=.o))

# Flags and Header
CFLAGS		=	-O2

HEADER		=	$(INCD)mlx.h \
				$(INCD)mlx_int.h \
				$(INCD)mlx_new_window.h

# Default make
all: $(MBJD) $(OBJD) $(NAME)

$(NAME): $(SRCS) $(SRCM) $(OBJ) $(MBJ) $(HEADER) Makefile
	@$(AR) rc $(NAME) $(OBJ) $(MBJ)
	@$(RANLIB) $(NAME)
	@printf "$(GREEN) [LIB]$(WHITE) Building $(NAME)\n"

# Create minilibx obj dir
$(OBJD):
	@$(MKDIR) -p $(OBJD)
	@$(MKDIR) -p $(dir $(OBJ))
	@printf "$(GREEN) [OBJ]$(WHITE) Creating minilibx .c obj dir\n"

$(MBJD):
	@$(MKDIR) -p $(MBJD)
	@$(MKDIR) -p $(dir $(MBJ))
	@printf "$(GREEN) [OBJ]$(WHITE) Creating minilibx .m obj dir\n"

# Create objects
$(OBJD)%.o: $(SRCD)%.c
	@$(CC) $(CFLAGS) -I$(INCD) -c $< -o $@
	@printf "$(GREEN) [OBJ]$(WHITE) Building $@\n"

$(MBJD)%.o: $(SRCD)%.m
	@$(CC) $(CFLAGS) -I$(INCD) -c $< -o $@
	@printf "$(GREEN) [OBJ]$(WHITE) Building $@\n"

# Norminette
norme:
	norminette $(INCD)mlx.h
	norminette $(INCD)mlx_int.h

# Clean objects
clean:
	@if [ -e $(OBJD) ] || [ -e $(MBJD) ]; \
	then \
		$(RM) -rf $(OBJD); \
		$(RM) -rf $(MBJD); \
		printf "$(BLUE) [OBJ]$(WHITE) Clean minilibx objects\n"; \
	fi;

# Clean in depth
fclean: clean
	@if [ -e $(NAME) ]; \
	then \
		$(RM) -f $(NAME); \
		printf "$(RED) [LIB]$(WHITE) Clean build files\n"; \
	fi;

# Remake
re: fclean all
