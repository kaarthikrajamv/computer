#include <stdio.h>
#include <string.h>
#define INFILE "Add.asm"
#define OUTFILE "Add.hack"

char* CinstructionParser();
char* AinstructionParser();
void RemoveSpacesandComments();

int LineCounter = 0;

struct hash{
	char *name;
	int address;
	struct hash *next;
};
typedef struct hash hash;

void main()
{
	FILE *rp = fopen(INFILE,"r");
	FILE *wp = fopen(OUTFILE,"w");
	char str[100];
	char writestr[100];

	RemoveSpacesandComments();

	while(fgets(str,100,rp))
	{
		if(str[0] == '@' || str[0] == '(')
		{
			writestr = AinstructionParser(str,LineCounter);
			fprintf(wp,"%s\n",writestr);
		}
		else if(str[0] != '\n')
		{
			writestr = CinstructionParser(str);
			fprintf(wp,"%s\n",writestr);				
		}
		else
			continue;
	}		
}