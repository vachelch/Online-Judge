#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

char input[1000];
char variabels[50][33];
int varibels_value[50];
int var_count = 0;

typedef struct node {
	char var[33];
	struct node * left;
	struct node * right;
} Node;

Node * scan(int *var_count){
	char var[33];
	if(scanf("%s", var) != EOF){
		if(!strcmp(var, "(")){
			// printf("1\n");
			Node * tmp = (Node *) malloc(sizeof(struct node));
			char operater[2];
			scanf("%s", operater);
			strcpy(tmp->var, operater);
			tmp->left = scan(var_count);
			tmp->right = scan(var_count);

			return tmp;
		}
		else if(!strcmp(var, ")")){
			// printf("2\n");
			return scan(var_count);
		}
		else if(isdigit(var[0])){
			// printf("3\n");
			Node * tmp = (Node *) malloc(sizeof(struct node));
			strcpy(tmp->var, var);
			tmp->left = NULL;
			tmp->right = NULL;

			return tmp;
		}
		//is variable or digit
		else{
			// printf("4\n");
			Node * tmp = (Node *) malloc(sizeof(struct node));
			strcpy(tmp->var, var);
			tmp->left = NULL;
			tmp->right = NULL;
			(*var_count)++;

			return tmp;
		}
	}

	return NULL;
}

void print_tree(Node *head){
	printf("%s\n", head->var);
	if(head->left != NULL)
		print_tree(head->left);
	if(head->right != NULL)
		print_tree(head->right);
}

int isoperator(char var[]){
	char str[4] = {'+', '-', '*', '/'};
	int flag = 0;
	for(int i=0; i<strlen(str); i++)
		if(str[i] == var[0])
			flag = 1;
	return flag;
}

int operate(int left, int right, char var[]){
	char str[4] = {'+', '-', '*', '/'};

	int operation = 0;
	for(int i=0; i<strlen(str); i++)
		if(str[i] == var[0])
			operation = i;

	int result;
	switch (operation){
		case 0:
			result = left + right;
			break;
		case 1:
			result = left - right;
			break;
		case 2:
			result = left * right;
			break;
		case 3:
			result = left / right;
			break;
	}

	return result;
}

int find_value(char var[]){
	for(int i=0; i<var_count; i++){
		if(!strcmp(var, variabels[i]))
			return varibels_value[i];
	}
	return 0;
}

int calculate(Node *head){
	if(isoperator(head->var)){
		return operate(calculate(head->left), calculate(head->right), head->var);
	}
	else if(isdigit(head->var[0]))
		return atoi(head->var);
	else{
		return find_value(head->var);
	}
	return 0;
}

void clean_input(){
	char tmp;
	while(scanf("%c", &tmp) != EOF){
		if(tmp == '\n')
			break;
	}
}

int main(){

	Node * head;
	head = scan(&var_count);

	clean_input();
	for(int i=0; i<var_count; i++){
		scanf("%s = %d", variabels[i], &varibels_value[i]);
	}

	int result = calculate(head);
	printf("%d\n", result);

	return 0;
}
























