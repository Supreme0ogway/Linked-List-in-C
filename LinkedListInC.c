#include <stdio.h>
#include <stdlib.h>

//*************new types for list**************
//creat new struct
typedef struct node {
    void* data;
    struct node* next;
} Node;

typedef struct list {
    int size;
    Node* head;
} List;

//creates the new linked list
List* create_LL() {
    List* new_L = (List*)malloc(sizeof(List));
    new_L->size = 0;
    new_L->head = NULL;
    return new_L;
}

//create new node and add to head
//adds to front
void listAdd(List* list, void* data) {
    //allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;//set data
    newNode->next = list->head;
    list->head = newNode;
    list->size++;//add to size
}

//remove node from list at head
void* removeNode(List* list) {
    if(list->size == 0) {//nothing in list
        return NULL;
    }

    Node* nodeRemove = list->head;
    void* data = nodeRemove->data;
    list->head = nodeRemove->next;
    free(nodeRemove);//free memory
    list->size--;
    return data;
}

//remove/delete the entire list
void freeDelete(List* list) {
    Node* curr_node = list->head;
    while(curr_node != NULL) {
        Node* nextNode = curr_node->next;
        free(curr_node);
        curr_node = nextNode;
    }
    free(list);//free the entire list memory reserve
}

//activate the list
int main() {
    List* listOfIntegers = create_LL();

    //make variables to add to list
    int x = 10;
    int y = 15;
    int z = 20;
    //add to list
    listAdd(listOfIntegers, (void*)&x);
    listAdd(listOfIntegers, (void*)&y);
    listAdd(listOfIntegers, (void*)&z);

    //remove the ints and print
    int* ptr = NULL;
    while((prt = (int*)removeNode(listOfIntegers)) != NULL) {
        printf("%d\n", *ptr);//print values then next
    }

    //free the list
    freeDelete(listOfIntegers);
    return 0;//end main
    
}