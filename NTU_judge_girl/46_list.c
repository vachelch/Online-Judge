#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct list;
struct head;
typedef struct head *Head;
typedef struct list *node;

struct head
{
	node next;
	int len;
};

struct list
{
	char value;
	node next;
};

void insert_left(char val, Head head){
	node cur;
	cur = (node) malloc(sizeof(struct list));

	cur->value = val;
	cur->next = head->next;
	head->next = cur;
	++head->len;
}

void insert_right(char val, Head head){
	node cur = head->next;
	node end;

	end = (node)malloc(sizeof(struct list));

	for (int i = 1; i < head->len; ++i)
		cur = cur->next;
	end->value = val;
	cur->next = end;
	end->next = NULL;
	++head->len;

}
void insert_k(char val, Head head, int k){
	node cur = head->next;
	node knode;

	knode = (node) malloc(sizeof(struct list));

	for (int i = 1; i < k-1; ++i)
		cur = cur->next;
	knode->value = val;
	knode->next = cur->next;
	cur->next = knode;
	++head->len;
}

void delete_left(Head head){
	node tmp = head->next;
	head->next = tmp->next;
	--head->len;
	free(tmp);
}

void delete_right(Head head){
	node cur = head->next;
	for(int i=1; i<head->len-1; i++)
		cur = cur->next;
	free(cur->next);
	cur->next = NULL;
	--head->len;

}
void delete_k(Head head, int k){
	node cur = head->next;
	node next_node;
	for (int i = 1; i < k-1; ++i)
		cur = cur->next;
	next_node = cur->next->next;
	free(cur->next);
	cur->next = next_node;
	--head->len;
}

int main(){
	Head head;
	head = (Head) malloc(sizeof(struct head));

	head->next = NULL;
	head->len = 0;

	char command[7];

	while(scanf("%s", command) != EOF){
		char param[6];
		char val[2];

		if(strcmp(command, "insert") == 0){
			scanf("%s", param);
			if(strcmp(param, "left") == 0){
				scanf("%s", val);
				insert_left(val[0], head);
			}
			else if(strcmp(param, "right") == 0){
				scanf("%s", val);
				insert_right(val[0], head);
			}
			else if(isdigit(param[0])){
				scanf("%s", val);
				insert_k(val[0], head, atoi(param));
			}

		}
		else if(strcmp(command, "delete") == 0){
			scanf("%s", param);
			if(strcmp(param, "left") == 0)
				delete_left(head);
			else if(strcmp(param, "right") == 0)
				delete_right(head);
			else if(isdigit(param[0])){
				delete_k(head, atoi(param));
			}
		}
	}

	node current = head->next;

	Head output;
	output = (Head) malloc(sizeof(struct head));
	output->next = NULL;
	output->len = 0;

	char last;
	int count=0;
	int max = -1;

	while(current){
		if(isalnum(last) && current->value == last){
			count++;
			if(count > max){
				max = count;

				//a new output list
				node position;
				position = (node) malloc(sizeof(struct list));

				position->value = last;
				position->next = NULL;
				free(output->next);
				output->next = position;
			}
			else if(count == max)
				insert_right(last, output);
		}
		else{
			count = 1;
			last = current->value;

			if(count>=max){
				max = 1;
				insert_left(last, output);
			}
		}
		current = current->next;
	}

	current = output->next;

	while(current){
		printf("%c ", current->value);
		current = current->next;
	}
	printf("%d\n", max);
	return 0;
}




















