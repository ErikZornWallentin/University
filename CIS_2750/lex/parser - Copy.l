%{  
#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"

int charCount=0;
int wordCount=0;
int lineCount=0;

%}
%%

title            printf(" [TITLE]");
fields           printf(" [FIELDS]");
buttons          printf(" [BUTTONS]");
=                printf(" [EQUALS]");
[a-zA-Z0-9_]+    printf(" [WORD]\n");
;                printf(" [SEMICOLON]\n");
["]              printf(" [QUOTES]");
[{]              printf(" [OPEN-BRACKET]");
[}]              printf(" [CLOSE-BRACKET]");
[,]              printf(" [COMMA]\n");
[#]              printf(" [COMMENT]\n");
[ \t\n]+                  /* ignore whitespace */;

%%
main(argc, argv)
int argc;
char** argv;
{           
if (argc > 1)
{
    FILE *file;
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        exit(1);
    }
    yyin = file;
}

yylex();
//printf("%d   %d   %d\n", charCount, wordCount, lineCount);
}