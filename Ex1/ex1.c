#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int compare(char* s1,char*s2){
  if(strcmp(s1,s2)==0)
	return 0;
  else
	return 1;
}

int tokenfinder(char* str){
  int type=0;
  if(str[0]=='#')
	type=1;
  if(!strcmp(str,";") || !strcmp(str,",") ||!strcmp(str,"(") || !strcmp(str,")"))
	type=2;
  if(strstr(str,"{")!=NULL || strstr(str,"}")!=NULL)
	type=2;
  if(strstr(str,"int")!=NULL || strstr(str,"if")!=NULL || strstr(str,"void")!=NULL || strstr(str,"else")!=NULL)
	type=3; 
  if(strstr(str,"(")!=NULL && strstr(str,")")!=NULL)
	type=4;
  if(str[0]=='1' || str[0]=='2' || str[0]=='3' ||str[0]=='4' ||str[0]=='5' ||str[0]=='6' ||str[0]=='7' ||str[0]=='8' || str[0]=='9')
  { 
	//int c=atoi(str);
	//if(c>1 && c<65536)
		type=5;
  }
  
  if(type==0 && compare(str,"int") && compare(str,"void") && compare(str,"if") && compare(str,"else"))
	type=6;
  if(!strcmp(str,"="))
	type=7;
  if(!strcmp(str,">"))
	type=8;
  return type;
}

void main(){
   char name[100];
   char buff[1024];
   char *arr[200],*ar[200],*ans[200];
   for(int i=0;i<200;i++){
 	arr[i]=(char*)malloc(sizeof(char));
	ans[i]=(char*)malloc(sizeof(char));

  }
   
   printf("\nEnter filename:");
   scanf("%s",name);
   int fd=open(name,O_RDONLY);
   if(fd<0){
	printf("File not found!!\n");
	exit(0);
	}
   else
	read(fd,buff,1024);
   char * token=strtok(buff," ");
   int i=0,n;
   while(token!=NULL)
    {
	strcpy(arr[i],token);
	token=strtok(NULL," ");
	i++;
    }
    n=i;
    for(int i=0;i<n;i++){
	int res=tokenfinder(arr[i]);
        if(res==1)
		strcpy(ans[i],"preprocessor directive");
	if(res==2)
		strcpy(ans[i],"special character");   
	if(res==3)
                strcpy(ans[i],"keyword");
	if(res==4)
                strcpy(ans[i],"function call");
        if(res==5)
                strcpy(ans[i],"constant");
	if(res==6)
                strcpy(ans[i],"identifier");
	if(res==7)
                strcpy(ans[i],"assignment operator");
	if(res==8)
                strcpy(ans[i],"relational operator");

    }
    for(int i=0;i<n;i++)
	printf("%s\t\t%s\n",arr[i],ans[i]);
    char* id[10],*value[10];
    for(int i=0;i<10;i++)
	{
		id[i]=(char*)malloc(sizeof(char));
		value[i]=(char*)malloc(sizeof(char));
	}
    int c=0;
    for(int i=0;i<n;i++){
	if(strcmp(ans[i],"identifier")==0 && strcmp(ans[i+1],"assignment operator")==0)
		{
			id[c]=arr[i];
			value[c]=arr[i+2];
			c++;
		}
    }
    for(int i=0;i<c;i++)
	printf("\n\n%s\t%s",id[i],value[i]);
}
