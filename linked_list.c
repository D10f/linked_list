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
