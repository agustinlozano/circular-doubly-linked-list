#ifndef CDLL
#define CDLL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct objeto {
    char content[30];
    int ID;
    struct objeto *next;
    struct objeto *prev;
} Obj;

typedef struct node {
    char content[30];
    Obj *obj;
    struct node *next;
    struct node *prev;
} Node;

/* funciones de interes */
void runMenu(Node *headC, Node *tailC);
void addNode(Node **head, Node **tail);
void nextCategory(Node **head, Node **tail);
void prevCategory(Node **head, Node **tail);
void printList(Node *head);

void addObject(Node *headC, Node *tailC);
void newObject(Node *currentCat);

void deleteObject(Node *head);
void deleteNode(Node **head, Node **tail);
void updateID(Obj *tail, Obj *current);


#endif