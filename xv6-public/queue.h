#include <stddef.h>
#include "defs.h"

struct Node {
  struct proc* process;
  struct Node* next;
};

struct Queue {
    struct Node* front; // Ponteiro para o primeiro nó da fila
    struct Node* rear;  // Ponteiro para o último nó da fila
};

struct Queue* createQueue();
void add_proc_to_queue(struct Queue* q, struct proc* p);
struct proc* select(struct Queue* q);