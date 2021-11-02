#include "cdll.h"

void addNode(Node **head, Node **tail) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    printf("\n\tIngresar la keyword del nodo: ");
    scanf(" %s", newNode -> content);

    if (*head == NULL) {                                 //la lista esta vacia
        printf("\n\tAgrega el primer nodo de la lista");
        (*head) = newNode;        
        newNode -> next = (*head);
        (*tail) = newNode;        
        newNode -> prev = (*tail);
    } else {                                             //la lista no esta vacia
        printf("\n\tAgrega un nodo mas a la lista");    
        (*tail) -> next = newNode;
        newNode -> prev = (*tail);
        (*tail) = newNode;
        newNode -> next = (*head);
        (*head) -> prev = newNode;
    }

	printf("\n\tNodo ingresado\n\n");

}

void addObject(Node *headCat, Node *tailCat) {
    Node *aux = headCat;
    char category[30];

    printf("\n\tIngrese la categoria que deseas buscar: ");
    scanf(" %s", category);

    int quit = 1;
    do {
        if(strcmp(aux->content, category) == 0){
           printf("\n\tExito: categoria encontrada");

           printf("\n\tAhora agregamos el nuevo objeto dentro de la categoria: %s\n",
                aux -> content);
           
           newObject(aux);

           quit = 0;
        }

        aux = aux -> next;
    } while(quit);
}

void newObject(Node *currentCat) {
    Obj *newObject = (Obj *)malloc(sizeof(Obj));
    Obj *headObj = currentCat -> obj;
    Obj *tailObj = NULL;

    printf("\n\tIngresar la keyword del objeto: ");
    scanf(" %s", newObject -> content);

    if (headObj == NULL) {                                 //la lista esta vacia
        printf("\n\tAgrega el primer objeto de la lista");
        newObject -> ID = 1;

        headObj = newObject;        
        newObject -> next = headObj;
        tailObj = newObject;        
        newObject -> prev = tailObj;

        currentCat -> obj = headObj;
    } else {                                             //la lista no esta vacia
        printf("\n\tAgrega un objeto mas a la lista");
        tailObj = headObj -> prev;
        int prevID = tailObj -> ID; 

        tailObj -> next = newObject;
        newObject -> prev = tailObj;
        tailObj = newObject;
        newObject -> next = headObj;
        headObj -> prev = newObject;

        newObject -> ID = prevID + 1;
    }

    printf("\n\tExito: objeto agregado\n\n");
}
