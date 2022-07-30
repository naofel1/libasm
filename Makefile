# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 11:21:07 by nabentay          #+#    #+#              #
#    Updated: 2022/07/30 21:24:32 by nabentay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	mandatory/ft_strlen.s\
		mandatory/ft_strcpy.s\
		mandatory/ft_strcmp.s\
		mandatory/ft_write.s\
		mandatory/ft_read.s\
		mandatory/ft_strdup.s

SRCS_B =	bonus/ft_list_size_bonus.s\

OBJS = $(SRCS:.s=.o)
OBJS_B = $(SRCS_B:.s=.o)
LIB = libasm.a
LIB_B = libasm_bonus.a

NASM = nasm
NFLAGS = -f elf64

GCC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = main
NAME_B = main_bonus
FNAME = libasmTest
FNAME_B = libasmTest_bonus

all: $(LIB)

%.o: %.s
	$(NASM) $(NFLAGS) $<

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

$(LIB_B): $(OBJS_B)
	ar rcs $(LIB_B) $(OBJS_B)

main: $(LIB) $(LIB_B)
	$(GCC) $(FLAGS) -c $(NAME).c -o $(NAME).o
	$(GCC) $(FLAGS) -o $(FNAME) $(NAME).o $<
	echo "TEST123" > testfile

bonus: $(LIB_B)

clean:
	rm -f $(OBJS) $(OBJS_B) $(NAME_B).o $(NAME).o

fclean: clean
	rm -f $(LIB) $(LIB_B) $(FNAME) $(FNAME_B) testfile

re: fclean $(LIB)

.PHONY: all bnus main clean fclean re
