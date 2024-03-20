

%{
#include <stdio.h>
int num_bytes=0;
%}


%%


68[a-f0-9]{8}c3		{ printf("WARNING! Trick Jump: byte number: 0x%x\n", num_bytes); printf("%s", yytext); printf("\n \n"); num_bytes+=6; }

[a-f0-9]		{ num_bytes+=1; }

. 			{ printf("error, matched the period"); }

%%


int main() {
	yylex();
	return 0;
}


//int yywrap(){
//	return 1;
//}
