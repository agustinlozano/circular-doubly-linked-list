#include "cdll.h"

void deleteNode(Node **head, Node **tail) {
    Node *current = *head;

    if (current != NULL) {
        if (current == (*head) && current == (*tail)) {
            printf("\n\tSe elemininara el unico elemento existente\n\n");
            //deleteAllobjects(*head); ??????????? sino no borra objetos ligados
            *head = NULL;
            *tail = NULL;
            free(current);

        } else {
            deleteAllobjects(*head);
            makeLinksDeleteCategory(head, tail);
        }
        
    } else {
        printf("\n\tLa lista esta vacia\n\n");
    }

    printf("\nSe ha eliminado el nodo seleccionado\n");
}

void deleteAllobjects(Node *head) {
    Obj *current  = NULL;

    if (head != NULL) {
        current = head -> obj;

        do {
          current = current -> next;
          free(current);

        } while (current != (head->obj));

        head -> obj = NULL;

    } else {
        printf("\nLa categoria no tiene objetos ligados que borrar");
        printf("\nSe eliminara solo la categoria indicada\n\n");
    }
}

void deleteObject(Node *head) {
    int ID;

    if (head != NULL && head -> obj != NULL) {
        Node *tail = head -> prev;
        Obj *tailObj = tail -> obj;
        Obj *currentObj = head -> obj;

        printf("\nIngrese el ID del objeto ligado a %s: ", head->content);
        scanf(" %d", &ID);

        //Encontar el objeto ligado al ID ingresado
        do {
            if ((currentObj -> ID) == ID) {
                printf("\nID hallado, el object es: %s\tID: %d\n\n", 
                      currentObj->content, currentObj->ID);

                if (currentObj == head -> obj) {
                    //elimino el nodo y pero tambien tengo que apuntarlo desde la categoria
                    head -> obj = makeLinksDeleteObjects(currentObj);

                    //Ahora actualizo los ID de los objetos
                    updateID(head->obj->prev, head->obj);

                    free(currentObj);

                } else {
                    //simplemente borro el nodo
                    makeLinksDeleteObjects(currentObj);

                    //Ahora actualizo los ID de los objetos
                    updateID(head->obj->prev, currentObj);

                    free(currentObj);
                }
                break;
            }
            currentObj = currentObj -> next;

        } while ((currentObj->ID) != (tailObj -> ID));

    } else {
        printf("\n\tLa lista esta vacia o bien no tiene ningun objeto ligado a ella\n\n");
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
    } while (current != tail->next); 
        //tail->next es el fix 
}
