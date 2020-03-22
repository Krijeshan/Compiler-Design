%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int yylex(void);
void yyerror(char* s); 
#include "y.tab.h"
%}
%token NUMBER
%%
program: line program
       | line
line: exp '\n' { printf("%d\n", $1); }
exp : exp '+' mx { $$ = $1 + $3; }
    | exp '-' mx { $$ = $1 - $3; }
    | mx { $$ = $1; }
mx   : mx '*' px { $$ = $1 * $3; }
     | mx '/' px { $$ = $1 / $3; }
     | px { $$ = $1; }
px   : px '^' term { $$ = pow($1, $3); }
     | term { $$ = $1; }
term: '(' exp ')' { $$ = $2; }
    | NUMBER { $$ = $1; }
%%
void yyerror(char* s)
{
  printf("\nSyntax error");
  return;
}
int yywrap()
{
  return 1;
}
int main()
{
  yyparse();
  return 0;
}
