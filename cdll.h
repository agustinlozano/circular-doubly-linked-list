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

  /*  */
  void runMenu(Node *headC, Node *tailC);
  void printList(Node *head);

  /* shift */
  void nextCategory(Node **head, Node **tail);
  void prevCategory(Node **head, Node **tail);


  /* add */
  void addNode(Node **head, Node **tail);
    void makeLinksAddCategory(Node **head, Node **tail, Node *newNode);

  void addObject(Node *headCat);
    void makeLinksAddObjects(Obj *headObj, Obj *tailObj, Obj *newObject);

  /* delete */
  void deleteObject(Node *head);
    Obj * makeLinksDeleteObjects(Obj *obj);

  void deleteNode(Node **head, Node **tail);
    void deleteAllobjects(Node *head);
    void makeLinksDeleteCategory(Node **head, Node **tail);

    void updateID(Obj *tail, Obj *current);

#endif