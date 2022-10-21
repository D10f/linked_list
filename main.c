#include "linked_list.c"
#include <stdio.h>

int main() {

  Node *head = NULL;
  Node *tail = NULL;

  head = insert_at_head(head, 2);
  head = insert_at_head(head, 243);
  tail = insert_at_tail(head, -12);
  head = insert_at_head(head, 756);
  tail = insert_at_tail(head, 0);
  tail = insert_at_tail(head, -111);
  head = insert_at_head(head, 45);
  tail = insert_at_tail(head, 556);

  print_all_nodes(head);

  printf("The length of the linked list is: %d\n", length(head));
  free(head);
  free(tail);

  return 0;
}
