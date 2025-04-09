# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:34:27 by danpalac          #+#    #+#              #
#    Updated: 2025/03/28 14:18:43 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========COLOURS=============================================================#

# Basic Colors
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# Bright Colors
BOLD_BLACK  = \033[1;30m
BOLD_RED    = \033[1;31m
BOLD_GREEN  = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE   = \033[1;34m
BOLD_MAGENTA= \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_WHITE  = \033[1;37m

# Extended Colors (256 colors)
ORANGE      = \033[38;5;208m
WINE        = \033[38;5;88m
LIME        = \033[38;5;190m
TURQUOISE   = \033[38;5;38m
LIGHT_PINK  = \033[38;5;13m
DARK_GRAY   = \033[38;5;235m
LIGHT_RED   = \033[38;5;203m
LIGHT_BLUE  = \033[38;5;75m

BRIGHT_BLUE = \033[38;5;27m
BRIGHT_GREEN= \033[38;5;46m
BRIGHT_YELLOW=\033[38;5;226m
BRIGHT_CYAN = \033[38;5;51m
BRIGHT_WHITE= \033[38;5;231m

# Reseteo de color
NO_COLOR    = \033[0m
DEF_COLOR   = \033[0;39m
CLEAR_LINE  = \033[2K
MOVE_UP     = \033[1A

#==========NAMES===============================================================#

NAME		:= libexe.a
MEMTRACK_LIB:= libmt.a
LIBFT_LIB	:= libft.a
PARSER_LIB	:= libparse.a
EXE			:= exe

#==========DIRECTORIES=======================================================#

INC 			:= inc/
SRC_DIR 		:= src/
OBJ_DIR 		:= obj/
LIBFT_DIR		:= ../libft/
LIB_DIR			:= ../lib/
MEMTRACK_DIR	:= ../memtrack/
PARSER_DIR		:= ../parse/

MEMTRACK		:= $(MEMTRACK_DIR)$(MEMTRACK_LIB)
LIBFT			:= $(LIBFT_DIR)$(LIBFT_LIB)
PARSER			:= $(PARSER_DIR)$(PARSER_LIB)
BUILTINS_DIR	:= $(SRC_DIR)builtins/
CMD_DIR			:= $(SRC_DIR)cmd/
ENV_DIR			:= $(SRC_DIR)env/
UTILS_DIR		:= $(SRC_DIR)exe_utils/

INCLUDES		:= $(BUILTINS_DIR)*.h $(CMD_DIR)*.h $(ENV_DIR)*.h $(UTILS_DIR)*.h

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p
IFLAGS		:= -I$(LIB_DIR)$(INC) -I$(INC) -I$(BUILTINS_DIR) -I$(CMD_DIR) -I$(ENV_DIR) -I$(UTILS_DIR)
LFLAGS		:= -L$(LIB_DIR) -lparse -lft -lmt -lreadline

#==========FILES==============================================================#

# Variables de fuentes y objetos
SRCS	:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS	:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
DEPS	:= $(patsubst $(OBJ_DIR)%.o, $(OBJ_DIR)%.d, $(OBJS))

#==========RULES==============================================================#

-include $(DEPS)
all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(MEMTRACK) $(PARSER) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(NAME)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"
	@$(MKDIR) $(LIB_DIR)
	@cp -r inc $(NAME) $(LIB_DIR)
	@cp $(INCLUDES) $(LIB_DIR)$(INC)

$(EXE): main.c $(NAME)
	@$(CC) $(CFLAGS) $(IFLAGS) main.c $(NAME) $(LFLAGS) -o $(EXE)
	@echo "$(BOLD_BLUE)[$(BRIGHT_GREEN)$(EXE)$(DEF_COLOR)$(BOLD_BLUE)] compiled!$(DEF_COLOR)"
	@echo "$(TURQUOISE)------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MEMTRACK):
	@make -sC $(MEMTRACK_DIR)

$(PARSER):
	@make -sC $(PARSER_DIR)
	
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) $(OBJ_DIR) $(LIB_DIR); \
		echo "$(CYAN)[$(NAME)]:\tobject files $(GREEN) => Cleaned!$(DEF_COLOR)"; \
	fi
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MEMTRACK_DIR)
	@make clean -sC $(PARSER_DIR)

fclean: clean
	@$(RM) -rf $(NAME) $(EXE)
	@make fclean -sC $(LIBFT_DIR)
	@make fclean -sC $(MEMTRACK_DIR)
	@make fclean -sC $(PARSER_DIR)

re: fclean all

.SILENT: all clean fclean
.PHONY: all clean fclean re bonus
