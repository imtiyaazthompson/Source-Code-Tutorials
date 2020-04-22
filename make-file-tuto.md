# Makefiles Yo!
## Basics
```makefile
	<target>: file_1.c file_2.c file_3.c ...
		gcc -o <file name> <source files>
```

+ Make with
```
	make
```
Makes the first target

+ Make subsequent targets
```
	make <target>
```

+ Specify directories
```
	<target> ./src/file_1.c
		gcc -o ./bin/file_1_ex ./src/file_1.c
```
+ Use macros to store values
```
	SRC = ./src/
		<target> $(SRC)file_1.c
			...
```

+ Build multiple targets, must be on first line
```
	all: target_1 target_2 ... target_n
```

+ Using Macros
```
	CC = gcc
	CFLAGS = -Wall
	DEPS = primes.h
	OBJ = go.o primes.o

	%.o: %.c $(DEPS)
       		$(CC) $(CFLAGS) -c -o $@ $<

	go: $(OBJ)
        	gcc $(CFLAGS) -o $@ $^
```

+ RUN.SH
```
	make
	./bin/file
```
+ `chmod +x run.sh`
