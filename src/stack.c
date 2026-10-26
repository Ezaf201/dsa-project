#include <stdio.h>

#include "stack.h"

#define MAX_SIZE 100

static void displayStack(int stack[], int top) {
    int i;

    for (i = top; i >= 0; i--) {
        if (i == top) {
            printf("TOP -> [%d]\n", stack[i]);
        } else {
            printf("       [%d]\n", stack[i]);
        }
    }
    printf("       BOTTOM\n");
}

void stackMenu(void) {
    int stack[MAX_SIZE];
    int top = -1;
    int choice;
    int value;

    while (1) {
        printf("\n--- STACK ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            return;
        }

        switch (choice) {
            case 1:
                printf("Value to push: ");
                scanf("%d", &value);
                stack[++top] = value;
                displayStack(stack, top);
                break;

            case 2:
                printf("Popped %d.\n", stack[top--]);
                break;

            case 3:
                printf("Top value: %d\n", stack[top]);
                break;

            case 4:
                displayStack(stack, top);
                break;
        }
    }
}
