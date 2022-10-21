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
    return new_node;
  }

  Node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;

  return new_node;
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

int length(Node *head) {
  return head == NULL ? 0 : 1 + length(head->next);
}
