#include "cdll.h"

void nextCategory(Node **head, Node **tail) {
    Node *aux;
    if (*head == NULL) {
        printf("\nLa lista esta vacia\n");
    } else {
        aux = (*head) -> next;
        (*tail) = (*head);
        (*head) = aux;

        printf("\nLa categoria actual es: %s\n\n", (*head)->content);        
    }
}

void prevCategory(Node **head, Node **tail) {
    Node *aux;
    if (*head == NULL) {
        printf("\nLa lista esta vacia\n");
    } else {
        aux = (*head) -> prev;
        (*tail) = (*tail) -> prev;
        (*head) = aux;

        printf("\nLa categoria actual es: %s\n\n", (*head)->content);        
    }
}