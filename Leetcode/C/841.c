#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
} * Node;

typedef struct queue{
	Node next;
	Node tail;
} *Queue;

void Enqueue(Queue queue, int val){
	Node node = (Node) malloc(sizeof(struct node));
	node->next = NULL;
	node->val = val;

	if (queue->tail == NULL)
		queue->next = node;
	else
		queue->tail->next = node;

	queue->tail = node;
}

int DeQueue(Queue queue){
	 Node node = queue->next;
	 queue->next = node->next;

	 if (queue->tail == node){
	 	queue->tail = NULL;
	 }

	 return node->val;
}

int isEmpty(Queue queue){
	return queue->tail == NULL;
}

Queue createQueue(){
	Queue queue = (Queue) malloc(sizeof(struct queue));
	queue->next = NULL;
	queue->tail = NULL;
	return queue;
}

void BFS(int **rooms, int roomsRowSize, int *roomsColSizes, Queue queue, int *visited){
	while(!isEmpty(queue)){
		int idx = DeQueue(queue);

		// for every adjacent rooms
		for(int i=0; i< roomsColSizes[idx]; i++){
			int adj_room = rooms[idx][i];
			if (!visited[adj_room]){
				visited[adj_room] = 1;
				Enqueue(queue, adj_room);
			}
		}
	}
}

bool canVisitAllRooms(int **rooms, int roomsRowSize, int *roomsColSizes) {
	Queue queue = createQueue();
	Enqueue(queue, 0);

	int * visited = (int *)malloc(roomsRowSize * sizeof(int));
	for(int i=0; i< roomsRowSize; i++)
		visited[i] = 0;
	visited[0] = 1;

	BFS(rooms, roomsRowSize, roomsColSizes, queue, visited);

	for(int i=0; i< roomsRowSize; i++){
		if (visited[i] == 0)
			return false;
	}
	return true;
}


int main(){
	// int rooms[4][3] = {{1,3},{3,0,1}, {2}, {0}};
	// int roomsColSizes[4] = {2, 3, 1, 1};
	int rooms[4][1] = {{1}, {2}, {3}};
	int roomsColSizes[4] = {1, 1, 1, 0};
	int roomsRowSize = 4;


	if(canVisitAllRooms(rooms, roomsRowSize, roomsColSizes))
		printf("true\n");
	else
		printf("false\n");

	return 0;		
}












