%{
#include<stdio.h>
#include<stdlib.h>
%}

key	("int"|"void"|"if"|"else"|"return")
spec    ("{"|"}"|"("|")"|";"|",")
identifier [a-zA-z][a-zA-Z0-9\_]*
string  [a-zA-Z\_]+
%%

#.*				{printf("%s\tpreprocessor directive\n",yytext);}
{key}				{printf("%s\tkeyword\n",yytext);}
{string}\(\)			{printf("%s\tfunction call\n",yytext);}
{string}\(\"{string}\"\)	{printf("%s\tfunction call\n",yytext);}
{identifier}			{printf("%s\tidentifier\n",yytext);}
{spec}				{printf("%s\tspecial character\n",yytext);}
\=				{printf("%s\tassignment operator\n",yytext);}
\>				{printf("%s\toperator",yytext);}
[0-9]+				{printf("%s\tconstant",yytext);}
%%

int main(){
  FILE* file;
  file=fopen("input.txt","r");
  if(!file){printf("file not found\n");exit(0);}
  yyin=file;
  yylex();
  return 0;

}
int yywrap(){
return 1;
}
