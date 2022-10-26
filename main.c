#include "linked_list.c"
#include <stdbool.h>
#include <stdio.h>

int main() {

  node_t *list1 = NULL;
  node_t *list2 = NULL;

  for (int i = 0; i < 10; i++) {
    list1 = append(list1, i);
  }

  for (int j = 0; j < 10; j++) {
    list2 = append(list2, j);
  }

  // list1 = reverse(list1);
  // list1 = extend(list1, list2);

  // unique(list1);

  // list1 = insert_after(list1, 123, 999);

  // list1 = sort(list1);

  // list2 = duplicate_list(list1);

  // add_lists(list1, list2);

  // list1 = merge(list1, list2);
  print_list(list1);
  free_list(list1);
  // free_list(list2);

  return 0;
}
