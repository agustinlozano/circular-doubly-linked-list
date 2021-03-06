#include "cdll.h"

void runMenu(Node *headC, Node *tailC) {
  int choice;

	do {
      printf("1. Insertar nueva categoria\n");
      printf("2. Eliminar categoria actual\n");
      printf("3. Insertar nuevo objeto a categoria actal\n");
      printf("4. Mostrar categorias y objetos\n");
      printf("5. Ir a siguiente categoria\n");
      printf("6. Ir a categoria anterior\n");
      printf("7. Eliminar objeto de la categoria actual\n");
      printf("0. Salir\n");
      printf("\nSu opcion: ");
      scanf(" %d", &choice);

      switch (choice) {
        case 1:
          printf("\n\n- Insertar categoria en la lista\n");
          addNode(&headC, &tailC);
          break;
        case 2:
          printf("\n\n- Eliminar categoria de la lista\n");
          deleteNode(&headC, &tailC);
          break;
        case 3:
          printf("\n\n- Insertar objeto\n");
          addObject(headC);
          break;
        case 4:
          printf("\n\n- Mostrar categorias\n");
          printList(headC);
          break;
        case 5:
          printf("\n\n- Categoria siguiente\n");
          nextCategory(&headC, &tailC);
          break;
        case 6:
          printf("\n\n- Categoria anterior\n");
          prevCategory(&headC, &tailC);
          break;
        case 7:
          printf("\n\n- Borrar objeto de la categoria actual\n");
          deleteObject(headC);
          break;
        case 0:
          printf("\n\n- El programa ha finalizado.\n");
          break;
        default:
          printf("\n\nUps! parece que ingresaste una valor incorrecto.\n");
		  }
	} while(choice != 0);
}