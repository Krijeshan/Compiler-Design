#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
  int n;
  printf("\nEnter the no od productions");
  scanf("%d",&n);
  char *ans[100];
  for(int i=0;i<100;i++)
	ans[i]=(char*)malloc(25*sizeof(char));
  int c=0;
  for(int i=0;i<n;i++)
  {
   	printf("\nEnter the production:");
   	char pro[100],bup[100],lhs[20],rhs[20];
   	scanf("%s",pro);
        strcpy(bup,pro);
   	char* token=strtok(pro,"->");
   	strcpy(lhs,token);
   	while(token!=NULL){
   	  strcpy(rhs,token);
   	  token=strtok(NULL,"->");	
  	}
  	if(lhs[0]==rhs[0])
  	{
  	      char l[10],r[10],p1[10],p2[10];      
		char *t=strtok(rhs,"|");
  	      strcpy(l,t);
  	      while(t!=NULL){
			strcpy(r,t);
			t=strtok(NULL,"|");
  	      }
		//printf("%s %s ",l,r);
  	      strcpy(p1,lhs);
  	      strcat(strcat(strcat(strcat(p1,"->"),r),lhs),"'");
		//printf("%s\n",p1);
  	      strcpy(p2,lhs);
		strcat(strcat(p2,"'"),"->");
  	      char b[10];
  	      strcpy(b,l);
		b[0]=' ';
  	      strcat(strcat(strcat(strcat(p2,b),lhs),"'"),"|E");
  	      //printf("%s\n",p2);;
              strcpy(ans[c],p1);
              c++;
              strcpy(ans[c],p2);
	      c++;
  	}
  	else
  	{
  	   char p3[10];
  	   strcpy(p3,bup);
  	   strcpy(ans[c],p3);
	   c++;
  	}

   }


  for(int i=0;i<c;i++)
	printf("%s\n",ans[i]);



}	
