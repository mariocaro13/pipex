# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:02:56 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/12/16 20:21:09 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = pipex

# COLORS
GREEN = \033[0;32m

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

# Source files and object files
SOURCE = $(SRC_DIR)/main.c	\
	$(UTILS_DIR)/exit_failure.c

# Objects files
OBJECTS = $(SOURCE:.c=.o)

# Dependency files
DEPS = $(OBJECTS:.o=.d)

# Compilation settings
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_DIRS) -g3  #-fsanitize=address

# Compile source files into object files and generate dependency files
%.o: %.c
	$(CC) -MMD -c $< $(CFLAGS) -o $@

# Include dependency files
-include $(DEPS)

# Link object files and FT_PRINTF library into the executable
$(NAME): $(OBJECTS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFTPRINTF) -o $(NAME)
	@echo "$(GREEN)$(NAME): $(NAME) has been created successfully!$(GREEN)"


# Default target to build the project
all: $(NAME)

# Run the project
run: re
	@$(MAKE) all
	./$(NAME)

# Run Valgrind
valgrind: re
	valgrind ./$(NAME)

# Clean up object files
clean:
	@rm -f $(OBJECTS) $(DEPS)
	@$(MAKE) -C $(FT_PRINTF) clean --silent

# Clean up all generated files
fclean: clean
	@rm -rf $(NAME) $(DEPS)
	@$(MAKE) -C $(FT_PRINTF) fclean --silent

# Rebuild the project
re: fclean all

# Run Norminette
norminette: 
	norminette $(NAME).h $(SOURCE)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run valgrind norminette $(FT_PRINTF)
.SILENT:
