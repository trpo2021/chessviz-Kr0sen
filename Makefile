all: main.c
	gcc -g -Wall -Werror -o main main.c
clean:
	$(RM) main