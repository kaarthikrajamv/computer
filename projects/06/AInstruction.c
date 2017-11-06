#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


struct symbol{
	char symbol[30];
	int address;
}table[5000];

int current_address = 16;

char bitstring[16];
int hash(char ParsedString[])
{
	
	printf("%s\n",ParsedString);
	int address = 0;
	if(strcmp(ParsedString,"SP") == 0)
		return 16;
	if(strcmp(ParsedString,"LCL") == 0)
		return 17;
	if(strcmp(ParsedString,"ARG") == 0)
		return 18;
	if(strcmp(ParsedString,"THIS") == 0)
		return 19;
	if(strcmp(ParsedString,"THAT") == 0)
		return 20;
	if(strcmp(ParsedString,"SCREEN") == 0)
		return 21;
	if(strcmp(ParsedString,"KBD") == 0)
		return 22;
	if(strcmp(ParsedString,"R0") == 0)
		return 0;
	if(strcmp(ParsedString,"R1") == 0)
		return 1;
	if(strcmp(ParsedString,"R2") == 0)
		return 2;
	if(strcmp(ParsedString,"R3") == 0)
		return 3;
	if(strcmp(ParsedString,"R4") == 0)
		return 4;
	if(strcmp(ParsedString,"R5") == 0)
		return 5;
	if(strcmp(ParsedString,"R6") == 0)
		return 6;
	if(strcmp(ParsedString,"R7") == 0)
		return 7;
	if(strcmp(ParsedString,"R8") == 0)
		return 8;
	if(strcmp(ParsedString,"R9") == 0)
		return 9;
	if(strcmp(ParsedString,"R10") == 0)
		return 10;
	if(strcmp(ParsedString,"R11") == 0)
		return 11;
	if(strcmp(ParsedString,"R12") == 0)
		return 12;
	if(strcmp(ParsedString,"R13") == 0)
		return 13;
	if(strcmp(ParsedString,"R14") == 0)
		return 14;
	if(strcmp(ParsedString,"R15") == 0)
		return 15;

	for(int i=0;ParsedString[i]!='\0';i++)
		address += toascii(ParsedString[i]);
	return address;
}
void SymbolTableFiller()
{
	char str[100]; 
	for(int i=0;i<5000;i++)
		strcpy(table[i].symbol,"1");
	strcpy(table[16].symbol,"SP");
	table[16].address = 0;
	strcpy(table[17].symbol,"LCL");
	table[17].address = 1;
	strcpy(table[18].symbol,"ARG");
	table[18].address = 2;
	strcpy(table[19].symbol,"THIS");
	table[19].address = 3;
	strcpy(table[20].symbol,"THAT");
	table[20].address = 4;
	strcpy(table[21].symbol,"SCREEN");
	table[21].address = 16384;
	strcpy(table[22].symbol,"KBD");
	table[22].address = 	24576;

	strcpy(table[0].symbol,"R0");
	table[0].address =  0;
	strcpy(table[1].symbol,"R1");
	table[1].address =  1;	
	strcpy(table[2].symbol,"R2");
	table[2].address =  2;	
	strcpy(table[3].symbol,"R3");
	table[3].address =  3;	
	strcpy(table[4].symbol,"R4");
	table[4].address =  4;
	strcpy(table[5].symbol,"R5");
	table[5].address =  5;
	strcpy(table[6].symbol,"R6");
	table[6].address =  6;
	strcpy(table[7].symbol,"R7");
	table[7].address =  7;
	strcpy(table[8].symbol,"R8");
	table[8].address =  8;
	strcpy(table[9].symbol,"R9");
	table[9].address =  9;
	strcpy(table[10].symbol,"R10");
	table[10].address =  10;
	strcpy(table[11].symbol,"R11");
	table[11].address =  11;
	strcpy(table[12].symbol,"R12");
	table[12].address =  12;
	strcpy(table[13].symbol,"R13");
	table[13].address =  13;
	strcpy(table[14].symbol,"R14");
	table[14].address =  14;
	strcpy(table[15].symbol,"R15");
	table[15].address =  15;

	// for(int i=0;i<=15;i++)
	// {	;
	// 	// sprintf(str, "%d", i);
	// 	// printf("Inside S\n");

	// 	// strcpy(table[i].symbol,strcat("R",str));
	// 	// printf("Inside S\n");

	// 	// table[i].address = i;

	// 	// printf("Inside S1\n");

	// }
}
char* inttobin(int address)
{
	printf("Address %d\n",address);
	strcpy(bitstring,"0000000000000000");
	int i=15;
	while(address)
	{
		bitstring[i--] = (address%2 + 48);
		address /= 2;
	}
	return bitstring;
}	
char* AInstructionParser(char *String,int line)
{
	char ParsedString[100];
	int j=0,i;
	for(i=1;String[i]!=')' && String[i]!=' ' && String[i]!='\0' && String[i]!='\n' && String[i]!='\r';i++)
		ParsedString[j++] = String[i];
	ParsedString[j] = '\0';
	if(toascii(ParsedString[0]) >=48 && toascii(ParsedString[0])<=57)
	{
		printf("%d\n",atoi(ParsedString) );
		return inttobin(atoi(ParsedString));
	}
	printf("%d\n",hash(ParsedString));
	
	for(i=hash(ParsedString),j=0;table[i].symbol[0] != '1' && j <= 4999 ;i=(i + j/2 + j*j/2)%5000,j++)
	{
		printf("%s\n%s",table[i].symbol,ParsedString);
		if(strcmp(table[i].symbol,ParsedString) == 0)
		{
			printf("Inside if in for\n");
			return inttobin(table[i].address);
		}
	}

	strcpy(table[i].symbol,ParsedString);
	if(current_address == 16384 || current_address == 24576)
		current_address++;
	if(String[0] == '@')
		table[i].address = current_address++;
	else if(String[0] == '(')
		table[i].address = line;
	return inttobin(table[i].address);
}


