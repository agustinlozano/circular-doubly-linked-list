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

void deleteObject(Node *head) {
    int ID;

    if (head != NULL) {
        Obj *currentObj = head -> obj;
        Obj *aux = NULL;

        printf("\nIngrese el ID del objeto ligado a %s: ", head->content);
        scanf(" %d", &ID);

        while ((currentObj->ID) != ID) {
            currentObj = currentObj -> next;
        }

        printf("\nCurrent object es: %s\tID: %d\n\n", 
            currentObj->content, currentObj->ID);

        if (currentObj == head -> obj) {
            //elimino el nodo y pero tambien tengo que apuntarlo desde la categoria
            aux = currentObj -> prev;
            aux -> next = currentObj -> next;

            aux = currentObj -> next;
            aux -> prev = currentObj -> prev;

            head -> obj = aux;

            //Ahora actualizo los ID de los objetos
            updateID(currentObj->prev, aux);

            free(currentObj);

        } else {
            //simplemente borro el nodo
            aux = currentObj -> prev;
            aux -> next = currentObj -> next;

            aux = currentObj -> next;
            aux -> prev = currentObj -> prev;

            //Ahora actualizo los ID de los objetos
            updateID(currentObj->prev, aux);

            free(currentObj);
        }

    } else {
        printf("\n\tLa lista esta vacia\n\n");
    }
}

void updateID(Obj *tail, Obj *current) {
    do {
        int currentID = current -> ID;
        current -> ID = currentID - 1;
        current = current -> next;
    } while (current != tail);  
}