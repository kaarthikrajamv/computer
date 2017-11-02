#include <stdio.h>

int bit=0,equal=0,semicolon=0,a=0,d=0,m=0,am=0;
char Ins[17];

void MemoryParser(char*);
void JumpParser(char*);
void OperationParser(char*);
void OPSetter(char,char,char,char,char,char);
void JPSetter(char,char,char);


char* CInstructionParser(char* CString){
	bit=equal=semicolon=a=d=m=am=0;
	Ins[0]='1';
	Ins[1]='1';
	Ins[2]='1';
	Ins[16]='\0';

	for (int i = 3; i < 16; ++i)
	{
		Ins[i]='0';
	}
	for (int i = 0; CString[i] != '\0' && CString[i] != '\\'; ++i)
	{
		if(CString[i]=='@'){
			printf("I'm a 'C' ; No 'A' plz\n");
		}
		if(CString[i]=='=')equal+=1;
		if(CString[i]==';')semicolon+=1;
	}
	if(equal==1)MemoryParser(CString);
	else if(equal)printf("How Many Equals Are you Planning in Your Operation\n");
	OperationParser(CString);
	if(semicolon==1)JumpParser(CString);
	else if(semicolon)printf("Plz Provide semicolon Only Between Operation and Jump.(No semicolon @END)\n");
	return Ins;
}

void MemoryParser(char* CString){
	while(CString[bit]!='='){

		switch(CString[bit]){
			case 'A':
			case 'a':{
					Ins[10]='1';
					if(a==0)a=1;
					else printf("Operation Tries to stores Value in A Register Multiple Times\n");
					break;
				}
			case 'M':
			case 'm':{
					Ins[12]='1';
					if(m==0)m=1;
					else printf("Operation Tries to stores Value in M[A] Multiple Times\n");
					break;
			}
			case 'D':
			case 'd':{
					Ins[11]='1';
					if(d==0)d=1;
					else printf("Operation Tries to stores Value in D Register Multiple Times\n");
					break;
			}
			default:{
					if(CString[bit]!=' ')printf("Error In Instruction Command\n");
					break;
			}
		}
		bit++;
	}
	bit++;
}
void JumpParser(char* CString){
	while(CString[bit] ==' ')bit++;
	if(CString[bit]=='j' || CString[bit]=='J'){
		bit++;
		switch(CString[bit]){
			case 'G':
			case 'g':{
					bit++;
					if(CString[bit]=='E' || CString[bit]=='e')
						JPSetter('0','1','1');
					else if(CString[bit]=='T' || CString[bit]=='t')
						JPSetter('0','0','1');
					else printf("Error Code\n");
					break;
				}
			case 'L':
			case 'l':{
					bit++;
					if(CString[bit]=='E' || CString[bit]=='e')
						JPSetter('1','1','0');
					else if(CString[bit]=='T' || CString[bit]=='t')
						JPSetter('1','0','0');
					else printf("Error Code\n");
					break;
				}
			case 'N':
			case 'n':{
					bit++;
					if(CString[bit]=='E' || CString[bit]=='e')
						JPSetter('1','0','1');
					else printf("Error Code\n");
					break;
				}
			case 'E':
			case 'e':{
					bit++;
					if(CString[bit]=='Q' || CString[bit]=='q')
						JPSetter('0','1','0');
					else printf("Error Code\n");
					break;
				}
			case 'M':
			case 'm':{
					bit++;
					if(CString[bit]=='P' || CString[bit]=='p')
						JPSetter('1','1','1');
					else printf("Error Code JMP\n");
					break;
				}
			default :{
					printf("Wrong Jump Statement Probably\n");
					break;
				}
		}
	}
	else{
		if(CString[bit]=='\0')printf("semicolon at end not required\n");
		else printf("Wrong Code\n");
	}
}
void OperationParser(char* CString){
	while(CString[bit]==' ')bit++;
	if(CString[bit]=='/' || CString[bit]==';'){
		printf("Main Operation of C Instruction Not Given \n");
		return;
	}
	switch(CString[bit]){
		case '0':{
				OPSetter('1','0','1','0','1','0');
				break;
			}
		case '1':{
				OPSetter('1','1','1','1','1','1');
				break;
			}
		case '-':{
				bit++;
				while(CString[bit]==' ')bit++;
				switch(CString[bit]){
					case '1':{
							OPSetter('1','1','1','0','1','0');
							break;
						}
					case 'd':
					case 'D':{
							OPSetter('0','0','1','1','1','1');
							break;
						}
					case 'M':
					case 'm':{
							Ins[3]='1';
						}
					case 'a':
					case 'A':{
							OPSetter('1','1','0','0','1','1');
							break;
						}
					default:{
							printf("Error in ops no value after '-'\n");
							break;
					}
				}
				break;
			}
		case '!':{
				bit++;
				while(CString[bit]==' ')bit++;
				switch(CString[bit]){
					case 'd':
					case 'D':{
							OPSetter('0','0','1','1','0','1');
							break;
						}
					case 'm':
					case 'M':{
							Ins[3]='1';
						}
					case 'a':
					case 'A':{
							OPSetter('1','1','0','0','0','1');
							break;
						}
					default:{
							printf("Error in ops no value after '!'\n");
							break;
					}
				}
				break;
			}
		case 'd':
		case 'D':{
				bit++;
				while(CString[bit]==' ')bit++;
				switch(CString[bit]){
					case '/':
					case '\0':
					case ';':{
							OPSetter('0','0','1','1','0','0');
							break;
						}
					case '+':{
							bit++;
							while(CString[bit]==' ')break;
							switch(CString[bit]){
								case '1':{
										OPSetter('0','1','1','1','1','1');
										break;
									}
								case 'M':
								case 'm':{
										Ins[3]='1';
									}
								case 'a':
								case 'A':{
										OPSetter('0','0','0','0','1','0');
										break;
									}

								default:{
										printf("D + What?\n");
										break;
									}
							}
							break;
						}
					case '-':{
							bit++;
							while(CString[bit]==' ')break;
							switch(CString[bit]){
								case '1':{
										OPSetter('0','0','1','1','1','0');
										break;
									}

								case 'M':
								case 'm':{
										Ins[3]='1';
									}
								case 'a':
								case 'A':{
										OPSetter('0','1','0','0','1','1');
										break;
									}
								default:{
										printf("D - What?\n");
										break;
									}
							}
							break;
						}
					case '&':{
							bit++;
							while(CString[bit]==' ')break;
							switch(CString[bit]){
								case 'M':
								case 'm':{
										Ins[3]='1';
									}								
								case 'a':
								case 'A':{
										OPSetter('0','0','0','0','0','0');
										break;
									}
								default:{
										printf("D & What?(A or M)\n");
										break;
									}
							}
							break;
						}
					case '|':{
							bit++;
							while(CString[bit]==' ')break;
							switch(CString[bit]){
								case 'M':
								case 'm':{
										Ins[3]='1';
									}
								case 'a':
								case 'A':{
										OPSetter('0','1','0','1','0','1');
										break;
									}
								default:{
										printf("D | What?(A or M)\n");
										break;
									}
							}
							break;
						}
					default:{
							printf("Error in ops no value after 'D'\n");
							break;
						}
				}
				break;
			}
		case 'M':
		case 'm':{
				Ins[3]='1';//NO break;
			}
		case 'a':
		case 'A':{
				bit++;
				while(CString[bit]==' ')bit++;
				switch(CString[bit]){
					case '/':
					case '\0':
					case ';':{
							OPSetter('1','1','0','0','0','0');
							break;
						}
					case '+':{
							bit++;
							while(CString[bit]==' ')break;
							switch(CString[bit]){
								case '1':{
										OPSetter('1','1','0','1','1','1');
										break;
									}
								default:{
										printf("A + What?\n");
										break;
									}
							}
							break;
						}
					case '-':{
							bit++;
							while(CString[bit]==' ')break;
							switch(CString[bit]){
								case '1':{
										OPSetter('1','1','0','0','1','0');
										break;
									}
								case 'D':
								case 'd':{
										OPSetter('0','0','0','1','1','1');
										break;
									}
								default:{
										printf("D - What?\n");
										break;
									}
							}
							break;
						}
					default:{
							printf("Error in ops no value after 'A'\n");
							break;
					}
				}
				break;
			}

			default: 
				printf("Error in C ops\n");
				break;
	}
	while(CString[bit] ==' ')bit++;
	bit++;
}
void OPSetter(char c1,char c2,char c3,char c4,char c5,char c6){
	Ins[4]=c1;
	Ins[5]=c2;
	Ins[6]=c3;
	Ins[7]=c4;
	Ins[8]=c5;
	Ins[9]=c6;
	return;
}
void JPSetter(char J1,char J2,char J3){
	Ins[13]=J1;
	Ins[14]=J2;
	Ins[15]=J3;
}

int main(int argc, char const *argv[])
{
	char arr[100];
	int c=1;
	printf("Just to test\n");
	while(c){
		scanf("%s", arr);
		printf("OUT%s\n", CInstructionParser(arr));
	}
	return 0;
}