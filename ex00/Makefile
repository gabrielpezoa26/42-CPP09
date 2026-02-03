NAME = btc
OBJECTS = objects/main.o objects/BitcoinExchange.o

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

objects/BitcoinExchange.o: BitcoinExchange.cpp
	$(CC) $(CFLAGS) -c BitcoinExchange.cpp -o objects/BitcoinExchange.o

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME) input.txt

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) input.txt

re: fclean all