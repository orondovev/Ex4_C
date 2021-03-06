#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main() {
    char cmd ='0';
    int node_size;
    pnode head = NULL; //head of Graph nodes list.
    int count = 0;
    int src, dest, weight;
    pnode dest_ = NULL;
    //A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 S 0 2
    //A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 B 5 0 4 2 1 D 2 2
    //A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 S 2 0
    scanf("%c", &cmd);
    while (1) {
        if (cmd == ' ') {
            scanf("%c", &cmd);
            if (cmd == ' ') {
                break;
            }
        }
        if (cmd == 'A') {
            build_graph_cmd(&head); //also delete graph if exist
            scanf("%d", &node_size); // num of nodes
            count = 0;
            while (count < node_size) { // create nodes for act
                insert_node_cmd(&head, count);
                count++;
            }
            scanf("%c", &cmd);
            while (scanf("%c", &cmd) != 0 && cmd == 'n') {
                scanf("%d", &src);
//                src_ = get_node(&head, src);
                while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0) {
//                    dest_ = get_node(&head, dest);
                    insert_edge(&head, src, weight, dest);
                }
//                printGraph_cmd(head);
            }

        }
        else if (cmd == 'B') {
            scanf("%d", &src);
            insert_node_cmd(&head, src);
            while (scanf("%d ", &dest) != 0 && scanf("%d", &weight) != 0) {
                dest_ = get_node(&head, dest);
                insert_edge(&head, src, weight, dest_->node_num);
            }
            scanf(" %c", &cmd);

//            printGraph_cmd(head);
//            printf("\n");
//            printGraph_cmd(head);
        }
        else if (cmd == 'D') {
            scanf("%d", &src);
            delete_node_cmd(&head, get_node(&head, src), 1);
            scanf("%c", &cmd);
//            printGraph_cmd(head);
//            printf("\n");
        }
        else if (cmd == 'S') {
            src = 0;
            dest = 0;
            scanf("%d", &src);
            scanf("%d", &dest);
            printf("Dijsktra shortest path: %d \n", shortsPath_cmd(head, src, dest));
            scanf("%c", &cmd);
        }
//        printGraph_cmd(head);
        else if (cmd == 'T') {
            shortsPath_cmd(head, 3, 2);
            int nodes;
            int n;
            scanf("%d", &n);
            int cities[n];

            for (int i = 0; i < n; ++i) {
                scanf("%d", &nodes);
                cities[i] = nodes;
            }
            TSP_cmd(head, cities, n);
            scanf("%c", &cmd);
        }
        else if (cmd != 'A' && cmd != 'B' && cmd != 'D' && cmd != 'S' && cmd != 'T') {
            break;
        }
//        else {
//            scanf("%c", &cmd);
//            if (cmd == ' ') {
//                break;
//            }
//        }
    }
    deleteGraph_cmd(&head);
//    printGraph_cmd(head);
//    exit(1);
    return 0;
//    exit(1);
}
