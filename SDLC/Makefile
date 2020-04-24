SRC = ./src/
BIN = ./bin/
$(shell mkdir -p $(SRC))
$(shell mkdir -p $(BIN))

CC = gcc
CFLAGS = -g -w
LFLAGS = -lSDL2 -lSDL2_image

all: client

window: $(SRC)window.c
	$(CC) $(CFLAGS) -o $(BIN)windowSDL $(SRC)window.c $(LFLAGS)

client: $(SRC)render.c $(SRC)load_media.c $(SRC)display.c $(SRC)client.c
	$(CC) $(CFLAGS) -o $(BIN)clientSDL $(SRC)render.c $(SRC)load_media.c $(SRC)display.c $(SRC)client.c $(LFLAGS)
