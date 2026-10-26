#include <stdio.h>

#include "queue.h"

#define MAX_SIZE 100

static void displayQueue(int queue[], int front, int size) {
    int i;

    printf("FRONT -> ");
    for (i = 0; i < size; i++) {
        printf("[%d]", queue[(front + i) % MAX_SIZE]);
        if (i < size - 1) {
            printf(" -> ");
        }
    }
    printf(" <- REAR\n");
}

void queueMenu(void) {
    int queue[MAX_SIZE];
    int front = 0;
    int size = 0;
    int choice;
    int value;
    int rear;

    while (1) {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek front\n4. Display\n0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            return;
        }

        switch (choice) {
            case 1:
                printf("Value to enqueue: ");
                scanf("%d", &value);
                rear = (front + size) % MAX_SIZE;
                queue[rear] = value;
                size++;
                displayQueue(queue, front, size);
                break;

            case 2:
                printf("Dequeued %d.\n", queue[front]);
                front = (front + 1) % MAX_SIZE;
                size--;
                break;

            case 3:
                printf("Front value: %d\n", queue[front]);
                break;

            case 4:
                displayQueue(queue, front, size);
                break;
        }
    }
}
