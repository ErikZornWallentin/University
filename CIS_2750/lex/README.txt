COMPILE LEX: NAME.l FILE
-flex name.l   OR lex name.l  --> lex.yy.c

CREATE OBJECT FILE FOR other files: 
- gcc -c lex.yy.c --> lex.yy.o

COMPILE IT TO EXECUTEABLE:
- gcc -o test lex.yy.o -lfl

EXECUTABLE IS NOW CALLED: test.exe