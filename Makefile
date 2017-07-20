all:
	make -C libft/ re
	gcc draw.c rain.c main.c textinput.c libft/libft.a -lncurses -std=gnu99

clean:
	rm a.out

re: clean all
