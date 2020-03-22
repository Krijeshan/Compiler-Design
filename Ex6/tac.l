%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "y.tab.h"
%}

term	([a-zA-Z][a-zA-Z0-9\_]*|[0-9]+)
relop	("<"|"<"|"=="|"!=")
op	("+"|"-"|"*"|"/")
%%

"while"		{return WHILE;}
"do"		{return DO;}
"switch"	{return SWITCH;}
"case"		{return CASE;}
"default"	{return DEFAULT;}
"break"		{return BREAK;}
{term}		{yylval.str=strdup(yytext);return TERM;}
{relop}		{yylval.str=strdup(yytext);return RELOP;}
{op}		{yylval.str=strdup(yytext);return OP;}
[ \t\n]		{ }
.		{return *yytext;}
%%
