all:
	make -C libft/ re
	gcc draw.c libft/libft.a -lncurses

clean:
	rm a.out

re: clean all
