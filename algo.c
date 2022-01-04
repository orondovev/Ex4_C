//
// Created by אורון דובב on 1/3/2022.
//
#include "graph.h"
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>


int max_node(pnode *head) {
    pnode p = *head;
    int max = (p)->node_num;
    p = p->next;
    while (p) {
        if (p->node_num > max) {
            max = p->node_num;
        }
        p = p->next;
    }
    return max;
}

void copy_graph(pnode *head, pnode *new_head) {
    pnode *p = head;
    while (*p) {
        insert_node_cmd(new_head, (*p)->node_num);
        pedge *e = &((*p)->edges);
        while (*e) {
            int temp_dest = (*e);
        }
        *p = (*p)->next;
    }
}

void return_default(pnode *head) {
    pnode p = *head;
    while (p) {
        p->state = 0;
        p->weight = INFINITY;
        p = p->next;
    }
}

pnode get_min(pnode *head, const float dist[], const int visited[], int len) {
    float min = INFINITY;
    int node = 0;
    for (int i = 0; i < len; ++i) {
        if (dist[i] < min && visited[i] != 1) {
            min = dist[i];
            node = i;
        }
    }
    return get_node(head, node);
}

void shortsPath_cmd(pnode head, int src, int dest) {
    int max_len = max_node(&head) + 1;
    float dist[max_len];
    int visited[max_len];
    memset(visited, 0, max_len);
    int visits = size - 1;
    memset(dist, INFINITY, max_len);
    int prev[max_len];
    memset(prev, -1, max_len);

    node curr = *(get_node(&head, src));
    dist[curr.node_num] = 0;
    curr.state = 1;

    while (visits && curr.node_num != dest) {
        pedge *e = &(curr.edges);
        while (*e) {
            if ((*e)->endpoint->state != 1) {
                int curr_e_w = (curr.weight + (*e)->weight);
                if (curr_e_w < (*e)->endpoint->weight) {
                    dist[(*e)->endpoint->node_num] = (float) curr_e_w;
                    prev[(*e)->endpoint->node_num] = curr.node_num;
                }
            }
        }
        visits--;
        curr = *(get_min(&head, dist, visited, max_len));
        curr.state = 1;
        visited[curr.node_num] = 1;
    }
    if (dist[dest] == INFINITY) {
        printf("Dijsktra shortest path: %d", -1);
    } else {
        printf("Dijsktra shortest path: %d", (int) dist[dest]);
    }
    return_default(&head);
}

void TSP_cmd(pnode head, int cities[], int len) {

}