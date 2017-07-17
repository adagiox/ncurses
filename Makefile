
all:
	gcc draw.c -lncurses
	./a.out

clean:
	rm a.out

re: clean all
