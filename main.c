#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

static int size = 0;

int main() {
    char cmd;
    int node_size;
    pnode head = NULL; //head of Graph nodes list.
    int count = 0;
    int src, dest, weight;
    pnode src_ = NULL;
    pnode dest_ = NULL;
    //A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3

    while (scanf("%c ", &cmd) != EOF) {
        if (cmd == 'A') {
            build_graph_cmd(&head); //also delete graph if exist
            scanf("%d ", &node_size); // num of nodes
            size += node_size;
            while (count < node_size) { // create nodes for act
                insert_node_cmd(&head, count);
                count++;
            }
            while (scanf("%c ", &cmd) && cmd == 'n') {
                scanf("%d", &src);
                src_ = get_node(&head, src);
                while (scanf("%d ", &dest) != 0 && scanf("%d ", &weight) != 0) {
                    dest_ = get_node(&head, dest);
                    insert_edge(&head, src_->node_num, weight, dest_->node_num);
                }
                printGraph_cmd(head);
            }
        }
    }


    return 0;
}
//        if (cmd == 'B') {