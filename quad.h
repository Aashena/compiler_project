#define MAXSIZE 1000

char quad_ruples[MAXSIZE][4][200];
char* label;
// opration arg1 arg2 result
int nextquad = 0;

void emit(char* op, char* arg1, char* arg2, char* result);
void quad_display();
void setLabel(int i, char* label);
void mkCfile();

void quad_display(){
	int i;
	printf("\nQUADRAPLE :\n");
		for(i=0; i<=nextquad-1; i++){
		  printf("%d : quadruples: %s, %s, %s, %s\n",i,quad_ruples[i][0],quad_ruples[i][1],quad_ruples[i][2],quad_ruples[i][3]);
		}
	printf("==========================\n");
}



void emit(char* op, char* arg1, char* arg2, char* res){
  int i =0;
  while(op[i]!='\0'){
   quad_ruples[nextquad][0][i] = op[i];
  i++;
  }  
  quad_ruples[nextquad][0][i] = op[i];
  i =0;
  while(arg1[i]!='\0'){
   quad_ruples[nextquad][1][i] = arg1[i];
  i++;
  }  
  quad_ruples[nextquad][1][i] = arg1[i];
  i =0;
  while(arg2[i]!='\0'){
   quad_ruples[nextquad][2][i] = arg2[i];
  i++;
  }  
  quad_ruples[nextquad][2][i] = arg2[i];
  i =0;
  while(res[i]!='\0'){
   quad_ruples[nextquad][3][i] = res[i];
  i++;
  }  
  quad_ruples[nextquad][3][i] = res[i];

nextquad++;
  //quad_display();
  
}

void setLabel(int i, char* label){
  int j=0;
  while(label[j]!='\0'){
   quad_ruples [i][1][j] = label[j];
  j++;
  }  
  quad_ruples [i][1][j] = label[j];
  j =0;
  //quad_display();
}







