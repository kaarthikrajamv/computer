#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFILE "Max.asm"

void RemoveSpacesfromLine(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

void RemoveSpacesandComments()
{
	char str[100];
	int flag1 = 0,p;
	FILE *fptr1,*fptr2;
	fptr1 = fopen(INFILE,"r");
	fptr2 = fopen("temp.txt","w+");
	char oldname[] = "temp.txt";
	while(fgets(str,100,fptr1)) 
	{
		int flag = 0;		
		int temp = strlen(str);
		if(str[0] == '\r')
			flag = 1;
		if((str[0] == '/' && (str[1] == '*' || str[1] == '/')) || str[0] == '*' && str[1] == '/')
			flag = 1;
		if(flag == 0 && flag1 == 0)
		{
			RemoveSpacesfromLine(str);
			if(str[0] != '\n')
				fprintf(fptr2,"%s",str);
		}	
		if((str[0] == '/' && str[1] == '*'))
			flag1 = 1;		
		if((str[0] == '*' && str[1] == '/') || (str[temp-3] == '*' && str[temp-2] == '/'))
			flag1 = 0;
		if((str[0] == '/' && str[1] == '*') && (str[temp-3] == '*' && str[temp-2] == '/'))
			flag1 = 0;		
	}	
	remove(INFILE);
	rename(oldname,INFILE);
	fclose(fptr1);
	fclose(fptr2);
}

// void fun()
// {
// 	FILE *fptr;
// 	fptr = fopen(SourceFile,"r");
// 	char str[100];
// 	while(fgets(str,100,fptr1)) 
// 	{
// 		if(str[0] != '(' && str[0] != '')
// 			LineCounter++;
// 		if(str[0] == '@' || str[0] == '(')
// 			AInstructionParser(str,LineCounter);
// 		else
// 			CInstructionParser(str);
// 	}
// }
