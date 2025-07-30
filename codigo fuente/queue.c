#include <stdio.h>
/*
  Referencia: https://frontendmasters.com/courses/algorithms/queue/

  Primero en entrar, primero en salir (FIFO).
 */
typedef struct Node {
  struct Node *next;
  int value;
} Node;

Node NewNode(int value) {
  Node node = {.value = value};
  return node;
}

typedef struct {
  struct Node *head;
  struct Node *tail;
  int size;
} Queue;

Queue NewQueue() {
  Queue queue;
  queue.size = 0;
  queue.head = nullptr;
  queue.tail = nullptr;

  return queue;
}

void Push(Queue *queue, struct Node *node) {
  queue->size++;
  if (queue->head == NULL) {
    queue->head = node;
    queue->tail = node;
  } else {
    queue->tail->next = node;
    queue->tail = node;
  }
}

Node *Pop(Queue *queue) {
  if (queue->head == NULL) {
    return nullptr;
  }

  queue->size--;
  Node *head = queue->head;
  queue->head = head->next;

  return head;
}

void Print(Queue queue) {
  Node *head = queue.head;

  while (head != NULL) {
    printf("%d -> ", head->value);

    head = head->next;
  };
  printf("NULL\n");
}

int main() {
  Queue queue = NewQueue();
  Node one = NewNode(1);
  Push(&queue, &one);
  Node two = NewNode(2);
  Push(&queue, &two);
  Print(queue);

  Pop(&queue);
  Print(queue);

  Node three = NewNode(3);
  Push(&queue, &three);
  Print(queue);
}
