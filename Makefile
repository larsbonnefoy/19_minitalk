# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 08:33:19 by lbonnefo          #+#    #+#              #
#    Updated: 2022/12/13 13:20:34 by lbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECLIENT = client

NAMESERVER = server

FILESCLIENT =	bin_conv.c \
				client.c \
				sig_com.c \

FILESSERVER =	server.c 

SRCSCLIENT = $(addprefix src_client/, $(FILESCLIENT))

SRCSSERVER= $(addprefix src_server/, $(FILESSERVER))

OBJ1 = $(SRCSCLIENT:.c=.o)

OBJ2 = $(SRCSSERVER:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

###LIB INCLUDES###

LIBFT_DIR = 19_libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = 19_ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

$(NAMECLIENT): $(OBJ1) $(OBJ2) 
				make -C $(LIBFT_DIR)
				make -C $(PRINTF_DIR)
				cc $(CFLAGS) $(OBJ1) $(LIBFT) $(PRINTF) -o $(NAMECLIENT)
				cc $(CFLAGS) $(OBJ2) $(LIBFT) $(PRINTF) -o $(NAMESERVER)

.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAMECLIENT) 

clean:
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		rm -rf $(OBJ1) $(OBJ2)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(PRINTF_DIR)
		rm -rf $(NAMECLIENT) $(NAMESERVER)

re: fclean all

.PHONY: all clean fclean re
