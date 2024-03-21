

%{
#include <stdio.h>
int num_bytes=0;
%}


%%


68[a-f0-9]{8}c3		{ printf("WARNING! Tricky Jump: byte number: 0x%x\n", num_bytes); printf("%s", yytext); printf("\n\n"); num_bytes+=6; }


bc[a-f0-9]{8}31363126   { printf("WARNING! Cavalier Virus: byte number: 0x%x\n", num_bytes); printf("%s", yytext); printf("\n\n"); num_bytes+=9; }

89ec50583b45fe		{ printf("WARNING! Rotunda Virus: byte number: 0x%x\n", num_bytes); printf("%s", yytext); printf("\n\n"); num_bytes+=7; }


[a-f0-9]{2}		{ num_bytes+=1; }

. 			{ }

%%


int main() {
	yylex();
	return 0;
}


//int yywrap(){
//	return 1;
//}
