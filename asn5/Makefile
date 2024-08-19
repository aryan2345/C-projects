CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = matrix.c bstree.c datatype.c main.c
OBJ = $(SRC:.c=.o)
EXEC = mymatrix

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)


