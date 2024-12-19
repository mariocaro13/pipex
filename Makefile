# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:02:56 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/12/18 20:24:35 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = pipex

# COLORS
GREEN = \033[0;32m
RESET := \033[0m

# SRC DIRS
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIRS = -I./ -I$(SRC_DIR) -I$(UTILS_DIR)

# FT_PRINTF directory and library
FT_PRINTF = ft_printf
LIBFTPRINTF = $(FT_PRINTF)/libftprintf.a

# Rule to build the FT_PRINTF library
$(LIBFTPRINTF):
	@$(MAKE) -C $(FT_PRINTF) --silent

# LIBFT directory and library
LIBFT = libft
LIBFTLIB = $(LIBFT)/libft.a

# Rule to build the LIBFT library 
$(LIBFTLIB):
	@$(MAKE) -C $(LIBFT) --silent

# Source files and object files
SRC = $(SRC_DIR)/main.c			\
	$(SRC_DIR)/path.c			\
	$(SRC_DIR)/execute_cmd.c	\
	$(SRC_DIR)/pid.c			\
	$(UTILS_DIR)/file_utils.c	\
	$(UTILS_DIR)/print_utils.c	\
	$(UTILS_DIR)/close_utils.c
	
# Objects files
OBJECTS = $(SRC:.c=.o)

# Dependency files
DEPS = $(OBJECTS:.o=.d)

# Compilation settings
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_DIRS) -g3  #-fsanitize=address

# Compile source files into object files and generate dependency files
%.o: %.c
	@$(CC) -MMD -c $< $(CFLAGS) -o $@

# Include dependency files
-include $(DEPS)

# Link object files and FT_PRINTF library into the executable
$(NAME): $(OBJECTS) $(LIBFTPRINTF) $(LIBFTLIB)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFTPRINTF) $(LIBFTLIB) -o $(NAME)
	@echo "$(GREEN)$(NAME): $(NAME) has been created successfully!$(RESET)"

# Default target to build the project
all: $(NAME)

# Clean up object files
clean:
	@rm -f $(OBJECTS) $(DEPS)
	@$(MAKE) -C $(FT_PRINTF) clean --silent
	@$(MAKE) -C $(LIBFT) clean --silent

# Clean up all generated files
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(FT_PRINTF) fclean --silent
	@$(MAKE) -C $(LIBFT) fclean --silent

# Rebuild the project
re: fclean all

# Run Norminette
norminette: 
	norminette $(NAME).h $(SRC)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re norminette
