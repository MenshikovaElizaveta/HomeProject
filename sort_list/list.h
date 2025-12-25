#pragma once

typedef struct Node {
  int num;
  struct Node *next;
} Node;

Node *createNode(int val);
void put(Node **head, int val);
void pop(Node **head, int val);
void printlist(Node *head);
void freeList(Node **head);
