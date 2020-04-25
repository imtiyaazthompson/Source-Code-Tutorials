KT = kotlinc
FLAGS = -include-runtime -d
SRC = src/
BIN = bin/

all: hello

hello: $(SRC)hello.kt
	$(KT) $(SRC)hello.kt $(FLAGS) $(BIN)hello.jar
