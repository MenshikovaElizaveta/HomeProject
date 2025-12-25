#include "test_list.h"
#include "../list.h"
#include <stdbool.h>
#include <stdlib.h>

bool test_put() {
  Node *head = NULL;

  put(&head, 30);
  put(&head, 10);
  put(&head, 20);

  bool result = (head != NULL) && (head->num == 10) &&
                (head->next->num == 20) && (head->next->next->num == 30) &&
                (head->next->next->next == NULL);

  freeList(&head);
  return result;
}

bool test_pop() {
  Node *head = NULL;

  put(&head, 10);
  put(&head, 5);
  put(&head, 15);
  pop(&head, 10);

  bool result1 =
      (head->num == 5) && (head->next->num == 15) && (head->next->next == NULL);

  pop(&head, 5);

  bool result2 = (head->num == 15) && (head->next == NULL);

  pop(&head, 15);

  bool result3 = (head == NULL);

  freeList(&head);

  return (result1 && result2 && result3);
}

bool test_empty() {
  Node *head = NULL;

  pop(&head, 999);

  bool result1 = (head == NULL);

  put(&head, 42);

  bool result2 = (head->num == 42) && (head->next == NULL);

  pop(&head, 42);

  bool result3 = (head == NULL);

  pop(&head, 42);

  bool result4 = (head == NULL);

  freeList(&head);

  return (result1 && result2 && result3 && result4);
}

bool test_double() {
  Node *head = NULL;

  put(&head, 5);
  put(&head, 5);
  put(&head, 5);

  bool result1 = (head->num == 5) && (head->next->num == 5) &&
                 (head->next->next->num == 5) &&
                 (head->next->next->next == NULL);

  pop(&head, 5);

  bool result2 =
      (head->num == 5) && (head->next->num == 5) && (head->next->next == NULL);

  pop(&head, 5);

  bool result3 = (head->num == 5) && (head->next == NULL);

  pop(&head, 5);

  bool result4 = (head == NULL);

  freeList(&head);

  return (result1 && result2 && result3 && result4);
}

bool run_tests(void) {
  return test_put() && test_pop() && test_empty() && test_double();
}