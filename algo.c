//
// Created by אורון דובב on 1/3/2022.
//
#include "graph.h"
#include "limits.h"
#include <memory.h>
#include <stdio.h>


int max_node(pnode *head) {
    pnode p = *head;
    if(p) {
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
    return -1;
}

void return_default(pnode *head) {
    pnode p = *head;
    while (p) {
        p->state = 0;
        p->weight = INT_MAX - 1;
        p = p->next;
    }
}

pnode get_min(pnode *head, const int dist[], const int visited[], int len, int *flag) {
    int min = INT_MAX - 1;
    int node = -1;
    for (int i = 0; i < len; ++i) {
        if (dist[i] < min && visited[i] != 1) {
            min = dist[i];
            node = i;
        }
    }
    if (node == -1) {
        *flag = 0;
        return *head;
    }
    return get_node(head, node);
}

int shortsPath_cmd(pnode head, int src, int dest) {
    if (src == dest) {
        return -1;
    }
    int flag = 1;
    int max_len = max_node(&head) + 1;
    int max = INT_MAX - 1;
    int dist[max_len];
    for (int i = 0; i < max_len; ++i) {
        dist[i] = INT_MAX - 1;
    }
    int visited[max_len];
    memset(visited, 0, max_len);
    int visits = max_len - 1;
    int prev[max_len];
    memset(prev, -1, max_len);

    node curr = *(get_node(&head, src));
    dist[curr.node_num] = 0;
    visited[curr.node_num] = 1;
    curr.state = 1;
    curr.weight = 0;

    while (visits && curr.node_num != dest && flag) {
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
        curr = *(get_min(&head, dist, visited, max_len, &flag));
        curr.state = 1;
        visited[curr.node_num] = 1;
    }
    if (dist[dest] == max) {
        return_default(&head);
        return -1;
    } else {
        int ans = dist[dest];
        return_default(&head);
        return ans;
    }
}


void add(pnode head, int *permut, int arr[], int len) {
    int total = 0;
    for (int i = 0; i < len - 1; ++i) {
        int temp = shortsPath_cmd(head, arr[i], arr[i + 1]);
        if (temp == -1) {
            return;
        }
        total += temp;
    }
    if (total < *permut) {
        *permut = total;
    }
}

void swap(int * left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

void possibilities(pnode head, int *permut, int arr[], int len, int original_len) {
    if (len == 1) {
        add(head, permut, arr, original_len);
        return;
    } else {
        possibilities(head, permut, arr, len - 1, original_len);

        for (int i = 0; i < len; ++i) {
            if(len % 2 == 0) {
                swap(&arr[i], &arr[len-1]);
            } else {
                swap(&arr[0], &arr[len-1]);
            }
            possibilities(head, permut, arr, len - 1, original_len);
        }
    }
}


void TSP_cmd(pnode head, int cities[], int len) {
    int ans = INT_MAX;
    possibilities(head, &ans, cities, len, len);
    if(ans == INT_MAX) {
        printf("TSP shortest path: %d\n", -1);
    } else {
        printf("TSP shortest path: %d\n", ans);
    }
}

