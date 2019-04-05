typedef struct {
    int *list;
    int capacity;
    int size;
    int front;
    int rear;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *deque = (MyCircularDeque *) malloc(sizeof(MyCircularDeque));
    int *list = (int *)malloc(sizeof(int) * k);
    deque->list = list;
    deque->size = 0;
    deque->capacity = k;
    
    return deque;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    if (obj->size == 0){
        obj->front = obj->rear = 0;
        obj->list[0] = value;
        obj->size = 1;
        return true;
    }

    if(obj->front == 0) 
        obj->front = obj->capacity - 1;
    else
        obj->front -= 1;
    obj->list[obj->front] = value;
    obj->size += 1;

    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    if (obj->size == 0){
        obj->front = obj->rear = 0;
        obj->list[0] = value;
        obj->size = 1;
        return true;
    }
    
    if(obj->rear == obj->capacity-1) 
        obj->rear = 0;
    else
        obj->rear += 1;
    obj->list[obj->rear] = value;
    obj->size += 1;
    
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    
    if(obj->front == obj->capacity-1) 
        obj->front = 0;
    else
        obj->front += 1;

    obj->size -= 1;
    
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    
    if(obj->rear == 0) 
        obj->rear = obj->capacity - 1;
    else
        obj->rear -= 1;

    obj->size -= 1;
    
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;

    return obj->list[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;

    return obj->list[obj->rear];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->list);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * struct MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 * bool param_3 = myCircularDequeDeleteFront(obj);
 * bool param_4 = myCircularDequeDeleteLast(obj);
 * int param_5 = myCircularDequeGetFront(obj);
 * int param_6 = myCircularDequeGetRear(obj);
 * bool param_7 = myCircularDequeIsEmpty(obj);
 * bool param_8 = myCircularDequeIsFull(obj);
 * myCircularDequeFree(obj);
 */