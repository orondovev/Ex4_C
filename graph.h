#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;
static int size;
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int weight;
    int state;
} node, *pnode;

void build_graph_cmd(pnode *head);

void insert_node_cmd(pnode *head, int data);
pnode get_node(pnode *head, int data);

pnode get_node(pnode *, int );

void insert_edge(pnode *head, int, int, int);

void delete_node_cmd(pnode *head, pnode data, int);

void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode *head);

int shortsPath_cmd(pnode head, int src, int dest);

void TSP_cmd(pnode head, int cities[], int len);

#endif
