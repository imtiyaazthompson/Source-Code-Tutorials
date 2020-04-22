SRC = ./src/
BIN = ./bin/
$(shell mkdir -p $(SRC))
$(shell mkdir -p $(BIN))

CC = gcc
CFLAGS = -g -w
LFLAGS = -lSDL2

all: client

window: $(SRC)window.c
	$(CC) $(CFLAGS) -o $(BIN)windowSDL $(SRC)window.c $(LFLAGS)

client: $(SRC)display.c $(SRC)client.c
	$(CC) $(CFLAGS) -o $(BIN)clientSDL $(SRC)display.c $(SRC)client.c $(LFLAGS)
