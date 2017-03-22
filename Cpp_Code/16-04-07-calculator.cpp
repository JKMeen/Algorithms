#include "stack.h"
Stack s;

int main()
{
	char exp[MAX_SIZE], post_exp[MAX_SIZE];

	init( &s);
	while ( 1 ) {
		printf("중위수식을 입력:");
		scanf("%s", exp );
		if( strcmp( exp, "quit" ) == 0 || strcmp( exp, "QUIT" ) == 0) break;
		infix_to_postfix( exp, post_exp);
		printf("변화된 후위표기법: %s\n", post_exp);
		printf("후위 수식 계산 결과 : %.2f\n", eval_postfix( post_exp ));
	}
	getchar();getchar();
	return 0;
}


void infix_to_postfix( char *infix, char *postfix)
{
	int index=0;
	element item;

	for ( int i = 0 ; infix[i] != '\0'; i++ ) {
		switch( infix[i] ) {
		case '+': 
		case '-':
		case '*':
		case '/':
			while ( !is_empty(&s) &&  get_priority( infix[i] ) <=  get_priority( peek(&s) ) )
				postfix[index++] = pop(&s);
			push( &s, infix[i] );
			break;
		case '(':
			push( &s, infix[i] );
			break;
		case ')':
			item = pop(&s);
			while( item != '(' ) { 
				postfix[index++] = item;
				item = pop(&s);
			}
			break;
		default:
			postfix[index++] = infix[i];
		}
	}
	while( !is_empty(&s) )
		postfix[index++] = pop(&s);
	postfix[index]='\0';
}

int get_priority( char op)
{
	switch( op ){
	case '*': return 3;
	case '/': return 3;
	case '+':return 2;
	case '-': return 2;
	}
	return -1;
}

double eval_postfix( char *expr )
{
	double data1, data2;

	init( &s );
	for( int i = 0  ; expr[i] != '\0'; i++ ) {
	
		if( expr[i] != '+' && expr[i] !='-' && expr[i] !='*' && expr[i] != '/' )
			push( &s, (double)(expr[i]-'0')); 	
		
		else {
			data2 = pop( &s );
			data1 = pop( &s);
			switch( expr[i] ) {
			case '+': push( &s, (data1 + data2)); break;
			case '-':  push( &s, (data1 - data2)); break;
			case '*':  push( &s, (data1 * data2)); break;
			case '/':  push( &s, (data1 / data2));break;
			}
		}
	}
	return pop(&s);
}