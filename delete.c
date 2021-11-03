#include "cdll.h"

void deleteNode(Node **head, Node **tail) {
    Node *current = *head;

    if (current != NULL) {
        if (current == (*head) && current == (*tail)) {
            printf("\n\tSe elemininara el unico elemento existente\n\n");
            *head = NULL;
            *tail = NULL;
            free(current);

        } else if (current == (*head)) {
            makeLinksDeleteCategory(head, tail);

        } else if (current == (*tail)) {
            makeLinksDeleteCategory(head, tail);
        }
        
    } else {
        printf("\n\tLa lista esta vacia\n\n");
    }

    printf("\nSe ha eliminado el nodo seleccionado\n");
}

void deleteObject(Node *head) {
    int ID;

    if (head != NULL) {
        Obj *currentObj = head -> obj;

        printf("\nIngrese el ID del objeto ligado a %s: ", head->content);
        scanf(" %d", &ID);

        while ((currentObj->ID) != ID) {
            currentObj = currentObj -> next;
        }

        printf("\nEl object es: %s\tID: %d\n\n", 
            currentObj->content, currentObj->ID);

        if (currentObj == head -> obj) {
            //elimino el nodo y pero tambien tengo que apuntarlo desde la categoria
            head -> obj = makeLinksDeleteObjects(currentObj);

            //Ahora actualizo los ID de los objetos
            updateID(currentObj->prev, head->obj);

            free(currentObj);

        } else {
            //simplemente borro el nodo
            makeLinksDeleteObjects(currentObj);

            //Ahora actualizo los ID de los objetos
            updateID(currentObj->prev, head->obj);

            free(currentObj);
        }

    } else {
        printf("\n\tLa lista esta vacia\n\n");
    }
}

void makeLinksDeleteCategory(Node **head, Node **tail) {
    (*tail) = (*head) -> prev;
    Node *aux = NULL;
    
    aux = (*tail);
    aux -> next = (*head) -> next;

    aux = (*head) -> next;
    aux -> prev = (*head) -> prev;

    free((*head));

    (*head) = aux;
}

Obj * makeLinksDeleteObjects(Obj *obj) {
    Obj *aux = NULL;
    
    aux = obj -> prev;
    aux -> next = obj -> next;

    aux = obj -> next;
    aux -> prev = obj -> prev;

    return aux;
}

void updateID(Obj *tail, Obj *current) {
    do {
        int currentID = current -> ID;
        current -> ID = currentID - 1;
        current = current -> next;
    } while (current != tail);  
}