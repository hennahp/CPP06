NAME = identify
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

SRCS =	main.cpp \
		functions.cpp \
		Base.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!✅$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)Object files removed.🧹$(RESET)"	

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) executable removed.🗑️$(RESET)"
re: fclean all

.PHONY: all clean fclean re