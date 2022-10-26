#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// append
node_t *append(node_t *head, int value) {

  node_t *new_node = calloc(1, sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  node_t *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;

  return head;
}

// prepend
node_t *prepend(node_t *head, int value) {
  node_t *new_node = calloc(1, sizeof(node_t));
  new_node->value = value;

  if (head == NULL) {
    return new_node;
  }

  new_node->next = head;

  return new_node;
}

// insert after
node_t *insert_after(node_t *head, int target, int value) {
  node_t *new_node = calloc(1, sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  node_t *current = head;

  while (current->next != NULL) {

    if (current->value == target) {

      new_node->next = current->next;
      current->next = new_node;

      return head;
    }

    current = current->next;
  }

  current->next = new_node;

  return head;
}

// extend
node_t *extend(node_t *head1, node_t *head2) {
  if (head1 == NULL) {
    return head2;
  }

  if (head2 == NULL) {
    return head1;
  }

  node_t *current = head1;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = head2;

  return head1;
}

// pop
node_t *pop(node_t *head) {
  if (head == NULL) {
    return NULL;
  }

  if (head->next == NULL) {
    free(head);
    return NULL;
  }

  node_t *current = head;
  node_t *prev = current;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  prev->next = NULL;

  free(current);
  return head;
}

// unshift
node_t *unshift(node_t *head) {
  if (head == NULL) {
    return NULL;
  }

  node_t *new_head = head->next;
  free(head);

  return new_head;
}

// filter
node_t *filter(node_t *head, int value) {
  if (head == NULL) {
    return NULL;
  }

  node_t *new_head = head;

  while (new_head->value == value) {
    node_t *tmp = new_head;
    new_head = new_head->next;
    free(tmp);

    if (new_head == NULL) {
      return NULL;
    }
  }

  node_t *current = new_head->next;
  node_t *prev = new_head;

  while (current != NULL) {

    if (current->value == value) {
      node_t *tmp = current;
      prev->next = current->next;
      current = current->next;
      free(tmp);
    } else {
      prev = current;
      current = current->next;
    }
  }

  return new_head;
}

// replace
node_t *replace(node_t *head, int value, int replacement) {
  if (head == NULL) {
    return NULL;
  }

  node_t *current = head;

  while (current != NULL) {
    if (current->value == value) {
      current->value = replacement;
      break;
    }

    current = current->next;
  }

  return head;
}

// reverse
node_t *reverse(node_t *head) {
  if (head == NULL) {
    return NULL;
  }

  if (head->next == NULL) {
    return head;
  }

  node_t *current = head;
  node_t *next_node = head->next;

  current->next = NULL;

  while (next_node != NULL) {
    node_t *tmp = next_node->next;
    next_node->next = current;
    current = next_node;
    next_node = tmp;
  }

  return current;
}

// sort
node_t *sort(node_t *head) {
  if (head == NULL) {
    return NULL;
  }

  if (head->next == NULL) {
    return head;
  }

  node_t *prev = head;
  node_t *current = head->next;

  while (current != NULL) {
    if (prev->value > current->value) {
      int tmp = prev->value;
      prev->value = current->value;
      current->value = tmp;
      prev = head;
      current = head->next;
    } else {
      prev = current;
      current = current->next;
    }
  }

  return head;
}

// unique
void unique(node_t *head) {
  if (head == NULL) {
    return;
  }

  node_t *current = head;

  while (current != NULL) {

    int target = current->value;
    node_t *outer_next = current->next;
    node_t *inner_current = current->next;
    node_t *inner_prev = current;

    while (inner_current != NULL) {

      if (inner_current->value == target) {
        node_t *tmp = inner_current;
        inner_prev->next = inner_current->next;
        inner_current = inner_current->next;

        if (outer_next->value == target) {
          outer_next = inner_current;
        }

        free(tmp);
        continue;
      }

      inner_prev = inner_current;
      inner_current = inner_current->next;
    }

    current = outer_next;
  }
}

// print
void print_list(node_t *head) {
  node_t *current = head;

  int idx = 0;
  while (current != NULL) {
    printf("Node %d: %d\n", idx, current->value);
    current = current->next;
    idx++;
  }
}

// free
void free_list(node_t *head) {
  node_t *current = head;

  while (current != NULL) {
    node_t *tmp = current;
    current = current->next;
    free(tmp);
  }
}

// length
int length(node_t *head) { return head == NULL ? 0 : 1 + length(head->next); }

// contains
bool contains(node_t *head, int value) {
  if (head == NULL) {
    return false;
  }

  if (head->value == value) {
    return true;
  }

  return contains(head->next, value);
}

// count
int count_value(node_t *head, int value) {
  if (head == NULL) {
    return 0;
  }

  if (head->value == value) {
    return 1 + count_value(head->next, value);
  }

  return 0 + count_value(head->next, value);
}

// add lists
void add_lists(node_t *head1, node_t *head2) {
  if (head1 == NULL || head2 == NULL) {
    return;
  }

  head1->value = head1->value + head2->value;

  add_lists(head1->next, head2->next);
}

node_t *duplicate_list(node_t *head) {
  if (head == NULL) {
    return NULL;
  }

  node_t *new_node = calloc(1, sizeof(node_t));
  new_node->value = head->value;
  new_node->next = duplicate_list(head->next);

  return new_node;
}

node_t *merge(node_t *list1, node_t *list2) {
  if (list1 == NULL) {
    return list2;
  }

  if (list2 == NULL) {
    return list1;
  }

  node_t *new_head, *new_current;
  node_t *current1 = list1;
  node_t *current2 = list2;

  if (current1->value < current2->value) {
    new_head = current1;
    current1 = current1->next;
  } else if (current1->value > current2->value) {
    new_head = current2;
    current2 = current2->next;
  } else {
    new_head = current1;
    current1 = current1->next;
    node_t *tmp = current2;
    current2 = current2->next;
    free(tmp);
  }

  new_current = new_head;

  while (current1 != NULL && current2 != NULL) {
    if (current1->value <= current2->value) {
      new_current->next = current1;
      new_current = current1;
      current1 = current1->next;
    } else {
      new_current->next = current2;
      new_current = current2;
      current2 = current2->next;
    }
  }

  if (current1 == NULL) {
    new_current->next = current2;
  } else {
    new_current->next = current1;
  }

  return new_head;
}
