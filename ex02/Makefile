NAME = PmergeMe
OBJECTS = objects/main.o objects/PmergeMe.o

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

objects/PmergeMe.o: PmergeMe.cpp
	$(CC) $(CFLAGS) -c PmergeMe.cpp -o objects/PmergeMe.o

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME) 3 5 9 7 4

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all