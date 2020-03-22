%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
void yyerror(char *s);
int yylex(void);
int tc=1,cc=1,sc=0,nc=1;
%}

%token TERM RELOP OP WHILE DO SWITCH CASE DEFAULT BREAK
%union
{
   int intval;
   float floatval;
   char * str;
}
%type<str> TERM RELOP OP

%%
line:/* empty */
    | TERM '=' TERM OP TERM ';' 	{printf("t%d:=%s %s %s\n%s:=t%d\n",tc,$3,$4,$5,$1,tc);tc++;} line
    |WHILE TERM RELOP TERM DO '{'	{printf("if not  %s %s %s goto FALSE%d\nTRUE%d:\n",$2,$3,$4,cc,cc);}line
    '}'					{printf("goto TRUE%d\nFalse%d\n",cc,cc);cc++;}
    |SWITCH '(' TERM OP TERM ')' '{'    {printf("t%d:=%s %s %s\n",tc,$3,$4,$5);sc=tc;tc++;} cases
    '}'					{printf("NEXT%d",cc);cc++;} line
    |BREAK ';'				{printf("goto NEXT%d\n",cc);}

cases : CASE TERM ':'			{printf("CASE%d: if not t%d==%s goto CASE%d\n",nc,tc,$2,nc+1);nc++;}line cases
      | DEFAULT ':'			{printf("CASE%d:\n",nc);nc++;}line {printf("goto NEXT%d\n",cc);}

%%

void yyerror(char* s){
   printf("Syntax Error");
}

int main(){
yyparse();
return 1;
}
int yywrap(){

  return 1;
}
