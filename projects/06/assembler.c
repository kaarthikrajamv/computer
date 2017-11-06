#include <stdio.h>
#include <string.h>
#include "AInstruction.c"
#include "CInstruction.c"
#include "Parser.c"
#define INFILE "Max.asm"
#define OUTFILE "Add.hack"

char* CInstructionParser(char*);
char* AInstructionParser(char*,int);
void RemoveSpacesandComments();


int LineCounter = 0;

// struct hash{
// 	char *name;
// 	int address;
// 	struct hash *next;
// };
// typedef struct hash hash;

void main()
{
	char str[100];
	char *writestr;

	RemoveSpacesandComments();
	FILE *rp = fopen(INFILE,"r");
	FILE *wp = fopen(OUTFILE,"w");
	while(fgets(str,100,rp))
	{
		if(str[0] == '@' || str[0] == '(')
		{
			if (str[0] == '(')
			{
				printf("%d",LineCounter);
				AInstructionParser(str,LineCounter);
			}
			if(str[0] == '@')
				LineCounter++;
		}
		else if(str[0] != '\n' && str[0]!='\r')
		{
			LineCounter++;				
		}
	}
	fclose(rp);
	FILE *rp1 = fopen(INFILE,"r");

	printf("After RemoveSpacesandComments()\n");
	SymbolTableFiller();
	printf("After SymbolTableFiller()\n");
	while(fgets(str,100,rp1))
	{
//		printf("%s\n",str );
		if(str[0] == '@' || str[0] == '(')
		{
			writestr = AInstructionParser(str,LineCounter);
			printf("%s\n",writestr);
			fprintf(wp,"%s\n",writestr);
		}
		else if(str[0] != '\n' && str[0]!='\r')
		{
			printf("Into C INs\n");
			writestr = CInstructionParser(str);
			fprintf(wp,"%s\n",writestr);
			printf("Into C INs Finish\n");

		}
		else
			continue;
	}		
}