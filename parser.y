%{
#include "all.h"
#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include "stack.h"
//#include "stack_arith.h"


extern FILE* yyin;
extern char* tempString;
struct Stack* tblptrStack;

void loadTmpVal(char * theTmp);
void saveTmpVal(char* theTmp);
void topPlsLoclNum(int quad);
char* mkString(char* input);
char* getRelop(char* str);
char* assignBool(Node * trueList , Node * falseList , char* var , bool isVar, bool mkItEval);
char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID);
char* functionCall(char* id , char * explist);
Eval* strToEval(char* input);
char * newQuad();
char * newTemp();
char * newVTemp();
char * newPTemp();
char * newITemp();
char* createLable();
void defaultGotoGen();
Eval * idToEval(char * idName);

char num[5];
int returnQuads[30];
int lastOfReturnQuad=0;
int tt=0;
int v=0;
int I=0;
int currentType;
char* returnType;
bool errorFlag=false;
int quadTmp;
struct SymbolTable* mainSymTbl;


int yylex();
void yyerror(char* error);

struct SymbolTable* secondArg(struct SymbolTable* a,struct SymbolTable* b );
void mkSymTblFncPrc(char * name);
%}

%union{
  char* strValue;
  struct eval* evalptr;
}
%start program
%type <evalptr> TRUE FALSE exp constant boolexp block stmt M PM stmtlist explist NS caseelement NP
%type <strValue> PLUS MINUS DIVISION MULTIPLY INTEGER REALNUM IDENTIFIER OPPAR CPAR relop GREATERTHAN GREATEREQUAL NOTEQUAL EQUAL LESSTHAN LESSEQUAL vardec idlist iddec INT REAL BOOL type dec declist program paramdecs paramdec paramlist lvalue funcdec procdec PROCEDURE FUNCTION
	
%token INTEGER
%token ZERO
%token REALNUM
%token PROGRAM
%token INT
%token REAL
%token BOOL
%token PROCEDURE
%token FUNCTION
%token BEGINN
%token END
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token FOR
%token TO
%token DOWNTO
%token CASE
%token RETURN
%token ANDTHEN
%token ORELSE
%token IDENTIFIER

%token MINUS
%token MULTIPLY
%token DIVISION
%token GREATERTHAN
%token GREATEREQUAL
%token NOTEQUAL
%token EQUAL
%token LESSTHAN
%token LESSEQUAL
%token COMMA
%token SEMICOLON
%token COLON
%token DECLARE
%token OPPAR
%token CPAR
%token FALSE
%token TRUE
%token ERROR
%left COMMA
%left INT BOOL REAL

%left COLON
%left IF_PREC
%left ELSE
%left ANDTHEN ORELSE
%left PLUS MINUS
%left MULTIPLY DIVISION
%left GREATERTHAN GREATEREQUAL NOTEQUAL EQUAL LESSTHAN LESSEQUAL

%%

program:
	PROGRAM IDENTIFIER PM SEMICOLON declist block M SEMICOLON {
		
		printf("\nin program\n");
		topPlsLoclNum( atoi( ((Eval*)$3)->str ) );
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		mainSymTbl = pop(tblptrStack);
		allSymbolTablePrint( mainSymTbl ); 
		backpatch( ((Eval*)$6)->nextList , ((Eval*)$7)->quad );
		emit("return" , "0" , "" , "" );
		
		$$ = $2;
	}
	| PROGRAM IDENTIFIER PM SEMICOLON block M SEMICOLON {
		printf("\nin program\n");
		topPlsLoclNum( atoi( ((Eval*)$3)->str ) );
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		mainSymTbl = pop(tblptrStack);
		allSymbolTablePrint( mainSymTbl );
		printf("this is program");
		backpatch( ((Eval*)$5)->nextList , ((Eval*)$6)->quad );
		emit("return" , "0" , "" , "" );
		
		printf("end of program\n");
		$$ = $2;
	}
	;
PM:
	{
		emit("//" , "program decleration:" , "" , "");
		snprintf(num,5,"%d",nextquad);
		emit("-" , "top" , "NA" , "top" );
		
		struct SymbolTable* t = mkTable( NULL , "program");
		push(t, tblptrStack);
		$$ = mkEval (0 ,0 ,0 , "" , mkString(num) );
	}
;
declist:
	dec {
		$$ = $1;
	}
	| declist dec {
		$$ = $1;
	}
	;
dec : 
	vardec {
		printf("var deccc");
		$$ = $1;
	}
	| procdec {
		$$ = $1;
	}
	| funcdec {
		$$ = $1;
	}
	;
type :
	INT {
		currentType=4;
		returnType = (char*) malloc(strlen("INT"));
		strcpy(returnType, "INT");
		printf("this is int");
		$$ = $1;
	}
	| REAL {
		currentType=8;
		returnType = (char*) malloc(strlen("REAL"));
		strcpy(returnType, "REAL");
		printf("this is real");
		$$ = $1;
	}
	|BOOL {
		currentType=1;
		returnType = (char*) malloc(strlen("BOOL"));
		strcpy(returnType, "BOOL");
		printf("this is bool\n");	
		$$ = $1;
	}
	;
iddec :
	IDENTIFIER {
		enterVar( $1, currentType , top(tblptrStack) ); printf("a variable entered:%s\n",$1);
		
		$$ = $1;
	}
	| IDENTIFIER {
		
		enterVar( $1 , currentType , top(tblptrStack) );
		
	}DECLARE exp {
		
		if( currentType > 1 && ((Eval*)$4)->str != 0 )
		{
			Eval* lvalueEval = idToEval($1);
			//DANGER
			emit("IP" , ((Eval*)$4)->str , "" , lvalueEval->str );
		}
		else if (currentType == 1)
		{
			assignBool( ((Eval*)$4)->trueList , ((Eval*)$4)->falseList, $1 , true ,true );
		}
		$$ = $1;
		printf("a variable entered:%s\n",$1); 
	}
	;
idlist : 
	iddec {
		$$ = $1;
	}
	| idlist COMMA iddec {
		$$ = $1;
	}
	;
vardec :
	type idlist SEMICOLON {
		printf("vardec");
		$$ = $1;
	}
	;
procdec :
	PROCEDURE IDENTIFIER NP OPPAR paramdecs CPAR M {
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "proc decleration:" , $2 , "");
		snprintf(num,5,"%d",nextquad);
		$1 = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
	}declist{
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		enterProcFunc( tmpc , 0 , "NULL" ,  tmpt , top(tblptrStack)  , ((Eval*)$7)->quad );
		push( tmpt , tblptrStack );

	} block M ret M  SEMICOLON {
		topPlsLoclNum(atoi($1));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)$3)->nextList , ((Eval*)$14)->quad );
		backpatch( ((Eval*)$11)->nextList , ((Eval*)$12)->quad );
		$$ = $2;
		
	}
	| PROCEDURE IDENTIFIER NP OPPAR paramdecs CPAR M{
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "proc decleration:" , $2 , "");
		snprintf(num,5,"%d",nextquad);
		$1 = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		enterProcFunc( tmpc , 0 , "NULL" ,  tmpt , top(tblptrStack)  , ((Eval*)$7)->quad );
		push( tmpt , tblptrStack );
	}block M ret M SEMICOLON { 
		topPlsLoclNum(atoi($1));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)$3)->nextList , ((Eval*)$12)->quad );
		backpatch( ((Eval*)$9)->nextList , ((Eval*)$10)->quad );
		$$ = $2;
		
	}
	;
funcdec :
	FUNCTION IDENTIFIER NP OPPAR paramdecs CPAR COLON type M{
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "func decleration:" , $2 , "");
		snprintf(num,5,"%d",nextquad);
		$1 = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
		printf("In Function declaration before declist\n");
	}declist {
		
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		//printf("after enterProcFunc\n");
		enterProcFunc(tmpc , -1 , returnType ,  tmpt , top(tblptrStack) , ((Eval*)$9)->quad );
		push( tmpt , tblptrStack );

	}block M ret M SEMICOLON{
		//printf("afterBlock in funcdec\n");
		topPlsLoclNum(atoi($1));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)$3)->nextList , ((Eval*)$16)->quad );
		//printf("BETWEEN in funcdec\n");
		backpatch( ((Eval*)$13)->nextList , ((Eval*)$14)->quad );
		//printf("AFTER in funcdec\n");
		$$ = $2;
		
		
	}
	| FUNCTION IDENTIFIER NP OPPAR paramdecs CPAR COLON type M{
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "func decleration:" , $2 , "");
		
		snprintf(num,5,"%d",nextquad);
		$1 = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
		
		//printf("after enterProcFunc\n");
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		//printf("after enterProcFunc\n");
		enterProcFunc(tmpc , -1 , returnType ,  tmpt , top(tblptrStack) , ((Eval*)$9)->quad );
		push( tmpt , tblptrStack );
		printf("funcdec after return type\n");
	}block M ret M SEMICOLON{
		//printf("after block in funcdec\n");
		topPlsLoclNum(atoi($1));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)$3)->nextList , ((Eval*)$14)->quad );
		backpatch( ((Eval*)$11)->nextList , ((Eval*)$12)->quad );
		$$ = $2;
		
	}
	;
ret:
	{
		char * tmpPointer = newPTemp();
		char * PPtmp = newVTemp();
		char * tmpPointerWithStar = (char*) malloc(strlen(tmpPointer)+1);
		strcpy(tmpPointerWithStar , "*");
		strcat( tmpPointerWithStar , tmpPointer );
		//returning
		emit("//" , "return" , "" , "");
		returnQuads[lastOfReturnQuad] = nextquad;
		lastOfReturnQuad++;
		emit("+" , "top" , "NA" , "top");
		emit("+" , "atop" , "1" , PPtmp);
		emit("PI" , PPtmp , "" , tmpPointer );
		emit("goto" , tmpPointerWithStar , "" , "");
	}
;
NP :
	{
		printf("starting reducing NP\n");
		mkSymTblFncPrc(tempString);
		$$ = mkEval(0 , 0 , mkList(nextquad) , "" , "");
		emit("goto" , "" , "" , "" );
	}
	;
paramdecs :
	paramdec { $$ = $1; printf("paramdecs\n"); }
	| paramdecs SEMICOLON paramdec { $$ = $1; printf("paramdecs\n"); }
	| { $$ = 0; printf("paramdecs\n"); }
	;
paramdec : 
	type paramlist {
		$$ = $1;
	}
	;
paramlist :
	IDENTIFIER {
		enterParam( $1, currentType , top(tblptrStack) ); printf("a variable entered:%s\n",$1); 
		$$ = $1;
	}
	| paramlist COMMA IDENTIFIER {
		enterParam( $3, currentType , top(tblptrStack) ); printf("a variable entered:%s\n",$3); 
		$$ = $3;
	}
	;
block : 
	BEGINN stmtlist END {
		
		$$ = mkEval (0 ,0 , ((Eval*)$2)->nextList , "" , "");
		printf("this is block \t nextList:%x\n" , ((Eval*)$2)->nextList );
		
	}
	| stmt {
		$$ = mkEval (0 ,0 ,((Eval*)$1)->nextList , "" , "");
		printf("this is block \t nextList:%x\n" , ((Eval*)$1)->nextList );
	}
	;
stmtlist : 
	stmt {
		//printf("BEFORE in : stmt to stmtlist:)\n");
		$$ = mkEval (0 ,0 , ((Eval*)$1)->nextList , "" , "");
		printf("in : stmt <to> stmtlist:\t nextLIst is:%x)\n",((Eval*)$1)->nextList );
	}
	| stmtlist SEMICOLON M stmt {
		printf("in : stmtlist SEMICOLON M stmt <to> stmtlist:\t nextLIst is:%x)\n",((Eval*)$4)->nextList );
		backpatch( ((Eval*)$1)->nextList , ((Eval*)$3)->quad );
		$$ = mkEval (0 ,0 , ((Eval*)$4)->nextList , "" , "");
	}
	;
lvalue : 
	IDENTIFIER {
		$$ = $1;
		printf("lvalue->identifier : %s\n", $1 );
	}
	;
stmt :
	lvalue DECLARE {
		printf("decleration (stmt)\n");
	}exp {
		
		printf("in : lvalue DECLARE exp to stmt\n");
		//if(lvalue)
		//int idSize = atoi( ((Eval*)$1)->quad );
		//printf("88888888888888888888888888idSize:%d \t address:%s\n" , idSize , ((Eval*)$1)->str );
		if( strcmp( ((Eval*)$4)->quad , "*" ) != 0 ){
			Eval* lvalueEval = idToEval($1);
			//DANGER
			emit("IP" , ((Eval*)$4)->str , "" , lvalueEval->str );
		}
		else{
			
			//printf("88888888888888888bool lvalue is assugning:\t%s\n" , lvalueEval->str);
			assignBool( ((Eval*)$4)->trueList , ((Eval*)$4)->falseList, $1 , true ,true );
		}
		$$ = mkEval(0,0,0,"","");
		
		
	}
	| IF exp THEN M block %prec IF_PREC {
		printf("stmt->if then\n");
		backpatch( ((Eval*)$2) ->trueList, ((Eval*)$4) ->quad);
		Node * tmp = mergeList ( ((Eval*)$2) ->falseList, ((Eval*)$5) ->nextList );
		$$=mkEval(0,0, tmp ,"","");
	}
	| IF exp THEN M block ELSE NS M block %prec ELSE{
		printf("BEGIN : IF exp THEN M block ELSE NS M block <TO> stmt\n");
		backpatch( ((Eval*)$2) ->trueList , ((Eval*)$4) ->quad );
		backpatch( ((Eval*)$2) ->falseList , ((Eval*)$8) ->quad );
		printf("in : IF exp THEN M block ELSE NS M block <TO> stmt\n");
		if( ((Eval*)$9) ->nextList == 0)
			printf("((Eval*)$9) ->nextList == 0\n");
		if( ((Eval*)$7) ->nextList == 0)
			printf("((Eval*)$7) ->nextList == 0\n");
		if( ((Eval*)$5) ->nextList == 0)
			printf("((Eval*)$5) ->nextList == 0\n");
		
		Node * tmp1=mergeList ( ((Eval*)$7) ->nextList , ((Eval*)$9) ->nextList );
		printf("in : IF exp THEN M block ELSE NS M block <TO> stmt\n");
		Node * tmp = mergeList ( ((Eval*)$5) ->nextList , tmp1);
		
		$$ = mkEval(0,0,tmp,"","");
		printf("FINISH : IF exp THEN M block ELSE NS M block <TO> stmt FINISHED\n");
		
	}
	| WHILE M exp DO M block {
		//printf("WHILE:\n");
		printf("in : WHILE M exp DO M block <TO> stmt\n");
		backpatch( ((Eval*)$6)->nextList , ((Eval*)$2)->quad );
		backpatch( ((Eval*)$3)->trueList , ((Eval*)$5)->quad );
		Node * tmp = mergeList ( ((Eval*)$3) ->falseList, ((Eval*)$6) ->nextList );
		$$ = mkEval( 0 ,0 , ((Eval*)$3)->falseList , "" , "");
		emit("goto", ((Eval*)$2) ->quad ,"" ,"");
	}
	
	| FOR lvalue DECLARE exp TO{
		printf("For to");
		if( strcmp( ((Eval*)$4)->quad , "*" ) != 0 ){
			Eval* lvalueEval = idToEval($2);
			//DANGER
			emit("IP" , ((Eval*)$4)->str , "" , lvalueEval->str );
		}
		else{
			//printf("88888888888888888bool lvalue is assugning:\t%s\n" , lvalueEval->str);
			assignBool( ((Eval*)$4)->trueList , ((Eval*)$4)->falseList, $2 , true ,true );
		}
	} M exp {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval($2);
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("if" , lvalueValue , ">" ,((Eval*)$8) ->str);
		
		//printf("((Eval*)$4) ->str : %s\t((Eval*)$2) ->str : %s\n",((Eval*)$4) ->str, $2 );
		((Eval*)$8) ->nextList = mkList(nextquad);
		emit("goto" , "" , "" , "" );
	}DO block M {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval($2);
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("+" , lvalueValue , "1" , lvalueValue );
		emit("IP" , lvalueValue , "" , lvalueEval->str );
		emit("goto" , ((Eval*)$7)->quad , "" , "" );
		backpatch ( ((Eval*)$11) ->nextList , ((Eval*)$12)->quad );
		Node * tmp = ((Eval*)$8) ->nextList ;
		$$ = mkEval( 0 , 0 , tmp , "" , "" );
	}
	
	| FOR lvalue DECLARE exp DOWNTO{
		
		printf("Downto is seen\n");
		if( strcmp( ((Eval*)$4)->quad , "*" ) != 0 ){
			printf("inside the if\n");
			Eval* lvalueEval = idToEval($2);
			emit("IP" , ((Eval*)$4)->str , "" , lvalueEval->str );
		}
		else{
			//printf("88888888888888888bool lvalue is assugning:\t%s\n" , lvalueEval->str);
			assignBool( ((Eval*)$4)->trueList , ((Eval*)$4)->falseList, $2 , true , true );
		}
		printf("For Downto\n");
		
	} M exp {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval($2);
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("if" , lvalueValue , "<" ,((Eval*)$8) ->str);
		
		((Eval*)$8) ->nextList = mkList(nextquad);
		emit("goto" , "" , "" , "" );
	}DO block M {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval($2);
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("-" , lvalueValue , "1" , lvalueValue );
		//printf("((Eval*)$6)->quad : ",((Eval*)$7)->quad);
		emit("IP" , lvalueValue , "" , lvalueEval->str );
		emit("goto" , ((Eval*)$7)->quad , "" , "" );
		backpatch ( ((Eval*)$11) ->nextList , ((Eval*)$12)->quad );
		Node * tmp = ((Eval*)$8) ->nextList ;
		$$ = mkEval( 0 , 0 , tmp , "" , "" );
	}
	
	| CASE exp {
		((Eval*)$2) -> nextList = mkList(nextquad);
		emit("goto" , "" ,"" , "" );
	}caseelement M END {
		backpatch( ((Eval*)$2)->nextList , ((Eval*)$5)->quad );
		char * casStr = ((Eval*)$4) ->str;
		char * casQuad = ((Eval*)$4) ->quad;
		char* strTmp = strtok( ((Eval*)$4) ->str , ",");
		char* quadTmp = strtok( ((Eval*)$4) ->quad , ",");
		while( strTmp != 0  &&  quadTmp != 0 )
		{
			casStr += strlen(strTmp) + 1 ;
			casQuad += strlen(quadTmp) + 1 ;
			
			emit("if" , ((Eval*)$2)->str , "==" , strTmp );
			emit("goto" , quadTmp , "" , "");
			strTmp = strtok( casStr , ",");
			quadTmp = strtok( casQuad , ",");
		}
		$$ = mkEval( 0 ,0 , ((Eval*)$4)->nextList , "" , "" );
	}
	
	| RETURN exp {
		printf("return\n");
		char * tmpPointer = newPTemp();
		//set return value
		emit("+" , "sp" , "1" , tmpPointer);
		//DANGER
		emit("IP" , ((Eval*)$2)->str , "" , tmpPointer);
		
	} ret {$$=mkEval(0 , 0 , 0 , "" , "");}
	
	| exp { $$=$1; printf("stmt exp\n");}
	;
NS:
	{
		$$ = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
		emit( "goto" ,"","","" );
	}
;
exp :
	exp ANDTHEN M exp {
		backpatch( ((Eval*)$1) ->trueList , ((Eval*)$3) ->quad);
		$$ = mkEval( ((Eval*)$4) ->trueList , mergeList( ((Eval*)$1)->falseList , ((Eval*)$4) ->falseList ) , 0 , "*" , "" );
	}
	| exp ORELSE M exp  {
		//printf("zero");
		backpatch( ((Eval*)$1) ->falseList , ((Eval*)$3) ->quad);
		//printf("first");
		$$ = mkEval( mergeList( ((Eval*)$1)->trueList , ((Eval*)$4) ->trueList ), ((Eval*)$4) ->falseList , 0 , "*" , "" );
		//printf("second");
	}
	| exp PLUS exp {
		//$2="+";
		$$=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)$1)->str);
		loadTmpVal(((Eval*)$3)->str);
		emit("+" , ((Eval*)$1)->str , ((Eval*)$3)->str , ((Eval*)$$)->str );
		saveTmpVal(((Eval*)$$)->str);
		//printf("--------------------------------------------------------\nexp PLUS exp\t$1:%s\t$2:%s\t$3:%s\n",((Eval*)$1)->str,$2,((Eval*)$3)->str);
		}
	| exp MINUS exp {
		//$2="-";
		$$=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)$1)->str);
		loadTmpVal(((Eval*)$3)->str);
		emit("-" , ((Eval*)$1)->str , ((Eval*)$3)->str , ((Eval*)$$)->str );
		saveTmpVal(((Eval*)$$)->str);
		//printf("--------------------------------------------------------\nexp MINUS exp\t$1:%s\t$2:%s\t$3:%s\n",$1,$2,$3);
	}
	| exp MULTIPLY exp {
		$$=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)$1)->str);
		loadTmpVal(((Eval*)$3)->str);
		emit("*" , ((Eval*)$1)->str , ((Eval*)$3)->str , ((Eval*)$$)->str );
		saveTmpVal(((Eval*)$$)->str);
	}
	| exp DIVISION exp {
		$$=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)$1)->str);
		loadTmpVal(((Eval*)$3)->str);
		emit("/" , ((Eval*)$1)->str , ((Eval*)$3)->str , ((Eval*)$$)->str );
		saveTmpVal(((Eval*)$$)->str);
	}
	| OPPAR exp CPAR {
		$$=$2;
	}
	| boolexp relop boolexp{
		//printf( "boolexp relop boolexp to exp : %s\n" , ((Eval*)$1) ->str );
		loadTmpVal( ((Eval*)$1) ->str );
		loadTmpVal( ((Eval*)$3) ->str );
		emit("if", ((Eval*)$1) ->str , getRelop($2) ,((Eval*)$3)->str );
		
		$$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
		defaultGotoGen();
		defaultGotoGen();
		
	}
	| constant {
		printf("exp->constant : %s\n" , $1 );
		$$ = $1;}
	| TRUE {
		$$ = mkEval( mkList(nextquad) , 0 , 0 , "*" , "true");
		defaultGotoGen();
		
	}
	| FALSE {
		$$ = mkEval( 0 , mkList(nextquad) , 0 , "*" , "false");
		defaultGotoGen();
		
	}
	| lvalue {
		Eval* lvalueEval = idToEval($1);
		int idSize = atoi( lvalueEval->quad );
		char * value = newTemp();
		emit("PI" , lvalueEval ->str , "" , value);
		saveTmpVal(value);
		if( idSize == 1)
		{	
			emit("if", value , "==" , "true" );
			$$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , value);
			defaultGotoGen();
			defaultGotoGen();
		}
		else
			$$ = mkEval( 0 , 0 , 0 , "" , value);
		printf("lvalue\n");
		
	}
	| IDENTIFIER OPPAR explist CPAR {
		//symbolTablePrint(top(tblptrStack) );
		$$ = mkEval( 0 , 0 , 0 , "" , functionCall ( $1 , ((Eval*)$3)->str ) );
	}
;
M:
{
	$$ = mkEval( 0 , 0 , 0 , createLable() , "");
}
;
constant :
	INTEGER {
		printf("Integer:%s\n",$1);
		$$=strToEval($1);
	}
	| REALNUM {
		printf("RealNum:%s\n",$1);
		$$=strToEval($1);
	}
;
boolexp:
	OPPAR exp CPAR { 
		char* str = ((Eval*)$2)->str;
		char* thequad = ((Eval*)$2)->quad;
		if(strcmp(thequad , "*") == 0 || strcmp(str , "true") == 0 || strcmp(str , "false") == 0)
		{
			char* newtemp  = newTemp() ;
			assignBool( ((Eval*)$2)->trueList , ((Eval*)$2)->falseList, newtemp ,true , true);
			$$ = mkEval(0 , 0 , 0 , "" , newtemp);
		}
		else
			$$ = ( Eval* )$2;
		
	} 
	| INTEGER {$$ = mkEval(0,0,0,"" , $1); }
	| REALNUM {$$ = mkEval(0,0,0,"" , $1); }
	| TRUE {$$ = mkEval(0,0,0,"" , "true"); }
	| FALSE {$$ = mkEval(0,0,0,"" , "false"); }
	| lvalue {

		Eval* lvalueEval = idToEval($1);
		char * value = newTemp();
		emit("PI" , lvalueEval ->str , "" , value);
		saveTmpVal(value);
		printf("boolexp->lvalue : %s\n",$1);
		$$ = mkEval( 0 , 0 , 0 , "" , value);
		printf("boolexp->lvalue : %s\n$$:%s|\n",$1,$$);
	}
	| IDENTIFIER OPPAR explist CPAR {
		$$ = mkEval( 0 , 0 , 0 , "" , functionCall( $1 , ((Eval*)$3)->str ) );
	}
;
caseelement : 
	INTEGER COLON M block SEMICOLON{
		Node* tmp = mergeList( mkList(nextquad) , ((Eval*)$4)->nextList );
		
		emit("goto" , "" ,"" ,"");
		$$ = mkEval(0 ,0, tmp , ((Eval*)$3) ->quad , $1);
	}
	| caseelement INTEGER COLON M block SEMICOLON{
		Node* tmp = mergeList( mkList(nextquad) ,((Eval*)$1)->nextList ) ;
		tmp = mergeList( tmp ,((Eval*)$5)->nextList );
		emit("goto" , "" ,"" ,"");
		
		char* quadTmp = strcat( ((Eval*)$1)->quad , "," );
		quadTmp = strcat( quadTmp , ((Eval*)$4)->quad );
		
		char* strTmp = strcat( ((Eval*)$1)->str , "," );
		strTmp = strcat( strTmp , $2 );
		
		$$ = mkEval(0 ,0, tmp , quadTmp , strTmp);
	}
	;
explist :
	exp {
		printf("explist->exp : %s\n", ((Eval*)$1)->str  );
		char* strTmp;
		if( strcmp( ((Eval*)$1)->str , "" ) )
			strTmp = strcat( ((Eval*)$1)->str , "," );
		else
		{
			char * mytmp = newTemp();
			assignBool(((Eval*)$1) ->trueList , ((Eval*)$1) ->falseList , mytmp , true , true );
			strTmp = strcat( mytmp , "," );
			
		}
		$$ = mkEval(0 , 0 , 0 , "" , strTmp);
		
	}
	| explist COMMA exp  {
		//char* strTmp = (char* ) malloc ( strlen(((Eval*)$3)->str) + strlen(((Eval*)$1)->str + 1 ) );
		char* strTmp = strcat( ((Eval*)$1)->str , "," );
		if( strcmp( ((Eval*)$3)->str , "" ) )
			strTmp = strcat( strTmp , ((Eval*)$3)->str );
		else
		{
			char * mytmp = newTemp();
			assignBool(((Eval*)$3) ->trueList , ((Eval*)$3) ->falseList , mytmp , true , true );
			strTmp = strcat( strTmp , mytmp );
		}
		$$ = mkEval(0 , 0 , 0 , "" , strTmp);
		
	}
	|{
		printf("explist->  \n");
		$$ = mkEval(0 , 0 , 0 , "" , "" );
	}
	;
relop :
	GREATERTHAN {$$=$1;}
	| GREATEREQUAL {$$=$1;}
	| NOTEQUAL {$$=$1;}
	| EQUAL {$$=$1;}
	| LESSTHAN {$$=$1;}
	| LESSEQUAL {$$=$1;}
	;



%%

int t=0;
int q=0;

void topPlsLoclNum(int quad)
{
	printf("in topPlsLoclNum()\n");
	snprintf(num,5,"%d",top(tblptrStack)->localNum );
	int i =0;
	printf("in topPlsLoclNum()\n");
  while(num[i]!='\0'){
   quad_ruples[quad][2][i] = num[i];
  i++;
  }  
  quad_ruples[quad][2][i] = num[i];
}

void loadTmpVal(char * theTmp){
	int *i = (int *) malloc( sizeof(int) );
	int *j = (int *) malloc( sizeof(int) );
	if( (theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true")==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
		return;
	char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
	emit( "PI" , addressOfStack , "" , theTmp );
}

void saveTmpVal(char* theTmp){
	if( (theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true" )==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
		return;
	int *i = (int *) malloc( sizeof(int) );
	int *j = (int *) malloc( sizeof(int) );
	printf("<<<<<<<<<<<<saveing temp value!>>>>>>>>>>>\t:%s\n",theTmp);
	char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
	
	emit("IP" , theTmp , "" , addressOfStack );
}

Eval * idToEval(char * idName){
	
	int * intsize = (int *) malloc(sizeof(int));
	int * scopeID = (int *) malloc(sizeof(int));
	char* tmp = lookup( idName ,top(tblptrStack) , intsize , scopeID );
	char * num = (char*) malloc( sizeof(char) * 3 ) ;
	itoa(*intsize, num , 10);
	//printf("lvalue to Identifier\tintSize:%d\tnum=%s\tthe addres is:%s\n", *intsize , num , tmp);
	if(tmp == 0)
	{
		yyerror("Variable is not Defined!!!!!!\t:'(");
		return 0;
	}
	else
		return mkEval( 0,0, 0 , num , tmp );
}

char* functionCall(char* id ,char * explist){
	//emit("=" , "top" , "" , "sp");
	printf("function call: %s \n" , id);
	//char * casStr = explist;
	char* strTmp = strtok( explist , "," );
	while( strTmp != 0 )//push variables
	{
		emit( "//" , "functioncall:" , id , "");
		//casStr += strlen(strTmp) + 1 ;
		emit( "-" , "top" , "1" , "top" );
		loadTmpVal(strTmp);
		emit("IP" , strTmp , "" , "top" );
		strTmp = strtok( NULL , ",");
	}
	int* size = (int*) malloc( sizeof(int) );
	int* scopeID = (int*) malloc( sizeof(int) );
	//symbolTablePrint(top(tblptrStack) );
	char* tmp = lookup(id , top(tblptrStack) , size , scopeID );
	//printf("size is : %d" , *size );
	if(*size>8)
	{
		char * retLabel= newQuad();
		char * retaddress = newPTemp();
		
		//push number of arguments
		emit("-" , "top" , "1" , "top");
		char* buff = (char*) malloc( sizeof(char) * 3 );
		itoa(*size - 9 , buff , 10);
		emit("IP" , buff , "" , "top" );
		
		//push return address
		emit("-" , "top" , "1" , "top");
		emit("&&" , retLabel , "" , retaddress);
		emit("-" , "atop" , "1" , "atop");
		emit("IP" , retaddress , "" , "atop");
		
		//push return value
		emit("-" , "top" , "1" , "top");
		
		//push sp
		emit("-" , "top" , "1" , "top");
		char* scopeid = (char*) malloc( sizeof(char) * 3 );
		itoa(*scopeID , scopeid , 10);
		emit("IP" , scopeid , "" , "top");
		emit("-" , "atop" , "1" , "atop");
		emit("IP" , "sp" , "" , "atop");
		
		//call
		emit("goto" , tmp , "" , "");
		emit( "//" , "return after func call" , "" , "");
		//return location
		emit( strcat(retLabel ,":") , "" , "" , "");
		
		//get return value
		char* returnValue = newTemp();
		emit("+" , "top" , "1" , "top");
		emit("PI" , "top" , "" , returnValue);
		//printf("size is : %d" , *size );
		
		//make every thing normal
			//setting top
			emit("+" , "top" , "2" , "top");
			char* argcount = newITemp();
			emit("PI" , "top" , "" , argcount);
			emit("+" , argcount , "1" , argcount);
			emit("+" , "top" , argcount , "top");
			//setting sp
			emit("PI" , "atop" , "" , "sp");
			//setting atop
			emit("+" , "atop" , "2" , "atop");
		emit( "//" , "every thing is normal after func call:" , id , "");
		saveTmpVal(returnValue);
		return returnValue;
	}
	else{
		printf("No such Function!!! : %s\n" , id);
		errorFlag = true;
		return 0;
	}
}

char* mkCodeFndVarScp(int id){
	char * scopeId = (char*) malloc(sizeof(char) *3);
	itoa(id , scopeId , 10);
	
	char * loop = newQuad();
	char * outOfLoop = newQuad();
	char * loopLabel = (char* ) malloc( strlen(loop)+1 );
	strcpy(loopLabel , loop);
	strcat(loopLabel , ":");
	
	char * outOfLoopLabel = (char* ) malloc( strlen(outOfLoop)+1 );
	strcpy(outOfLoopLabel , outOfLoop );
	strcat(outOfLoopLabel , ":");
	
	char* vPointer = newVTemp();
	char* pPointer = newPTemp();
	char* value = newTemp();
	
	emit("=" , "atop" , "" , vPointer);
	emit(loopLabel , "" ,"" ,"");
	emit("PI" , vPointer , "" , pPointer);
	emit("PI" , pPointer , "" , value);
	emit("if" , value , "==" , scopeId);
	emit("goto" , outOfLoop , "" , "");
	emit("+" , vPointer , "2" , vPointer );
	emit("goto" , loop , "" , "");
	emit(outOfLoopLabel , "" ,"" ,"");
	return pPointer;
}

char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID){
	
	bool isInside=true;
	struct SymbolTable* currentTbl = symbolTable;
	
	while(currentTbl != NULL){
		
		struct SymbolTableNode* currentNode = currentTbl->head;
		while(currentNode != NULL){
			//symbolTablePrint(currentTbl);
			//printf("variable is searched : %s ?= %s\n" , currentNode->name , name);
			
			if( strcmp( currentNode->name , name ) == 0 )
			{
				*size = currentNode->size;
				//printf("fuck the life!! %d \n", strcmp( currentNode->name , name ));
				//printf("the variable is found! : %s\t with size:%d\n" , name , *size);
				char* tblPtrTmp;
				
				
				if(*size >= 1 || *size==-2)
				{
					*scopeID = currentTbl->ID;
					if(isInside)
					{
						tblPtrTmp = newPTemp();
						if(currentNode->offset>0)
							emit("+" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						else
							emit("-" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						return tblPtrTmp;
					}
					else{
						tblPtrTmp = mkCodeFndVarScp(currentTbl->ID);
						if(currentNode->offset>0)
							emit("+" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						else
							emit("-" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						return tblPtrTmp;
					}
				}
				else{
					//printf("it is func or proc!\n");
					*scopeID = currentNode-> innerScope ->ID;
					*size = 9 + (currentNode->innerScope->argNum);
					return (currentNode->address);
				}
			}
			currentNode = currentNode->next;
		}
		currentTbl = currentTbl->outerScope;
		isInside = false;
		
	}
	printf("No such variable or Function!!! : %s\n" , name);
	
	errorFlag = true;
	return 0;
}

char * assignBool(Node * trueList , Node * falseList , char* name , bool isVar , bool mkItEval)
{
	char* var;
	
	char * quad3 = newQuad();
	if(trueList!=0){
		char * quad1 = createLable();
		
		if(mkItEval){
			Eval* lvalueEval = idToEval(name);
			var = lvalueEval->str;
		}
		else{
			var = (char*) malloc(strlen(name));
			strcpy(var , name);
		}
		if(isVar)
			emit ( "IP" , "true" , "" , var );
		else
			emit ( "=" , "true" , "" , var );
		
		backpatch( trueList , quad1 );
		emit ( "goto" , quad3 , "" , "" );
	}
	if(falseList!=0)
	{
		char * quad2 = newQuad();
		char * colonQuad2 = (char *)malloc( strlen(quad2) );
		strcpy(colonQuad2 , quad2);
		strcat(colonQuad2 , ":");
		emit ( colonQuad2 , "" , "" , "" );
		if(mkItEval){
			Eval* lvalueEval = idToEval(name);
			var = lvalueEval->str;
		}
		else{
			var = (char*) malloc(strlen(name));
			strcpy(var , name);
		}
		if(isVar)
			emit ( "IP" , "false" , "" , var );
		else
			emit ( "=" , "false" , "" , var );
		backpatch( falseList , quad2 );
		emit ( "goto" , quad3 , "" , "" );
	}
	
	char * colonQuad3 = (char *)malloc( strlen(quad3) );
	strcpy(colonQuad3 , quad3);
	strcat(colonQuad3 , ":");
	emit ( colonQuad3 , "" , "" , "" );
	return var;
}


void writeTmpVar(FILE * f)
{
	char defStr[10000];
	strcpy(defStr , "double ");
	
	
	for(int i = 0 ; i<t ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
		strcpy(tmp,  "t");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(t>0)
		fprintf(f, defStr );
	
	strcpy(defStr , "double ");
	
	for(int i = 0 ; i<tt ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("*tt")+sizeof(num) );
		strcpy(tmp,  "*tt");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(tt>0)
		fprintf(f, defStr );
	
	strcpy(defStr , "double ");
	for(int i = 0 ; i<v ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("**v")+sizeof(num) );
		strcpy(tmp,  "**v");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(v>0)
		fprintf(f, defStr );
	
	strcpy(defStr , "int ");
	for(int i = 0 ; i<I ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
		strcpy(tmp,  "i");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(I>0)
		fprintf(f, defStr );
}

void mkCfile()
{
	FILE * fp;
   /* open the file for writing*/
   fp = fopen ("intermediate.c","w");
   fprintf(fp,"#include <stdbool.h>\n");
   fprintf(fp,"#include <stdlib.h>\n");
   fprintf(fp,"#include <stdio.h>\n");
   
   fprintf(fp,"double * top;\n");
   fprintf(fp,"double * sp;\n");
   fprintf(fp,"double ** atop;\n");
   
   writeTmpVar(fp);
   //writeVar( mainSymTbl , 8 , fp );
   //writeVar( mainSymTbl , 4 , fp );
   //writeVar( mainSymTbl , 1 , fp );
   
   fprintf(fp,"int main() {\n");
   fprintf(fp,"top = (double *) malloc(sizeof(double) *10001);\n");
   fprintf(fp,"atop = (double **) malloc(sizeof(double*) *1001);\n");
   fprintf(fp,"top = top + 10000;\n");
   fprintf(fp,"atop = atop + 1000;\n");
   fprintf(fp,"sp = top;\n\n");
   fprintf(fp,"*top = 0;\n\n");
   
   for(int i=0; i<=nextquad-1; i++){
	   if( strcmpi( quad_ruples[i][0] , "if" ) == 0 )
		  fprintf(fp,"%s ( %s %s %s )\n",quad_ruples[i][0],quad_ruples[i][1],quad_ruples[i][2],quad_ruples[i][3]);
		else if(strcmpi( quad_ruples[i][0] , "goto" ) == 0 )
			fprintf(fp,"\t\t%s %s; \n",quad_ruples[i][0],quad_ruples[i][1]);
		else if(strcmpi( quad_ruples[i][0] , "=" ) == 0 )
			fprintf(fp,"\t%s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][0],quad_ruples[i][1]);
		else if(strcmpi( quad_ruples[i][0] , "+" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if(strcmpi( quad_ruples[i][0] , "-" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if(strcmpi( quad_ruples[i][0] , "*" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if(strcmpi( quad_ruples[i][0] , "/" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if( strstr( quad_ruples[i][0] , ":" ) != 0 )
			fprintf(fp,"%s\n", quad_ruples[i][0]);
		else if(strcmpi( quad_ruples[i][0] , "PI" ) == 0 )
			fprintf(fp,"\t%s = *%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
		else if(strcmpi( quad_ruples[i][0] , "IP" ) == 0 )
			fprintf(fp,"\t*%s = %s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
		else if(strcmpi( quad_ruples[i][0] , "&&" ) == 0 )
			fprintf(fp,"\t%s = &&%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
		else if(strcmpi( quad_ruples[i][0] , "//" ) == 0 )
			fprintf(fp,"//%s %s %s\n", quad_ruples[i][1] , quad_ruples[i][2] , quad_ruples[i][3] );
		
	}
	fprintf(fp,"return 0;\n");
	fprintf(fp,"}\n");
 
   /* close the file*/  
   fclose (fp);
}

char* getRelop(char* str){
	
	if( strcmp( str , ".GT.") == 0 )
		return mkString(">");
	else if ( strcmp( str , ".GE.") == 0 )
		return mkString(">=");
	else if ( strcmp( str , ".NE.") == 0 )
		return mkString("!=");
	else if ( strcmp( str , ".EQ.") == 0 )
		return mkString("==");
	else if ( strcmp( str , ".LT.") == 0 )
		return mkString("<");
	else if ( strcmp( str , ".LE.") == 0 )
		return mkString("<=");
}

void defaultGotoGen(){
	char * tmp = newQuad();
	emit("goto",tmp,"","");
	emit(strcat(tmp,":") , "" ,"" ,"");
}

char* mkString(char* input)
{
	char* string = (char*) malloc(strlen(input));
	strcpy(string , input);
	return string;
}

char * newQuad(){
	
  snprintf(num,5,"%d",q);
  char * tmp = (char*) malloc( sizeof("L")+sizeof(num) );
	strcpy(tmp,  "L");
  strcat(tmp,num);
  q++;
  return tmp;
  
}

char * newVTemp(){
	
  snprintf(num,5,"%d",v);
  char * tmp = (char*) malloc( sizeof("v")+sizeof(num) );
	strcpy(tmp,  "v");
  strcat(tmp,num);
  v++;
  return tmp;
}

char * newTemp(){
	
  snprintf(num,5,"%d",t);
  char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
	strcpy(tmp,  "t");
  strcat(tmp,num);
  tmp = mkString(tmp);
  //printf("newTmp() : |%s|\n", tmp);
  enterVar( tmp, -2 , top(tblptrStack) );
  t++;
  return tmp;
}

char * newPTemp(){
	
  snprintf(num,5,"%d",tt);
  char * tmp = (char*) malloc( sizeof("tt")+sizeof(num) );
	strcpy(tmp,  "tt");
  strcat(tmp,num);
  tt++;
  return tmp;
}

char * newITemp(){
	
  snprintf(num,5,"%d",I);
  char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
	strcpy(tmp,  "i");
  strcat(tmp,num);
  I++;
  return tmp;
}

char* createLable(){
	char * tmp = newQuad();
	char *ttmp = mkString(tmp);
	emit(strcat(ttmp,":") , "" ,"" ,"");
	return tmp;
}

Eval* strToEval(char* input){
	
	Eval* e = (Eval*) malloc (sizeof(Eval));
	char * string = (char*) malloc (strlen(input));
	strcpy(string , input);
	e->str = string;
	e->trueList = 0;
	e->falseList = 0;
	e->nextList = 0;
	e->quad = mkString("");
	return e;
}

void mkSymTblFncPrc(char * name)
{
	struct SymbolTable* t = mkTable( top(tblptrStack) , name );
	push(t, tblptrStack);
}

struct SymbolTable* popTop(struct Stack* b ){
	pop(b);
	top(b);
}

int main(){

	tblptrStack=createStack();
	tblptrStack->top = NULL;
	yyin = fopen("fibonachi.txt", "r");
	yyparse();
	if(errorFlag)
	{
		printf("!!!!!!!!OH!!!!!!!!! <<<<ERROR>>>> !!!!!!!!OH!!!!!!!!!! \t :'( /_\\");
	}
	quad_display();
	mkCfile();
	printf("------<<<<<<<***** FINISH *****>>>>>>------ :D *_*");
	return 0;
}

void yyerror(char* error){
	printf("Error : %s\n", error);
}