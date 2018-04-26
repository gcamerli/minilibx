# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 19:11:39 by gicamerl          #+#    #+#              #
#    Updated: 2018/04/25 20:28:13 by gicamerl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Please use configure script

all: do_configure

do_configure:
	./configure

norme:
	./configure norme

clean:	
	./configure clean

fclean:
	./configure fclean

re: fclean all
