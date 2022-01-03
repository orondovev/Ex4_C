#include <stddef.h>
#include <stdlib.h>
//#include "graph.h"

typedef struct GRAPH_NODE_ *pnode;

pnode new_node(int, struct GRAPH_NODE_ *);

typedef struct edge_ {
    pnode endpoint;
    int weight;
    struct edge_ *next;
} edge, *pedge;

pedge new_edge(int, pnode, pedge);

typedef struct GRAPH_NODE_ {
    int node_num; // =1
    pedge edges; // edge_ (w = 5, endpoint = 2)
    struct GRAPH_NODE_ *next;
} node, *pnode;

void insert_node_cmd(pnode *head, int data) {
    if (*head == NULL) {
        *head = new_node(data, NULL);
        return;
    }
    pnode *phead;
    *phead = *head;
    while (*phead) {
        if ((*phead)->node_num == data) {
            //todo change edges
        }
        phead = &((*phead)->next);
    }
    *phead = new_node(data, NULL);

}

pnode new_node(int id, struct GRAPH_NODE_ *next) {
    pnode new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->node_num = id;
    new_node->next = next;
    new_node->edges = NULL;

    return new_node;
}

void insert_edge(pnode *head, pnode src, int weight, pnode dest) {

    pnode *phead;
    *phead = *head;
    while (*phead) {
        if ((*phead)->node_num == src->node_num) {
            pedge *temp_edge = NULL;
            *temp_edge = ((*phead)->edges);
            while (*temp_edge) {
                temp_edge = &((*temp_edge)->next);
            }
            *temp_edge = new_edge(weight, dest, NULL);
            return;
        }
        phead = &((*phead)->next);
    }

}

pedge new_edge(int weight, pnode dest, pedge next) {
    pedge curr_edge = (edge *) malloc(sizeof(edge));
    if (curr_edge == NULL) {
        return NULL;
    }
    curr_edge->endpoint = dest;
    curr_edge->weight = weight;
    curr_edge->next = next;

    return curr_edge;
}



