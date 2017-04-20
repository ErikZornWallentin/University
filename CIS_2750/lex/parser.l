%{  
#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"

int charCount=0;
int wordCount=0;
int lineCount=0;
//[a-zA-Z]+  { yylval=strdup(yytext); return STRING; }
%}
%%

title            return TITLE;
fields           return FIELDS;
buttons          return BUTTONS;
=                return EQUALS;
[a-zA-Z0-9_]+    printf(" [WORD]\n");
;                return SEMICOLON;
["]              return QUOTES;
[{]              return OPENBRACKET;
[}]              return CLOSEBRACKET;
[,]              return COMMA;
[#]              return COMMENT;
[ \t\n]+                  /* ignore whitespace */;

%%