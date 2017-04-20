all:
	flex parser.l
	bison -d parser.y
	gcc -c lex.yy.c
	gcc -o yadc lex.yy.o -lfl