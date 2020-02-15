typedef struct node {
  int data;
  int *next;
} node_t;

typedef struct queue {
  node_t *head;
  node_t *tail;
} q_t;

q_t *global_line = malloc(sizeof(node_t *)*2);
