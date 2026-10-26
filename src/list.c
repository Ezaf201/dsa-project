#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static void displayList(Node *head) {
    Node *current = head;

    printf("HEAD -> ");
    while (current != NULL) {
        printf("[%d] -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void listMenu(void) {
    Node *head = NULL;
    Node *current;
    Node *previous;
    int choice;
    int value;

    while (1) {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Delete by value\n");
        printf("4. Search\n5. Display\n0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                current = malloc(sizeof(Node));
                current->value = value;
                current->next = head;
                head = current;
                displayList(head);
                break;

            case 2:
                printf("Value: ");
                scanf("%d", &value);
                current = malloc(sizeof(Node));
                current->value = value;
                current->next = NULL;

                if (head == NULL) {
                    head = current;
                } else {
                    previous = head;
                    while (previous->next != NULL) {
                        previous = previous->next;
                    }
                    previous->next = current;
                }
                displayList(head);
                break;

            case 3:
                printf("Value to delete: ");
                scanf("%d", &value);
                current = head;
                previous = NULL;

                while (current->value != value) {
                    previous = current;
                    current = current->next;
                }

                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                displayList(head);
                break;

            case 4:
                printf("Value to search: ");
                scanf("%d", &value);
                current = head;
                while (current != NULL && current->value != value) {
                    current = current->next;
                }
                if (current != NULL) {
                    printf("Value found.\n");
                } else {
                    printf("Value not found.\n");
                }
                break;

            case 5:
                displayList(head);
                break;
        }
    }

    /* Free the remaining nodes before leaving the list menu. */
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}
