#include "cdll.h"

void printList(Node *headCat) {
    Node *current = headCat;
    
    if (current != NULL) {
        do {
            if(current == headCat) {
                printf("\n\t*%s", current->content);
            } else {
                printf("\n\t%s", current->content);
            }
            
            Obj *headObj = current->obj;
            Obj *currentObject = headObj;

            if(currentObject != NULL){
                int count = 0;
                do {
                    printf("\n%d: %s, \tID: %d", count, currentObject->content, currentObject->ID);
                    
                    currentObject = currentObject -> next;
                    count++;
                } while (currentObject != headObj);
                printf("\n");
            } else {
                printf("\n%s no tiene objetos ligados\n", current->content);
            }
            
            current = current -> next;
        } while (current != headCat);

    } else {
        printf("\n\tLa lista esta vacia.\n");
    }

    printf("\n\n");
}