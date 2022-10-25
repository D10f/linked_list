#ifndef LINKED_LIST
#define LINKED_LIST
#endif

#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
} node_t;

node_t *append(node_t *head, int value);
node_t *prepend(node_t *head, int value);
node_t *pop(node_t *head);
node_t *unshift(node_t *head);
node_t *filter(node_t *head, int value);
node_t *replace(node_t *head, int value, int replacement);
void print_list(node_t *head);
void free_list(node_t *head);
int length(node_t *head);
bool contains(node_t *head, int value);
int count_value(node_t *head, int value);
node_t *extend(node_t *head1, node_t *head2);
node_t *reverse(node_t *head);
