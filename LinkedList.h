struct Node{
	char* token;
	char* lexeme;
	int lineNum;
	struct Node* next;
	struct Node * prev;
	float attribute;
};
struct LinkedList{
	struct Node* lastNode;
	struct Node * firstNode;
} table;

void initLinkedList(struct LinkedList t)
{
	t.lastNode=0;
	t.firstNode=0;
}

void push(char* l , char* t , int lN, float atr){
	//printf("push shod\n");
	struct Node * tmp = (struct Node*) malloc(sizeof(struct Node));
	char* tt = (char*) malloc (sizeof(t));
	strcpy(tt,t);
	tmp->token=tt;
	//tmp->lexeme=l;
	char* ttt = (char*) malloc (sizeof(l));
	strcpy(ttt,l);
	tmp->lexeme=ttt;

	tmp->lineNum = lN;

	tmp->attribute=atr;

	tmp->next = 0;

	if(table.firstNode==0)
	{
		tmp->prev = 0;
		table.firstNode = tmp;

	}
	else {
		tmp->prev = table.lastNode;

		table.lastNode->next = tmp;
	}

	table.lastNode = tmp;
}

int NextElement(){
	//printf("NextElement shod\n");
	if(!table.firstNode){
		table.firstNode=0;
		return 0;
	}
	else
	{
		table.firstNode = table.firstNode->next;
		if(table.firstNode){
			table.firstNode->prev = 0;
		}
		return 1;
	}
	//printf("NextElement tamum shod\n");
}

char* getHeadToken(){
	char* tmp = (char*) malloc (sizeof(table.firstNode->token));
	strcpy(tmp,table.firstNode->token);
	return tmp;
}

int getHeadLineNum(){
	return table.firstNode->lineNum;
}

char* getHeadLexeme(){

	char* tmp = (char*) malloc (sizeof(table.firstNode->lexeme));
	strcpy(tmp,table.firstNode->lexeme);
	return tmp;
}

float getHeadAtrribute(){
	return table.firstNode->attribute;
}
void printLinkedList(){
	printf("lexeme\ttoken\tlineNumber\tattribute\n");
	while (table.firstNode)
	{
		char* tmpStr = (char*) malloc(strlen("REALNUM"));
		strcpy(tmpStr, "REALNUM");
		tmpStr[strlen(tmpStr)] = 0;
		if(strcmp(getHeadToken(),tmpStr) == 0)
			printf("%s\t%s\t\t%d\t\t%f\n",getHeadLexeme(),getHeadToken(),getHeadLineNum(),getHeadAtrribute());
		else
			printf("%s\t%s\t\t%d\t\t%d\n",getHeadLexeme(),getHeadToken(),getHeadLineNum(),(int) getHeadAtrribute());
		NextElement();
	}
}
float search(char * str)
{
	struct Node * tmp = table.firstNode;
	while(tmp)
	{
		char* lexeme = (char*) malloc(strlen(tmp->lexeme));
		strcpy(lexeme, tmp->lexeme);
		lexeme[strlen(lexeme)] = 0;
		//printf("lexeme: %s\n",lexeme);
		//printf("str: %s\n",str);
		if (strcmp(lexeme,str) == 0 )
		{
			//printf("matched!!!!!!!!!!\n");
			return tmp->attribute;
		}
		else{
			tmp=tmp->next;
		}
	}
	//printf("out of while\n");
	return 0;
	
}
