NAME = so_long

CC = cc
CFLAGS =  -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = main.c read_map.c moves.c so_long_utils.c check_error.c check_error4.c check_error3.c game_play.c so_long_utils2.c check_error2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(MLX_DIR) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME) -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	@clear
	@echo "\033[32mProjeto compilado com sucesso, pode trabalhar!\033[0m"

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@rm -f *.o
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[31mTudo eliminado com sucesso, pode bazar!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@clear
	@echo "\033[31mTudo eliminado com sucesso, pode bazar!\033[0m"

re: fclean all

.PHONY: all clean fclean re
