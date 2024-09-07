SRC	=	ft_putnbr_fd ft_putendl_fd ft_putstr_fd ft_putchar_fd ft_striteri ft_strmapi ft_itoa ft_split ft_strtrim ft_strjoin ft_substr ft_strjoin ft_strtrim ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_atoi ft_strncmp ft_memcmp ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_calloc ft_strlcpy ft_strlcat ft_strlen ft_strchr ft_strrchr ft_strnstr ft_strdup ft_substr ft_isspace

SRCS = $(addsuffix .c, ${SRC})

OBJS = ${SRCS:.c=.o}

SRCSB =	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstclear ft_lstdelone ft_lstiter ft_lstmap $(SRC)
		
OBJECTS_BONUS_SUFFIX = $(addsuffix .c, ${SRCSB})

OBJSB = ${OBJECTS_BONUS_SUFFIX:.c=.o}

HEAD = ./includes/

NAME = libft.a

CC = cc

RM = rm -f

AR = ar rc

RN = ranlib

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RN) $(NAME)
	@clear
	
.c.o: 
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	 @$(RM) $(OBJS) $(OBJSB)

fclean: clean
	@$(RM) $(NAME)
	@clear

bonus: $(OBJSB)
	@$(AR) $(NAME) $(OBJSB)
	@$(RN) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus
