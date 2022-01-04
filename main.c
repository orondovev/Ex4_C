#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    char cmd;
    int node_size;
    char *file = (char *)malloc((sizeof (char) ));
    pnode head = NULL; //head of Graph nodes list.
    while (scanf("%c ",&cmd) != EOF) {
        if(cmd == 'A') {
            build_graph_cmd(&head);
            scanf("%d ", &node_size);
            int count = 0;
            while (count < node_size) {
                insert_node_cmd(&head, count);
                count++;
            }
            count = 0;
            char n;
            while (count < node_size) {
                int src;
                if(scanf("%d ", &src) ==1 && scanf("%d ", &src) != EOF ) {
                    int end_p;
                    while (scanf("%d ", &end_p) == 1) {
                        int weight;
                        scanf("%d ", &weight);
                        insert_edge(&head,src, weight, end_p);
                    }
                }
                count++;

            }
        }
        printGraph_cmd(head);
    }
    return 0;
}
