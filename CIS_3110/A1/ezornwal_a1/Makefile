all: shell
shell: shell.o lex.yy.o
	gcc -o shell shell.o lex.yy.o -lfl
shell.o: shell.c
	gcc -Wall -g -c shell.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c
lex.yy.c: lex.c
	flex lex.c
clean:
	rm -f *.o
	rm -f lex.yy.c
	rm -f shell
	
