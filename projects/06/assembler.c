#include <stdio.h>
#include <string.h>
#include "AInstruction.c"
#include "CInstruction.c"
#include "Parser.c"
#define OUTFILE "Prog.hack"

char* CInstructionParser(char*);
void LabelParser(char*,int);
char* AInstructionParser(char*);
void RemoveSpacesandComments();
void printtable();

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
	SymbolTableFiller();
	FILE *rp = fopen(INFILE,"r");
	if(rp == NULL)
		exit(0);
	FILE *wp = fopen(OUTFILE,"w");
	while(fgets(str,100,rp))
	{
		if (str[0] == '(')
		{
				// printf("%d",LineCounter);
				LabelParser(str,LineCounter);
		}
		else if(str[0] != '\n' && str[0]!='\r')
		{
			LineCounter++;				
		}
	}
	fclose(rp);
	FILE *rp1 = fopen(INFILE,"r");
	printf("Hello\n");

	while(fgets(str,100,rp1))
	{
//		printf("%s\n",str );
		if(str[0] == '@' )
		{
			writestr = AInstructionParser(str);
			fprintf(wp,"%s\n",writestr);
		}
		else if(str[0] != '\n' && str[0]!='\r' && str[0] != '(')
		{
			// printf("Into C INs\n");
			writestr = CInstructionParser(str);
			fprintf(wp,"%s\n",writestr);
			// printf("Into C INs Finish\n");

		}
		else
			continue;
	}
	fclose(rp1);		
	fclose(wp);
	// printtable();		
}