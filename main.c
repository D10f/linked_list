#include "linked_list.c"
#include <stdio.h>

int main() {

  // Node head;
  // head.value = 34;
  // head.next = NULL;

  Node *head = NULL;

  Node *new_head = insert_at_head(head, 2);

  // printf("The new head of the linked list is: %d\n", new_head->value);

  Node *new_tail = insert_at_tail(new_head, 556);

  print_all_nodes(new_head);

  free(new_head);
  free(new_tail);

  return 0;
}
