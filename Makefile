# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 10:01:30 by kyoulee           #+#    #+#              #
#    Updated: 2022/09/24 19:44:14 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = push_swap

CC = cc
CXXFLAGS = $(NULL)
CFLAGS = -Wall -Werror -Wextra
DFLAGS = $(NULL)
IFLAGS =						\
	-I $(INCLUDE_DIR)			\
	-I $(INCLUDE_LIBFT_DIR)		\
	-I $(INCLUDE_FT_PRINTF_DIR)

LDFLAGS =						\
	-L $(LIBFT_DIR)				\
	-L $(FT_PRINTF_DIR)
	
LDLIBS =						\
	 -lft -lftprintf
	

#####***** COLOR *****#####
BG_RED     = \033[41m
BG_GREEN   = \033[42m
BG_YELLOW  = \033[43m
BG_BLUE    = \033[44m
BG_MAGENTA = \033[45m
BG_CYAN    = \033[46m
BG_LGREY   = \033[47m
BG_DGREY   = \033[100m
BG_LRED    = \033[101m
BG_LGREEN  = \033[102m
BG_LYELLOW = \033[103m
BG_LBLUE   = \033[104m
BG_LMAGENTA= \033[105m
BG_LCYAN   = \033[106m
BG_WHITE   = \033[107m
BG_MAKE1   = \033[48;5;236m
BG_MAKE2   = \033[48;5;238m
BG_MAKE3   = \033[48;5;240m

FG_BLACK   = \033[30m
FG_RED     = \033[31m
FG_GREEN   = \033[32m
FG_YELLOW  = \033[33m
FG_BLUE    = \033[34m
FG_MAGENTA = \033[35m
FG_CYAN    = \033[36m
FG_LGREY   = \033[37m
FG_DGREY   = \033[90m
FG_LRED    = \033[91m
FG_LGREEN  = \033[92m
FG_LYELLOW = \033[93m
FG_LBLUE   = \033[94m
FG_LMAGENTA= \033[95m
FG_LCYAN   = \033[96m
FG_WHITE   = \033[97m
 
CL_BOLD   = \033[1m
CL_DIM    = \033[2m
CL_UDLINE = \033[4m
CL_BLINK  = \033[5m
CL_INVERT = \033[7m
CL_HIDDEN = \033[8m
 
NO_COLOR = \033[0m

#####***** DIR *****#####

ROOTDIR = $(abspath $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
SRC_DIR = $(ROOTDIR)/src
SRC_DOUBLY_LIST_DIR = $(ROOTDIR)/src_doubly_list
SRC_PIVOT_DIR = $(ROOTDIR)/src_pivot
SRC_PUSH_SWAP_DIR = $(ROOTDIR)/src_push_swap
SRC_QUICK_SORT_DIR = $(ROOTDIR)/src_quick_sort
SRC_STACK_DIR = $(ROOTDIR)/src_stack


OBJ_DIR = $(ROOTDIR)/obj
INCLUDE_DIR = $(ROOTDIR)/include

## MODULES ##
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = $(ROOTDIR)/modules/Libft
INCLUDE_LIBFT_DIR = $(LIBFT_DIR)/include

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_DIR = $(ROOTDIR)/modules/ft_printf
INCLUDE_FT_PRINTF_DIR = $(FT_PRINTF_DIR)/include

#####***** SRC *****#####
SRC_C_SRC =	ft_make_memory.c	\
			main.c 

SRC_C = $(addprefix $(SRC_DIR)/, $(SRC_C_SRC))

SRC_DOUBLY_LIST_C_SRC =	\
						ft_doubly_list_add.c		\
						ft_doubly_list_connect.c	\
						ft_doubly_list_head_add.c	\
						ft_doubly_list_head_pop.c	\
						ft_doubly_list.c

SRC_DOUBLY_LIST_C = $(addprefix $(SRC_DOUBLY_LIST_DIR)/, $(SRC_DOUBLY_LIST_C_SRC))

SRC_PIVOT_C_SRC =	ft_minmax_hold.c	\
					ft_pdata.c 		\
					ft_pivot_down.c	\
					ft_pivot_sort.c	\
					ft_pivot_split.c	\
					ft_pivot_split_a.c	\
					ft_pivot_split_b.c	\
					ft_pivot_up.c		\
					ft_pivot.c			\
					ft_sort.c

SRC_PIVOT_C = $(addprefix $(SRC_PIVOT_DIR)/, $(SRC_PIVOT_C_SRC))

SRC_PUSH_SWAP_C_SRC =	ft_push_swap.c

SRC_PUSH_SWAP_C = $(addprefix $(SRC_PUSH_SWAP_DIR)/, $(SRC_PUSH_SWAP_C_SRC))

SRC_QUICK_SORT_C_SRC =	ft_quick_sort.c

SRC_QUICK_SORT_C = $(addprefix $(SRC_QUICK_SORT_DIR)/, $(SRC_QUICK_SORT_C_SRC))

SRC_STACK_C_SRC =	ft_pp.c	\
						ft_rr.c	\
						ft_rrr.c	\
						ft_ss.c

SRC_STACK_C = $(addprefix $(SRC_STACK_DIR)/, $(SRC_STACK_C_SRC))


OBJS =	$(SRC_C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_PIVOT_C:$(SRC_PIVOT_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_PUSH_SWAP_C:$(SRC_PUSH_SWAP_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_DOUBLY_LIST_C:$(SRC_DOUBLY_LIST_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_QUICK_SORT_C:$(SRC_QUICK_SORT_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_STACK_C:$(SRC_STACK_DIR)/%.c=$(OBJ_DIR)/%.o)	\




OBJS_CLEAN = $(OBJS) 

#####***** working *****#####

all : $(OBJ_DIR) $(TARGET)

bonus : $(OBJ_DIR) $(TARGET)

test : 
	@echo "$(OBJS) -o $(TARGET)"


$(TARGET) : $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $(TARGET)
	@echo "$(FG_LMAGENTA)$(CC) $(FG_BLUE) $(CFLAGS)"
	@(for i in $(IFLAGS) $(LDFLAGS); do echo $$i; done)
	@echo "$(LDLIBS) $(FG_LCYAN)"
	@(for i in $(OBJS); do echo $$i; done)
	@echo "$(FG_BLUE)-o $(FG_LYELLOW)$(TARGET)$(NO_COLOR)"

$(OBJ_DIR) : 
	mkdir $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_PIVOT_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_PUSH_SWAP_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DOUBLY_LIST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_QUICK_SORT_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_STACK_DIR)/%.c
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

debug : 
	$(CC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -g3 -fsanitize=address
	
## MODULES ##
$(LIBFT):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)Libft$(NO_COLOR) -> $(FG_LCYAN)$(LIBFT)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(LIBFT_DIR) bonus
	@echo "$(NO_COLOR)"

$(FT_PRINTF):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)ft_printf$(NO_COLOR) -> $(FG_LCYAN)$(FT_PRINTF)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(FT_PRINTF_DIR) bonus
	@echo "$(NO_COLOR)"
#####***** clean *****#####

## MODULES ##
clean_libft :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(LIBFT))$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(LIBFT_DIR) fclean 
	@echo "$(NO_COLOR)"

clean_ft_printf :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(FT_PRINTF))$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(FT_PRINTF_DIR) fclean 
	@echo "$(NO_COLOR)"

clean : clean_libft clean_ft_printf
	rm -f $(OBJS_CLEAN)

fclean : OBJS_CLEAN+=$(TARGET)
fclean : clean

re : fclean all

.PHONY: all re  clean fclean clean_libft clean_ft_printf
