#include<stdio.h>
#include<stdlib.h>
int procE(char* inp ,int c);
int procF(char* inp ,int c);
int procT(char* inp ,int c);
int Eprime(char* inp,int c);
int Tprime(char* inp,int c);
int advance(char*  inp,int c);

int length(char inp[100]){
  int c=0;
  while(inp[c]!='\0')
	c+=1;
  return c;
}

void main(){
 char inp[100];
 printf("\nEnter input string:");
 scanf("%s",inp); 
 int c=0;
 c=procE(inp,c);
 int len=length(inp);
 printf("%d %d",len,c);

}


int procE(char* inp ,int c){
   c=procT(inp,c);
   c=Eprime(inp,c);
   return c;
}

int Eprime(char* inp ,int c){
   if(inp[c]=='+'){
      c=advance(inp,c);
      c=procT(inp,c);
      c=Eprime(inp,c);
   }
   return c;
}

int Tprime(char* inp ,int c){
   if(inp[c]=='*'){
      c=advance(inp,c);
      c=procF(inp,c);
      c=Tprime(inp,c);
   }
   return c;
}

int procF(char* inp ,int c){
   if(inp[c]=='i' && inp[c+1]=='d'){
      c=advance(inp,c);
      c=advance(inp,c);
   }
   else if(inp[c]=='('){
      c=advance(inp,c);
      c=procE(inp,c);
      if(inp[c]==')')
         c=advance(inp,c);
      else 
        {
	   printf("\nError");
	   exit(0);
        }
   }
   else 
        {
	   printf("\nError");
	   exit(0);
        }
   return c;
}

int procT(char* inp ,int c){
   c=procF(inp,c);
   c=Tprime(inp,c);
   return c;
}

int advance(char* inp,int c){
  c=c+1;
  return c;
}
