#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

static int size;
int main() {
    char cmd;
    int node_size;
//    char *file = (char *)malloc((sizeof (char) ));
    pnode head = NULL; //head of Graph nodes list.
    int count = 0;
    int src, dest, weight;
    //A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3
    while ((scanf("%c ", &cmd)) != EOF) {
        if (cmd == 'A') {
            build_graph_cmd(&head); //also delete graph if exist
            scanf("%d ", &node_size); // num of nodes
            while (count < node_size) { // create nodes for act
                insert_node_cmd(&head, count);
                count++;
                size++;
                scanf("%c ", &cmd);
                scanf("%d ", src);
                while (cmd == 'n' && src) {
                    scanf("%d ", dest);
                    scanf("%d ", weight);
                    insert_edge(head, src, dest, weight);
                }
            }
        }
//        if (cmd == 'B') {
        }
//    }
//    if (cmd == 'n', &cmd) {
    }
//}



//            build_graph_cmd(&head);
//            scanf("%d ", &node_size);
//            int count = 0;
//            while (count < node_size) {
//                insert_node_cmd(&head, count);
//                count++;
//            }
//            count = 0;
//            char n;
//            while (count < node_size) {
//                int src;
//                if(scanf("%d ", &src) ==1 && scanf("%d ", &src) != EOF ) {
//                    int end_p;
//                    while (scanf("%d ", &end_p) == 1) {
//                        int weight;
//                        scanf("%d ", &weight);
//                        insert_edge(&head,src, weight, end_p);
//                    }
//                }
//                count++;
//            }
//        }
//        printGraph_cmd(head);
//    }
//    return 0;
//}
