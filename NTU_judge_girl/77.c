#include <stdio.h>
#include<stdlib.h>
// #include "node.h"

struct node {
	int key;
    struct node *next;
};

struct node *getNode(struct node *head, unsigned int i){
	struct node *tmp = head;
	int n = 0;
	while(tmp){
		tmp = tmp->next;
		n++;
	}

	i = n - 1 - i;

	tmp = head;
	for(int k=0; k<i; k++){
		if(tmp == NULL)
			return NULL;
		else
			tmp = tmp->next;
	}
	return tmp;
}


int main(){
	struct node *node1 = (struct node *)malloc(sizeof(struct node));
	struct node *node2 = (struct node *)malloc(sizeof(struct node));
	node1->key = 1;
	node1->next = node2;
	node2->key = 2;
	node2->next = NULL;

	struct node *tmp =  getNode(node1, 1);
	if(tmp != NULL)
		printf("%d\n", tmp->key);
	else
		printf("NULL\n");

	return 0;

}






