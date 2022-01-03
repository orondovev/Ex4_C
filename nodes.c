#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"

struct node {
    int data; // for node
    struct node *link; // memory allocate next node
};

int node() {
    // create first node
    struct node *head = malloc(sizeof(struct node));
    if (head != NULL) {
        return 0;
    }
    //head -> data = //first node
    head->link = NULL;

    //create second node
    struct node *current = malloc(sizeof(struct node));
    if (current != NULL) {
        return 0;
    }
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->link;
    }
    return 0;
}
