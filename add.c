#include "cdll.h"

void addNode(Node **head, Node **tail) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    printf("\n\tIngresar la keyword del nodo: ");
    scanf(" %s", newNode -> content);

    //la lista esta vacia
    if (*head == NULL) {
        printf("\n\tAgrega el primer nodo de la lista");
        (*head) = newNode;        
        (*tail) = newNode;
        makeLinksAddCategory(head, tail, newNode);     
    
    //la lista no esta vacia
    } else {
        printf("\n\tAgrega un nodo mas a la lista");    
        makeLinksAddCategory(head, tail, newNode);
    }

    printf("\n\tExito: categoria agregada\n\n");
}

void addObject(Node *headCat) {
    Obj *newObject = (Obj *)malloc(sizeof(Obj));
    Obj *headObj = headCat -> obj;
    Obj *tailObj = NULL;

    printf("\n\tSe agregara el nuevo objeto dentro de la categoria: %s\n",
                headCat -> content);

    printf("\n\tIngresar la keyword del objeto: ");
    scanf(" %s", newObject -> content);

    //la lista esta vacia
    if (headObj == NULL) {
        printf("\n\tAgrega el primer objeto de la lista");
        newObject -> ID = 1;

        headObj = newObject;
        tailObj = newObject;

        makeLinksAddObjects(headObj, tailObj, newObject);

        headCat -> obj = headObj;
    
    //la lista no esta vacia
    } else {
        printf("\n\tAgrega un objeto mas a la lista");
        tailObj = headObj -> prev;
        int prevID = tailObj -> ID; 

        makeLinksAddObjects(headObj, tailObj, newObject);

        newObject -> ID = prevID + 1;
    }

    printf("\n\tExito: objeto agregado\n\n");
}

void makeLinksAddCategory(Node **head, Node **tail, Node *newNode) {
    (*tail) -> next = newNode;
    newNode -> prev = (*tail);
    (*tail) = newNode;
    newNode -> next = (*head);
    (*head) -> prev = newNode;
}

void makeLinksAddObjects(Obj *headObj, Obj *tailObj, Obj *newObject) {
    tailObj -> next = newObject;
    newObject -> prev = tailObj;
    tailObj = newObject;
    newObject -> next = headObj;
    headObj -> prev = newObject;    
}
