#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "graph.h"
#include "limits.h"

typedef struct GRAPH_NODE_ *pnode;
pnode new_node(int, struct GRAPH_NODE_ *);
void free_edges(pnode);
pnode get_node(pnode *, int );
//void delete_node_cmd(pnode *, pnode, bool);
void free_all_edges(pnode *, pnode);
void deleteGraph_cmd(pnode*);
void printGraph_cmd(pnode);

//typedef struct edge_ {
//    pnode endpoint;
//    int weight;
//    struct edge_ *next;
//} edge, *pedge;

pedge new_edge(int, pnode, pedge);

//typedef struct GRAPH_NODE_ {
//    int node_num; // =1
//    pedge edges; // edge_ (w = 5, endpoint = 2)
//    struct GRAPH_NODE_ *next;
//    int weight;
//    int state;
//} node, *pnode;

void insert_node_cmd(pnode *head, int data) {
    if (*head == NULL) {
        *head = new_node(data, NULL);
        return;
    }
    pnode *phead = NULL;
    phead = head;
    pnode *prev = head;
    while (*phead) {
        prev = &((*phead)->next);
        if ((*phead)->node_num == data) {
            delete_node_cmd(head,*phead,false);
            break;
        }
        phead = &((*phead)->next);
    }
    *phead = new_node(data, *prev);

}

pnode new_node(int id, struct GRAPH_NODE_ *next) {
    pnode new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->node_num = id;
    new_node->next = next;
    new_node->edges = NULL;
    new_node->weight = INT_MAX - 1;
    new_node->state = 0;

    return new_node;
}

pnode get_node(pnode *head, int data) {
    if(*head == NULL) {
        return NULL;
    }
    pnode p = *head;
    while (p) {
        if(p->node_num == data) {
            break;
        } else {
            p = p->next;
        }
    }
    return p;
}

void insert_edge(pnode *head, int src_, int weight, int dest_) {
    pnode src = get_node(head, src_);
    pnode dest = get_node(head, dest_);
    pnode *phead;
    phead = head;
    while (*phead) {
        if ((*phead)->node_num == src->node_num) {
            pedge *temp_edge = NULL;
            temp_edge = &((*phead)->edges);
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

void delete_node_cmd(pnode *head, pnode data, int flag) {
    if (*head == NULL) {
        return;
    }
    pnode p = (*head)->next;
    pnode *prev = head;

    while (p) {
        if (p->node_num == data->node_num) {
            *prev = p->next;
            if(flag) {
                free_all_edges(head,p);
            } else{
                free_edges(p);
            }
            free(p);
            p = *prev;
        }
        else{
            prev= &(p->next);
            p = p->next;
        }
    }
}

void free_all_edges(pnode *head,pnode node) {
    if(node->edges) {
        free_edges(node);
    }
    pnode p = *head;
    while (p) {
        pedge *prev = &((p)->edges);
        pedge e = ((p)->edges);
        while (e && p->node_num != node->node_num) {
            if(e->endpoint->node_num == node->node_num) {
                *prev = e->next;
                free(e);
                e = *prev;
            } else {
                prev = &(e->next);
                e = e->next;
            }
        }
        p = p->next;
    }
}

void free_edges(pnode node){
    if(node->edges == NULL){
        return;
    }
    pedge e = node->edges;
    pedge *prev = &(node->edges);
    while(e){
        *prev = e->next;
        free(e);
        e = *prev;
    }
}

void deleteGraph_cmd(pnode* head) {
    if(*head == NULL) {
        return;
    }
    while (*head) {
        delete_node_cmd(head,*head,true);
        *head = (*head)->next;
    }
    *head = NULL;
}

void build_graph_cmd(pnode *head) {
    if(*head != NULL) {
        deleteGraph_cmd(head);
    }
}

void print_edges(pedge eHead) {
    printf("edges[");
    while (eHead) {
        printf(" endP: %d, W: %d ", eHead->endpoint->node_num, eHead->weight);
        eHead = eHead->next;
    }
    printf("] ");
}

void print_node(pnode head) {
    printf("ID: %d ", head->node_num);
    print_edges(head->edges);
    if(head->next) {
        printf("Next: %d \t", head->next->node_num);
    } else {
        printf("Next: NULL \t");
    }

}

void printGraph_cmd(pnode head) {
    while (head) {
        print_node(head);
        head = head->next;
    }
}
