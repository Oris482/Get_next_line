# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 11:16:18 by jaesjeon          #+#    #+#              #
#    Updated: 2021/12/20 15:37:05 by jaesjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./$(SRCDIR)
RM = rm -rf
USERBUF = 1
DEF = -D BUFFER_SIZE=$(USERBUF)
DEBUG = -g
LEAKS = -fsanitize=address
SRCDIR = ./get_next_line
OBJDIR = ./get_next_line
_SRCS_M = get_next_line.c \
		 get_next_line_utils.c
_SRCS_B = $(_SRCS_M:%.c=%_bonus.c)
SRCS_M = $(addprefix $(SRCDIR)/, $(_SRCS_M))
SRCS_B = $(addprefix $(SRCDIR)/, $(_SRCS_B))
_OBJS_M = $(SRCS:.c=.o)
_OBJS_B = $(SRCS_BONUS:.c=.o)
OBJS_M = $(addprefix $(OBJDIR)/, $(_OBJS_M))
OBJF_B = $(addprefix $(OBJDIR)/, $(_OBJS_B))
MULTI_M = multifd_main.c
MAXFD_M = maxfd_main.c
STDIN_M = stdin_main.c
USER_M =

.PHONY: maxfd stdin multifd user clean fclean 42 1024 10000000 leaks debug

multifd: $(SRCS_B) $(MULTI_M)
	$(CC) $(CFLAGS) $(DEF) $(SRCS_B) $(MULTI_M) -o $(addprefix gnlo_, $@)

maxfd: $(SRCS_M) $(MAXFD_M)
	$(CC) $(CFLAGS) $(DEF) $(SRCS_M) $(MAXFD_M) -o $(addprefix gnlo_, $@)

stdin: $(SRCS_M) $(STDIN_M)
	$(CC) $(CFLAGS) $(DEF) $(SRCS_M) $(STDIN_M) -o $(addprefix gnlo_, $@)

user: $(SRCS_B) $(USER_M)
	$(CC) $(CFLAGS) $(DEF) $(SRCS_B) $(USER_M) -o $(addprefix gnlo_, $@)

42: $(SRCS_B)
	@echo --------------------------------------
	@echo ********BUFFER_SIZE is now 42*********
	@echo --------------------------------------
	@make "USERBUF = 42" multifd

1024: $(SRCS_B)
	@echo --------------------------------------
	@echo *******BUFFER_SIZE is now 1024********
	@echo --------------------------------------
	@make "USERBUF = 1024" multifd

10000000: $(SRCS_B)
	@echo --------------------------------------
	@echo *****BUFFER_SIZE is now 10000000******
	@echo --------------------------------------
	@make "USERBUF = 10000000" multifd

leaks: $(SRCS_B) $(MULTI_M)
	@echo --------------------------------------
	@echo Compiled with fsanitize=address option
	@echo --------------------------------------
	$(CC) $(CFLAGS) $(LEAKS) $(DEF) $(SRCS_B) $(MULTI_M) -o $(addprefix gnlo_, $@)

debug: $(SRCS_B) $(MULTI_M)
	$(CC) $(CFLAGS) $(DEBUG) $(DEF) $(SRCS_B) $(MULTI_M) -o $(addprefix gnlo_, $@)

clean:
	$(RM) gnlo_*

fclean: clean
	$(RM) $(SRCDIR)/*
