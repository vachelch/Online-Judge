#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _NODE_H
#define _NODE_H

struct node {
    struct node *left;
    struct node *right;
    int data;
};
 
void print_all_paths(struct node *root);
 
#endif

int path[1000];
void print_path(int depth){
	for(int i=0; i<depth-1; i++)
		printf("%d ", path[i]);
	printf("%d\n", path[depth-1]);
}

void search_path(struct node *root, int depth){
	path[depth] = root->data;

	if(root->left == NULL && root->right == NULL)
		print_path(depth+1);
	if(root->left != NULL)
		search_path(root->left, depth+1);
	if(root->right != NULL)
		search_path(root->right, depth+1);
}
 
void print_all_paths(struct node *root){
	path[0] = root->data;

	search_path(root, 0);
}
 
struct node *insert_bs_tree(struct node *root, int data)
{
    struct node *current;
    if (root == NULL)
    {
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}














