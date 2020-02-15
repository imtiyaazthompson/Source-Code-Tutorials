#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  int *next;
} node_t;

typedef struct queue {
  node_t *head;
  node_t *tail;
} q_t;

node_t *head = NULL;
node_t *prev = NULL;
node_t *curr = NULL;

q_t *line;

void push(int data)
{
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;

  if (head == NULL) {
    head = node;
    curr = head;
    return;
  }
  curr->next = node;
  curr = node;
}

void init_queue()
{
  line->head = head;
  line->tail = curr;
}

void dump()
{
  node_t *curr = line->head;
  while (curr != NULL) {
    printf("Line has: %d\n", curr->data);
    curr = curr->next;
  }
  printf("Head has: %d\n", line->head->data);
  printf("Tail has: %d\n", line->tail->data);
}

int main(int argc, char **argv)
{
  int i = argc;
  int j;
  for (j = 1; j < i; j++) {
    push(atoi(argv[j]));
  }

  init_queue();
  dump();
}
