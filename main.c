#include "linked_list.c"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/**
 * TODO: Extending the library
 *
 * - Add, delete, replace values in the list at a given index
 * - Swap two nodes at given indeces
 * - Swap head and tail nodes
 * - Implement different sorting algorithms
 * - Allow extend, add_lists and merge to accept any number of lists
 */

int main() {

  node_t *list1 = NULL;
  node_t *list2 = NULL;

  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    list1 = append(list1, rand() % 99);
  }

  for (int j = 0; j < 10; j++) {
    list2 = append(list2, rand() % 99);
  }

  list1 = sort(list1);
  list2 = sort(list2);

  list1 = merge(list1, list2);

  print_list(list1);
  free_list(list1);

  return 0;
}
