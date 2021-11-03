#include "cdll.h"

void deleteNode(Node **head, Node **tail) {
    Node *current = *head;
    Node *aux = NULL;

    char category[30];

    printf("\n\tIngrese la categoria que desea borrar: ");
    scanf(" %s", category);

    if (current != NULL) {
        do {
            if (strcmp(current -> content, category) == 0) {
                if (current == (*head) && current == (*tail)) {
                    printf("\n\tSe elemininara el unico elemento existente");
                    *head = NULL;
                    *tail = NULL;

                    free(current);
                } else if (current == (*head)) {
                    (*head) = (*head) -> next;
                    (*head) -> prev = (*tail);
                    (*tail) -> next = (*head);

                    free(current);
                } else if (current == (*tail)) {
                    aux = current -> prev;
                    
                    (*tail) = aux;
                    (*tail) -> next = (*head);
                    (*head) -> prev = (*tail);

                    free(current);
                } else {
                    aux = current -> prev;
                    aux -> next = current -> next;

                    aux = current -> next;
                    aux -> prev = current -> prev;

                    free(current);
                }
                break;
            }
            current = current -> next;

        } while (current != *head);
        printf("\n\tEl nodo ha sido elininado\n\n");
        
    } else {
        printf("\n\tLa lista esta vacia\n\n");
    }
}