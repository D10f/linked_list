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
node_t *extend(node_t *head1, node_t *head2);
node_t *reverse(node_t *head);
node_t *sort(node_t *head);
node_t *insert_after(node_t *head, int target, int value);
void unique(node_t *head);
void print_list(node_t *head);
void free_list(node_t *head);
int length(node_t *head);
bool contains(node_t *head, int value);
int count_value(node_t *head, int value);

void add_lists(node_t *head1, node_t *head2);
node_t *duplicate_list(node_t *head);
node_t *merge(node_t *list1, node_t *list2);

/*

list1 = 1 -> 2 -> 4 -> 16
list2 = 0 -> 1 -> 4 -> 6 -> 8 -> 23

result = 0 -> 1 -> 2 -> 4 -> 6 -> 8 -> 16 -> 23
*/
