#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t *next;
} Node;

Node *insert_at_head(Node *head, int value) {

  Node *new_node = calloc(1, sizeof(Node));

  new_node->value = value;

  if (head != NULL) {
    new_node->next = head;
  }

  return new_node;
}

Node *insert_at_tail(Node *head, int value) {
  Node *new_node = calloc(1, sizeof(Node));

  new_node->value = value;

  if (head == NULL) {
    return NULL;
  }

  Node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;

  return head;
}

Node *delete_at_head(Node *head) {
  if (head == NULL) {
    return NULL;
  }

  Node *to_return = head->next;
  free(head);

  return to_return;
}

void *delete_at_tail(Node *head) {
  if (head == NULL) {
    return NULL;
  }

  Node *current = head;
  Node *prev = current;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  prev->next = NULL;

  free(current);
  return NULL;
}

void print_all_nodes(Node *head) {
  if (head == NULL) {
    printf("The list is empty");
    return;
  }

  Node *current = head;

  int idx = 0;
  while (current != NULL) {
    printf("Node %d: %d\n", idx, current->value);
    current = current->next;
    idx++;
  }
}

int length(Node *head) { return head == NULL ? 0 : 1 + length(head->next); }

bool is_member(Node *head, int value) {
  if (head == NULL) {
    return false;
  }

  if (head->value == value) {
    return true;
  }

  return is_member(head->next, value);
}

int count_matches(Node *head, int value) {
  if (head == NULL) {
    return 0;
  }

  if (head->value == value) {
    return 1 + count_matches(head->next, value);
  }

  return 0 + count_matches(head->next, value);
}

void replace(Node *head, int value, int replacement, bool once) {
  if (head == NULL) {
    return;
  }

  if (head->value == value) {
    head->value = replacement;

    if (once) {
      return;
    }
  }

  return replace(head->next, value, replacement, once);
}

Node *delete_first_match(Node *head, int value, bool *was_deleted) {
  if (head == NULL) {
    *was_deleted = false;
    return NULL;
  }

  if (head->value == value) {
    Node *tmp = head->next;
    free(head);
    *was_deleted = true;
    return tmp;
  }

  Node *current = head->next;
  Node *prev = head;

  while (current != NULL) {

    if (current->value == value) {
      prev->next = current->next;
      free(current);
      *was_deleted = true;
      return head;
    }

    prev = current;
    current = current->next;
  }

  *was_deleted = false;
  return head;
}
