#include "queue.h"

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) kalloc();
    if (q == 0)
        panic("createQueue: falha ao alocar memória");
    q->front = q->rear = NULL;
    return q;
}

void add_proc_to_queue(struct Queue* q, struct proc* p) {
    // Cria um novo nó para o processo
    struct Node* newNode = (struct Node*) kalloc();
    if (newNode == 0)
        panic("enqueue: falha ao alocar memória");

    newNode->process = p;
    newNode->next = NULL;

    // Se a fila estiver vazia, o novo nó será tanto a frente quanto o final da fila
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Adiciona o novo nó ao final da fila e atualiza o ponteiro rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Função para desenfileirar um processo da fila
struct proc* select(struct Queue* q) {
    // Se a fila estiver vazia, retorna NULL
    if (q->front == NULL)
        return NULL;

    // Remove o nó da frente da fila e atualiza o ponteiro front
    struct Node* temp = q->front;
    struct proc* p = temp->process;
    q->front = q->front->next;

    // Se a frente se tornou NULL, também atualizamos o ponteiro rear para NULL
    if (q->front == NULL)
        q->rear = NULL;

    // Libera a memória alocada para o nó removido
    kfree((char*)temp);

    return p;
}