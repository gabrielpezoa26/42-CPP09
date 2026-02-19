NAME = RPN
OBJECTS = objects/main.o objects/RPN.o

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = objects

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

objects/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o objects/main.o

objects/RPN.o: RPN.cpp
	$(CC) $(CFLAGS) -c RPN.cpp -o objects/RPN.o

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)


run: all
	./$(NAME) "7 7 * 7 -"

run2: all
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

run3: all
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"

run4 : all
	./$(NAME) "(1 + 1)"

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

re: fclean all