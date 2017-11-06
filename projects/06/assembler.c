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
	
	printf("After RemoveSpacesandComments()\n");
	SymbolTableFiller();
	printf("After SymbolTableFiller()\n");
	while(fgets(str,100,rp))
	{
		printf("%s\n",str );
		if(str[0] == '@' || str[0] == '(')
		{
			printf("Hello\n");

			writestr = AInstructionParser(str,LineCounter);
			printf("%s\n",writestr);
			fprintf(wp,"%s\n",writestr);
			if(str[0] == '@')
				LineCounter++;
		}
		else if(str[0] != '\n' && str[0]!='\r')
		{
			printf("Into C INs\n");
			writestr = CInstructionParser(str);
			fprintf(wp,"%s\n",writestr);
			LineCounter++;				
			printf("Into C INs Finish\n");

		}
		else
			continue;
	}		
}