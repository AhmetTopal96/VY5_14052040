/*This program converts infix expression to postfix expression*/
// PLEASE ENTER VARIABLES NAME FROM 'a' TO 'z' AND IT MUST BE SÝNGLE CHARACTER SUCH AS 'a','c','d'  !! IMPORTANT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 100

typedef struct STACK{
	int top;
	char st[SIZE];
	int  intst[SIZE];
}STACK;

void initializeArray(int Array[],int size){
	int i;
	for(i=0;i<size;i++)Array[i]=0;
}

//Basic stack operation is starting here
void initializest(STACK *stack){
	stack->top=0;
}
int isFull(STACK *stack){
	if(stack->top==SIZE)return 1;
	else return 0;
}

int isEmpty(STACK *stack){
	if(stack->top==0)return 1;
	else return 0;
}
void pushint(STACK *stack,int value){
	if(isFull(stack))
	printf("Stack is Full");
	else{
		stack->intst[stack->top]=value;
		stack->top++;
	}
}
void pushchar(STACK *stack,char value){
	if(isFull(stack))
	printf("Stack is Full");
	else{
		stack->st[stack->top]=value;
		stack->top++;
	}
}
int popint(STACK *stack){
	if(isEmpty(stack)) {
	printf("Stack is Empty");
}
	else{
		stack->top--;
		return stack->intst[stack->top];
	}
}
char popchar(STACK *stack){
	if(isEmpty(stack)) {
	printf("Stack is Empty");
}
	else{
		stack->top--;
		return stack->st[stack->top];
	}
}//Basic stack operation is ending here,So far we did push,pop and initialþze function, basically.

//This function converts one or more digit number  character in string array to integer.
//and returns address of last digit of number
//we will use this function to solve postfix expression
int convertcharTonumber(STACK *stack,char postfix[],int i){
		int count=0,top,number=0;
		while(postfix[i]!=' '){//we are look at digit of number
					count++;
					i++;
				}
				i-=count;
				while(count>0){
				count--;
				top=(postfix[i]-48);
				top=top*pow(10,count);//we get the digit value of the number
				number+=top;
				i++;
				}
				pushint(stack,number);
		return i;
}
//we will use this function to take two or more digit number to postfix expression
int convertcharTonumber2(char infix[],char postfix[],int i,int j,int *cont){
		
		while(infix[i]!=' '){
					postfix[j]=infix[i];
					i++;j++;
					(*cont)++;
				}
		return j;
}

void infixTopostfix(STACK *stack,char infixifade[],char postfixifade[],int visitvariable[]){
	int i=0,k=0;
	int j=0;
	int stop=0;
	char value;
	int count=0;

	while(infixifade[k]!='='){
		if(infixifade[k]>='a' || infixifade[k]<='z' )
		visitvariable[infixifade[k]-'a']=1;
		if( (infixifade[k]<'a' || infixifade[k] >'z' )&& infixifade[k]!=' '){
			printf("Error: Variable name must be English character between a and z");
			exit(0);
		}
		k++;
	}
	i=k+1;
	while(infixifade[i]!=';'){
		
		if(infixifade[i]==' '){
		i++;
		continue;
		
	}
	else{
	
		if(infixifade[i]!='+' &&infixifade[i]!='-' && infixifade[i]!='/' && infixifade[i]!='*' && infixifade[i]!='(' &&infixifade[i]!=')' )
		{
		count=0;
		j=convertcharTonumber2(infixifade,postfixifade,i,j,&count);
		postfixifade[j]=' ';
		j++;
	    i=i+count;
	}
	else{
	
		if( infixifade[i]=='+' || infixifade[i]=='-'  ) {
			if(isEmpty(stack)){
				pushchar(stack,infixifade[i]);
			
		}
		
			else{
				value=popchar(stack);
		
				if(value=='(')
				{
				pushchar(stack,value);
				pushchar(stack,infixifade[i]);	
			}
			
			else{
			while((value=='+' || value=='-' || value=='*' || value=='/')&& !stop ){
				postfixifade[j]=value;
				j++;
				postfixifade[j]=' ';
				j++;
				if(isEmpty(stack)!=1)
				value=popchar(stack);
				else stop=1;
			}
			if(stop==1)
				pushchar(stack,infixifade[i]);
			else{
				pushchar(stack,value);
				pushchar(stack,infixifade[i]);
			}
				stop=0;
			}
		}
		
	}
	if(infixifade[i]=='/' || infixifade[i]=='*' )
	{
		if(isEmpty(stack))
			pushchar(stack,infixifade[i]);
			
		
		else{
			value=popchar(stack);
			if(value=='+' || value=='-'){
				pushchar(stack,value);
				pushchar(stack,infixifade[i]);
			}
			
			if(value=='/' || value=='*'){
				postfixifade[j]=value;
				j++;
				postfixifade[j]=' ';
				j++;
				pushchar(stack,infixifade[i]);
			}
			if(value=='(') 
			{
				pushchar(stack,value);
				pushchar(stack,infixifade[i]);
			}
			
			
		}
	}
	if(infixifade[i]=='(')pushchar(stack,infixifade[i]);
	
	if(infixifade[i]==')'){
		stop=0;
		value=popchar(stack);
		while(value!='(' && !stop){
			postfixifade[j]=value;
			j++;
			postfixifade[j]=' ';
			j++;
			if(isEmpty(stack)!=1)
			value=popchar(stack);
			else stop=1;
		}
	
	}
	i++;
}
	

	printf("Postfix:%s\n",postfixifade);
	printf("Stack:");
	if(isEmpty(stack))printf("Bos");
	else{
		for(k=0;k<stack->top;k++)
		printf("%c",stack->st[k]);
	}
	printf("\n\n");

	}
}


	while(isEmpty(stack)!=1)
	{
	value=popchar(stack);
	postfixifade[j]=value;
	j++;
	postfixifade[j]=' ';
	j++;

	printf("Postfix:%s\n",postfixifade);
	printf("Stack:");
	if(isEmpty(stack))printf("Bos");
	else{
		for(k=0;k<stack->top;k++)
		printf("%c",stack->st[k]);
	}
	printf("\n\n");

	
}

	printf("OUTPUT: %s\n",postfixifade);
	postfixifade[j]=' ';j++;
	postfixifade[j]=';';j++;

}

int solvePostfix(char postfix[],int variableadr[],int visitvariable[]){
	printf("----------- Postfix Solver-Status of the stack ----------------\n");
	int i=0,k;
	int sayi;
	int number=0,number1,number2,sonuc;
	int count,top,tmp;
	STACK *tmpstack=(STACK *)malloc(sizeof(STACK));
	initializest(tmpstack);
		while(postfix[i]!=';'){
			if(postfix[i]==' '){
			i++;
		}
		else{
			if(isdigit(postfix[i]) || postfix[i]>='a' || postfix[i]<='z' && postfix[i]!='+'&& postfix[i]!='-'&& postfix[i]!='*'&& postfix[i]!='/'){
				if(isdigit(postfix[i])){
				i=convertcharTonumber(tmpstack,postfix,i);
			
			}
				else
				{
				
				sayi=variableadr[postfix[i]-'a'];
				pushint(tmpstack,sayi);
				i++;
				}
			}
			 else{
			 	number1=popint(tmpstack);
			 	number2=popint(tmpstack);
			 	
			 	if(postfix[i]=='+')sonuc=number1+number2;
			 	if(postfix[i]=='-')sonuc=number2-number1;
			 	if(postfix[i]=='/')sonuc=number2/number1;
			 	if(postfix[i]=='*')sonuc=number2*number1;
			 	pushint(tmpstack,sonuc);
			 	
			 	i++;
			 }
			
		printf("\nStack:");
		for(k=0;k<tmpstack->top;k++)
		printf("%4d",tmpstack->intst[k]);
	
	}
	
	}
	int value=popint(tmpstack);
	for(k=0;k<26;k++){
		if(visitvariable[k]==1)
		variableadr[k]=value;
	}
	return value;
}

int main()
{
	int i;
	int k=0;
	char infix[75];
	int variableadr[26];
	int visitvariable[26];
	char *str;
	STACK *stack;
	stack=(STACK *)malloc(sizeof(STACK));
	initializest(stack);
	char variable;
	
	initializeArray(variableadr,26);
	initializeArray(visitvariable,26);
	
	printf("Warning:You must enter the variables in the file from English characters between a and z and it must be single character\n");

	int devam;
	
	
	
		
	FILE *fp;
	if((fp=fopen("input.txt","r"))==NULL){
		printf("Dosya acma hatasi");
		exit(0);
	}
	fseek(fp,0,SEEK_SET);
	str=fgets(infix,50,fp);
	while(str!=NULL){
	printf("Press 1 to continue and to analyze the expressions:%d\n",k+1);
	scanf("%d",&devam);
	if(devam==1){
	char postfix[75]="0";
	printf("Arithmetic Expression:\t%s\n\n",infix);
	
	infixTopostfix(stack,infix,postfix,visitvariable);
	int eval=solvePostfix(postfix,variableadr,visitvariable);
	for(i=0;i<26;i++){
		if(visitvariable[i])
		variable=97+i;
	}
	initializeArray(visitvariable,26);
	printf("\nvariable: %c <- %d\n",variable,eval);
	printf("--------------------------------------------------------------------------------");
}
else {
printf("\nProgram is ended ");
exit(0);
}
str=fgets(infix,50,fp);
k++;

}
printf("\n------------------- Status of all variables ------------------------\n");

	for(i=0;i<26;i++){
		if(variableadr[i]){
		variable=97+i;
		printf("%c <- %d\t\t",variable,variableadr[i]);
			}
		}
	
	
}

