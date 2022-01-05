//
// Created by אורון דובב on 1/3/2022.
//
#include "graph.h"
#include <math.h>
#include "limits.h"
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
        p->weight = INT_MAX;
        p = p->next;
    }
}

pnode get_min(pnode *head, const int dist[], const int visited[], int len) {
    int min = INT_MAX;
    int node = 0;
    for (int i = 0; i < len; ++i) {
        if (dist[i] < min && visited[i] != 1) {
            min = dist[i];
            node = i;
        }
    }
    return get_node(head, node);
}

int shortsPath_cmd(pnode head, int src, int dest) {
    int max_len = max_node(&head) + 1;
    int dist[max_len];
    int visited[max_len];
    memset(visited, 0, max_len);
    int visits = max_len - 1;
    memset(dist, INFINITY, max_len);
    int prev[max_len];
    memset(prev, -1, max_len);

    node curr = *(get_node(&head, src));
    dist[curr.node_num] = 0;
    visited[curr.node_num] = 1;
    curr.state = 1;
    curr.weight = 0;

    while (visits && curr.node_num != dest) {
        pedge *e = &(curr.edges);
        while (*e) {
            if ((*e)->endpoint->state != 1) {
                int curr_e_w = (curr.weight + (*e)->weight);
                if (curr_e_w < (*e)->endpoint->weight) {
                    dist[(*e)->endpoint->node_num] = curr_e_w;
                    prev[(*e)->endpoint->node_num] = curr.node_num;
                    (*e)->endpoint->weight = curr_e_w;
                }
            }
            *e = (*e)->next;
        }
        visits--;
        curr = *(get_min(&head, dist, visited, max_len));
        curr.state = 1;
        visited[curr.node_num] = 1;
    }
    if (dist[dest] == INT_MAX) {
        printf("Dijsktra shortest path: ");
        return -1;
    } else {
        printf("Dijsktra shortest path: ");
        int ans = dist[dest];
        return_default(&head);
        return ans;
    }
}

int cmpfunc(const void *a, const void *b) //what is it returning?
{
    return (*(int *) a - *(int *) b); //What is a and b?
}

int TSP_rec(pnode head, int index, int cities[], int len, int val, int final_val) {
    if (len == 0) {
        return 0;
    }


    for (int i = 0; i < len; ++i) {
        int t_val = val + shortsPath_cmd(head, index, cities[i]);
        int curr_val = t_val + TSP_rec(head, cities[i], cities, len - 1, t_val, final_val);

        if (curr_val < final_val) {
            final_val = curr_val;
        }

    }
    return final_val;
}

void TSP_cmd(pnode head, int cities[], int len) {
    float min = INFINITY;
    qsort(cities, sizeof(int), len, cmpfunc);

    int ans = TSP_rec(head, 1, cities, len, 0, INFINITY);

    printf("TSP shortest path: %d\n", ans);
}

