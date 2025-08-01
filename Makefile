CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11 -g -pedantic
SRC = main.c error.c graph.c euler.c user_interface.c
EXEC = main

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)
	
run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
