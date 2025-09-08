CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++20

OBJS_DIR = obj
HDRS_DIR = inc/
HDRS = -I$(HDRS_DIR)

NAME = 
SRCS = srcs/main.cpp srcs/Fixed.cpp
OBJS = $(patsubst srcs/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling executable...$(RESET)"
	$(CXX) $(FLAGS) $(OBJS) $(HDRS) -o $(NAME)
	@echo "$(GREEN)COMPILATION COMPLETE!$(RESET)"

$(OBJS_DIR)/%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(FLAGS) $(HDRS) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning object files$(RESET)"
	rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(GREEN)Removing executable$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
