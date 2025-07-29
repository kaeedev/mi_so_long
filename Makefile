# **************************************************************************** #
#                                                                              #
#                          Makefile para so_long                               #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

# --- Rutas de Librerías ---
# Asegúrate de que estas rutas coincidan con la estructura de tu proyecto
LIBFT_DIR	:= ./includes/mi_libft
LIBFT_LIB	:= $(LIBFT_DIR)/libft.a

PRINTF_DIR	:= ./includes/ft_printf
PRINTF_LIB	:= $(PRINTF_DIR)/libftprintf.a

LIBMLX_DIR	:= ./includes/MLX42
LIBMLX_BUILD	:= $(LIBMLX_DIR)/build
LIBMLX_LIB	:= $(LIBMLX_BUILD)/libmlx42.a

# --- Archivos del Proyecto ---
# Busca archivos .c en TODO el proyecto (excluyendo includes)
SRCS	:= $(shell find ./srcs ./maps ./includes/mi_libft ./includes/get_next_line -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

# --- Includes y Enlazado de Librerías ---
HEADERS	:= -I ./includes -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I ./includes/get_next_line -I $(LIBMLX_DIR)/include
LIBS	:= $(LIBFT_LIB) $(PRINTF_LIB) $(LIBMLX_LIB) -ldl -lglfw -pthread -lm

# --- Colores para la Salida ---
GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

# --- Reglas Principales ---
all: $(NAME)

# El ejecutable depende de los objetos de so_long y de TODAS las librerías
$(NAME): $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(LIBMLX_LIB)
	@echo "$(BLUE)Enlazando $@...$(NC)"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)✅ so_long compilado con éxito!$(NC)"

# Reglas para compilar cada librería por separado
$(LIBFT_LIB):
	@echo "$(BLUE)Compilando Libft...$(NC)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(PRINTF_LIB):
	@echo "$(BLUE)Compilando ft_printf...$(NC)"
	@$(MAKE) -sC $(PRINTF_DIR)

$(LIBMLX_LIB):
	@echo "$(BLUE)Compilando MLX42...$(NC)"
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_BUILD) && make -C $(LIBMLX_BUILD) -j4

# Regla para compilar tus archivos .c a .o
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compilando: $(notdir $<)\r"

# --- Reglas de Limpieza ---
clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX_BUILD)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(PRINTF_DIR) clean
	@echo "Limpiando archivos objeto y builds."

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(PRINTF_DIR) fclean
	@echo "Limpiando todo."

re: fclean all

.PHONY: all clean fclean re