%{
#include <stdlib.h>
#define YYSTYPE char *
char mode[20];
char state[20];
%}

%token TITLE FIELDS BUTTONS EQUALS STRING WORD SEMICOLON QUOTES OPENBRACKET CLOSEBRACKET COMMA COMMENT SET STATE MODE GET EOLN
%%
list:   /* nothing */
        | list getorset
        ;
getorset: getvalue 
         | setvalue 
         ;
setvalue: 
        SET STATE STRING  { strcpy(state,$3); printf("State set\n"); }
        | SET MODE STRING { strcpy(mode,$3); printf("Mode set\n"); }
        ;
getvalue: 
        GET STATE  { printf("State: %s\n",state); }
        | GET MODE { printf("Mode: %s\n",mode); }
        ;

%%

#include <stdio.h>
#include <ctype.ha>
char *progname;

main( argc, argv )
char *argv[];
{
  progname = argv[0];
  yyparse();
}

yyerror( s )
char *s;
{
  fprintf( stderr ,"%s: %s\n" , progname , s );
}
