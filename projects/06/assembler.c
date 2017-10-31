#include <stdio.h>
#include <string.h>
#define INFILE "Add.asm"
#define OUTFILE "Add.hack"

struct hash{
	char *name;
	int address;
	struct hash *next;
};

typedef struct hash hash;

void func(char* p,int i)
{
	char *b;
	if(i==1)
		b="Hello Guys";
	else
		b="Hello";
}
void main()
{
	hash table[100];
	FILE *rp = fopen(INFILE,"r");
	FILE *wp = fopen(OUTFILE,"w");
	char a[1000];
	char *b;
	printf("%p\n",b );
	printf("%p\n",a );
	func(b,0);
	printf("%p\n",b );
	func(b,1);
	printf("%p\n",b );

	while(fgets(a,1000,rp))
	{
		printf("%s",a);
					
		break;
	}
		
}