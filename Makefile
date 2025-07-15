# **************************************************************************** #
#                                                                              #
#                          Makefile para so_long                               #
#                                                                              #
# **************************************************************************** #

NAME = so_long


MLX_DIR = ./minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a


CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I. -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCDIR = .
OBJDIR = obj


SOURCES = 

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compilando $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	@echo "$(BLUE)Compilando MiniLibX...$(NC)"
	@$(MAKE) -sC $(MLX_DIR)

$(NAME): $(OBJECTS) $(MLX_LIB)
	@echo "$(BLUE)Enlazando $(NAME)...$(NC)"
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME) 
	@echo "$(GREEN)✓ $(NAME) creado con éxito!$(NC)"

clean:
	@echo "$(RED)Limpiando archivos objeto...$(NC)"
	@rm -rf $(OBJDIR)
	@$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	@echo "$(RED)Limpiando $(NAME)...$(NC)"
	@rm -f $(NAME)

re: fclean all

valgrind: all
	@echo "$(BLUE)Ejecutando valgrind...$(NC)"
	@valgrind --leak-check=full ./$(NAME) maps/tu_mapa.ber

norm:
	@echo "$(BLUE)Comprobando norminette...$(NC)"
	@norminette $(SOURCES) *.h

.PHONY: all clean fclean re valgrind norm