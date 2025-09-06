CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

OBJS_DIR = obj

NAME = sedLoser
SRCS = main.cpp
OBJS = $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling executable...$(RESET)"
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)COMPILATION COMPLETE!$(RESET)"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning object files$(RESET)"
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(GREEN)Removing executable$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
