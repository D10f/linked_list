#include "linked_list.c"
#include <stdbool.h>
#include <stdio.h>

int main() {

  node_t *head = NULL;

  head = append(head, 12);
  head = prepend(head, -2);
  head = prepend(head, 4);
  head = append(head, 76);
  head = append(head, 33);

  head = pop(head);
  head = unshift(head);

  head = replace(head, -2, 147);

  head = prepend(head, 33);
  head = append(head, 33);
  head = append(head, 33);
  head = prepend(head, 33);
  head = append(head, 33);

  head = filter(head, 33);

  int len = length(head);
  int find_value = 183;
  int is_member = contains(head, find_value);

  printf("List has %d elements.\n", len);

  if (is_member) {
    printf("%d is member of the list.\n", find_value);
  } else {
    printf("%d is NOT a member of the list.\n", find_value);
  }

  print_list(head);
  free_list(head);

  return 0;
}
