#include "linked_list.c"
#include <stdbool.h>
#include <stdio.h>

int main() {

  Node *head = NULL;
  Node *tail = NULL;

  head = insert_at_head(head, 2);
  head = insert_at_head(head, -12);
  head = insert_at_head(head, 243);
  head = insert_at_tail(head, -12);

  // replace(head, 243, -12, false);
  print_all_nodes(head);

  // printf("The length of the linked list is: %d\n", length(head));
  // printf("Is 24 a member of this list? %d\n", is_member(head, 24));
  // printf("-12 appears in this list %d times\n", count_matches(head, -12));

  bool was_deleted = false;
  head = delete_first_match(head, -12, &was_deleted);

  print_all_nodes(head);

  return 0;
}
