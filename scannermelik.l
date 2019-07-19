%{
//#include "all.h"
#include<stdbool.h>
#include <stdlib.h>
#include <string.h>
//#include "LinkedList.h"
#include "parser.tab.h"
char* tempString;
char* string;

typedef struct eval Eval;

char* mkStr(char* input)
{
	char* string = (char*) malloc(strlen(input));
	strcpy(string , input);
	return string;
}


%}
%option yylineno

whole	0|[1-9][0-9]*
real	{whole}\.(([0-9])|([0-9][0-9]*[1-9]))
divisionop [/]
noSymbol	[^ \t\n\/\+\-\*\:\;\,\(\)\.]
error	{noSymbol}+

%%


[ \t\n\r]+	;



\#[-+]?{whole}/[\ :\,\;\+\-\/\*\)\n\r]|".GT."|".GE."|".EQ."|".NE."|".LT."|".LE."|":="	{
	
	char* string = (char*) malloc(strlen(yytext)-1);
	strcpy(string, yytext + 1);
	string[strlen(string)] = 0;
	yylval.strValue=string;
	printf("Found integer : %s\n", string);
	//push(string,INTEGER,yylineno);
	return INTEGER;}


\#[-+]?{real}/[\ :\,\;\+\-\/\*\)\n\r]|".GT."|".GE."|".EQ."|".NE."|".LT."|".LE."|":="	{
	char* string = (char*) malloc(strlen(yytext-1));
	strcpy(string, yytext + 1);
	string[strlen(string)] = 0;
	yylval.strValue=string;
	//printf("Found real:%s\n",string);
	//push(string,REAL,0);
	return REALNUM;
}

[a-zA-Z][0-9][0-9a-zA-Z]*	{
	printf("Found identifier:%s\n",yytext);
	//yylval.str = yytext;
	//printf("****lvalue is:%s\n",yylval.strValue);
	//push(yytext,IDENTIFIER,yylineno);
	tempString = (char*) malloc(strlen(yytext));
	strcpy(tempString, yytext);
	yylval.strValue = tempString;
	//printf("****lvalue is:%s\n",string);
	return IDENTIFIER;
}

Program	{
	//printf("Found program :%s\n",yytext);
	yylval.strValue=mkStr("Program");
	return PROGRAM;

}

Int	{
	//printf("Found int :%s\n",yytext);
	yylval.strValue=mkStr("Int");
	return INT;

}

Real	{
	//printf("Found real :%s\n",yytext);
	yylval.strValue=mkStr("Real");
	return REAL;

}

Bool	{
	//printf("Found bool :%s\n",yytext);
	yylval.strValue=mkStr("Bool");
	return BOOL;

}

Procedure	{
	//printf("Found real :%s\n",yytext);
	yylval.strValue=mkStr("Procedure");
	return PROCEDURE;

}

Function	{
	//printf("Found function :%s\n",yytext);
	yylval.strValue=mkStr("Function");
	return FUNCTION;

}

Begin	{
	//printf("Found begin :%s\n",yytext);
	yylval.strValue=mkStr("Begin");
	return BEGINN;

}

End {
	//printf("Found end :%s\n",yytext);
	yylval.strValue=mkStr("End");
	return END;

}

If 	{
	//printf("Found if :%s\n",yytext);
	yylval.strValue=mkStr("If");
	return IF;
}

Then {
	//printf("Found then :%s\n",yytext);
	yylval.strValue=mkStr("Then");
	return THEN;

}

Else {
	//printf("Found else :%s\n",yytext);
	yylval.strValue=mkStr("Else");
	return ELSE;
}

While {
	//printf("Found while :%s\n",yytext);
	yylval.strValue=mkStr("While");
	return WHILE;
}

Do {
	//printf("Found do :%s\n",yytext);
	yylval.strValue=mkStr("Do");
	return DO;
}

For {
	printf("\t\t\tFound for :%s\n",yytext);
	yylval.strValue=mkStr("For");
	return FOR;
}

To {
	printf("Found to :%s\n",yytext);
	yylval.strValue=mkStr("To");
	return TO;
}

Downto {
	//printf("Found downto :%s\n",yytext);
	yylval.strValue=mkStr("Downto");
	return DOWNTO;
}

Case {
	//printf("Found case :%s\n",yytext);
	yylval.strValue=mkStr("Case");
	return CASE;
}

Return {
	//printf("Found return :%s\n",yytext);
	yylval.strValue=mkStr("Return");
	return RETURN;
}

"And Then" {
	//printf("Found andthen :%s\n",yytext);
	yylval.strValue=mkStr("And Then");
	//push(yytext,ANDTHEN,yylineno);
	return ANDTHEN;
}

"Or Else" {
	//printf("Found andthen :%s\n",yytext);
	//push(yytext,ORELSE,yylineno);
	yylval.strValue=mkStr("Or Else");
	return ORELSE;
}

"+"	{
	//printf("Found plus :%s\n",yytext);
	yylval.strValue=mkStr("+");
	return (PLUS);
}

"-"	{
	//printf("Found minus :%s\n",yytext);
	yylval.strValue=mkStr("-");
	return (MINUS);

}

\*	{
	//printf("Found multiply :%s\n",yytext);
	yylval.strValue=mkStr("*");
	return MULTIPLY;
}

{divisionop}	{
	//printf("Found divis++++++@@@@@@@ion :%s\n",yytext);
	//push(yytext,DIVISION,yylineno);
	char* string = (char*) malloc(strlen("/"));
	strcpy(string , "/");
	yylval.strValue = string;
	return DIVISION;
}

".GT."	{
	//printf("Found greaterthan :%s\n",yytext);
	yylval.strValue=mkStr(".GT.");
	return GREATERTHAN;
}

".GE."	{
	//printf("Found greaterequal :%s\n",yytext);
	yylval.strValue=mkStr(".GE.");
	return GREATEREQUAL;
}

\.NE\.	{
	//printf("Found notequal :%s\n",yytext);
	yylval.strValue=mkStr(".NE.");
	return NOTEQUAL;
}

\.EQ\.	{
	//printf("Found EQUAL :%s\n",yytext);
	yylval.strValue=mkStr(".EQ.");
	return EQUAL;
}

\.LT\.	{
	//printf("Found lessthan :%s\n",yytext);
	yylval.strValue=mkStr(".LT.");
	return LESSTHAN;
}

\.LE\.	{
	//printf("Found lessequal :%s\n",yytext);
	
	yylval.strValue=mkStr(".LE.");
	return LESSEQUAL;
}

[,]	{
	//printf("Found comma :%s\n",yytext);
	yylval.strValue=mkStr(",");
	return COMMA;
}

":="	{
	printf("Found declare :%s\n",yytext);
	yylval.strValue=mkStr(":=");
	return DECLARE;
}

[:]	{
	//printf("Found semicolon :%s\n",yytext);
	
	yylval.strValue=mkStr(":");
	return COLON;
}

[;]	{
	//printf("Found semicolon :%s\n",yytext);
	yylval.strValue = mkStr(";");
	return SEMICOLON;
}


"(" {
	//printf("\n\n\t\tFound oppar :%s\n",yytext);
	yylval.strValue = mkStr("(");
	return OPPAR;

}

")"	{
	//printf("Found cppar :%s\n",yytext);
	yylval.strValue = mkStr(")");
	return CPAR;
}

False	{
	//printf("Found false :%s\n",yytext);
	return FALSE;
}

True	{
	//printf("Found true :%s\n",yytext);
	return TRUE;
}

{error}	{
	printf("Error on : **<<  %s  >>**\n", yytext);
	//yymore();
}
\.	{
	printf("Error on : **<<  illegal use of \" %s \" >>**\n", yytext);
	//yymore();
}

%%


int yywrap(){
	return 1;
}

//int main(){
//	yyin = fopen("input2P.txt", "r");
//	initLinkedList(table);
//	while(yylex());
//	printLinkedList();
//	return 0;
//}