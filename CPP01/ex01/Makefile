CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

OBJS_DIR = obj
HDRS_DIR = inc/
HDRS = -I$(HDRS_DIR)

NAME = Zombie
SRCS = srcs/main.cpp srcs/Zombie.cpp srcs/zombieHorde.cpp
OBJS = $(patsubst srcs/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling executable...$(RESET)"
	$(CXX) $(FLAGS) $(OBJS) $(HRDS) -o $(NAME)
	@echo "$(GREEN)COMPILATION COMPLETE!$(RESET)"

$(OBJS_DIR)/%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(FLAGS) $(HRDS) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning object files$(RESET)"
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(GREEN)Removing executable$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
