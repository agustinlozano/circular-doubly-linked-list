#include "cdll.h"

int main(void) {
    Node *headCat = NULL;
    Node *tailCat = NULL;

    printf("Circular doubly linked list\n\n");
    runMenu(headCat, tailCat);

    return EXIT_SUCCESS;
}
