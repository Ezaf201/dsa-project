#include <stdio.h>

#include "array.h"

#define MAX_SIZE 100

static void displayArray(int array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("[%d] ", array[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf(" %d  ", i);
    }
    printf("\n");
}

void arrayMenu(void) {
    int array[MAX_SIZE];
    int size;
    int choice;
    int index;
    int value;
    int i;

    printf("Enter the number of items in the array: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter item %d: ", i);
        scanf("%d", &array[i]);
    }

    while (1) {
        printf("\n--- ARRAY ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Update\n5. Display\n0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            return;
        }

        switch (choice) {
            case 1:
                printf("Index to insert at: ");
                scanf("%d", &index);
                printf("Value: ");
                scanf("%d", &value);
                for (i = size; i > index; i--) {
                    array[i] = array[i - 1];
                }
                array[index] = value;
                size++;
                displayArray(array, size);
                break;

            case 2:
                printf("Index to delete: ");
                scanf("%d", &index);
                for (i = index; i < size - 1; i++) {
                    array[i] = array[i + 1];
                }
                size--;
                displayArray(array, size);
                break;

            case 3:
                printf("Value to search: ");
                scanf("%d", &value);
                for (i = 0; i < size; i++) {
                    if (array[i] == value) {
                        printf("Found at index %d.\n", i);
                        break;
                    }
                }
                if (i == size) {
                    printf("Value not found.\n");
                }
                break;

            case 4:
                printf("Index to update: ");
                scanf("%d", &index);
                printf("New value: ");
                scanf("%d", &array[index]);
                displayArray(array, size);
                break;

            case 5:
                displayArray(array, size);
                break;
        }
    }
}
