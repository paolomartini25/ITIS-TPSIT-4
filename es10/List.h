#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int valore;
    char *string;
    struct node* next;
}Nodo;


//LISTE -------------------------------------------------------------------
int is_empty(struct node *head){
    if(head == NULL) return 1;
    else return 0; //lista piena
}

void print_list(struct node *head){
    if (is_empty(head)) {
        printf("lista vuota\n");
    }
    else{
        struct node *tmp = head;
        while(tmp != NULL){
            printf("valore: %d\n", head->valore);
            tmp= tmp->next;
        }
    }
}

int string_already_in_list(struct node *head, char* str){
    struct node *tmp = head;

    while(tmp != NULL) {
        if (!strcmp(tmp->string, str))
            return 1;
        
        tmp = tmp->next;
    }

    return 0;
}

//PILE -LIFO- -------------------------------------------------------------
void push(struct node **head, struct node *element){
    if (is_empty(*head)) {
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

struct node* pop(struct node **head){
    struct node *ret = *head;
    if (is_empty(*head)) {
        return NULL;
    }
    else{
        *head = ret->next;
    }
    return ret;
}
// quando stampo il valore: (*pop(...))->valore

//CODE -FIFO- ------------------------------------------------------------
void enqueue (struct node **head, struct node **tail, struct node *element){
    if (is_empty(*head)) {
        *head = element;
    }
    else{
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

struct node *dequeue(struct node **head, struct node **tail){
    struct node *ret = *head;
    if (is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}
// quando stampo il valore: (*dequeue(...))->valore