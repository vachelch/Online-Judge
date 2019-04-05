#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct tree {
	int sum;
	struct tree * left;
	struct tree * right;
} Tree;

char string[4000];
void print_HRHL(Tree* head);
void print_HLHR(Tree* head);

char * parse(Tree* head, char* str, int N){
	if(isdigit(*str)){
		char num[10];
		num[0] = *str;

		while(isdigit(*(++str))){
			num[strlen(num)] = *(str);
		}
		head->sum = atoi(num);
		head->left = NULL;
		head->right = NULL;

		return str;
	}

	if(*str == '('){
		Tree* left_node = (Tree *) malloc(sizeof(struct tree));
		assert(left_node);
		Tree* right_node = (Tree *) malloc(sizeof(struct tree));
		assert(right_node);
		left_node->left = NULL;
		left_node->right = NULL;
		right_node->left = NULL;
		right_node->right = NULL;

		str = parse(left_node, str+1, N);
		if(*str == ')' | *str == ',')
			str++;
		str = parse(right_node, str, N);

		head->left = left_node;
		head->right = right_node;
		head->sum = head->left->sum + head->right->sum;

		return str+1;
	}

	return string;
}

void print_HLHR(Tree* head){
	if(head->left && head->right){
		printf("%d\n", head->sum);
		print_HRHL(head->left);
		printf("%d\n", head->sum);
		print_HRHL(head->right);
	}
	else{
		printf("%d\n", head->sum);
		printf("%d\n", head->sum);
	}
}

void print_HRHL(Tree* head){
	if(head->left && head->right){
		printf("%d\n", head->sum);
		print_HLHR(head->right);
		printf("%d\n", head->sum);
		print_HLHR(head->left);
	}
	else{
		printf("%d\n", head->sum);
		printf("%d\n", head->sum);
	}
}

int main(){
	scanf("%s", string);

	Tree * head = (Tree *) malloc(sizeof(struct tree));
	assert(head);
	head->left = NULL;
	head->right = NULL;

	parse(head, string, strlen(string));
	print_HLHR(head);
	return 0;
}

















