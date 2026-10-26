#include <stdio.h>

#include "array.h"
#include "list.h"
#include "queue.h"
#include "stack.h"

int main(void) {
    int choice;

    while (1) {
        printf("1. Array\n2. Stack\n3. Queue\n4. Singly Linked List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayMenu();
                break;
            case 2:
                stackMenu();
                break;
            case 3:
                queueMenu();
                break;
            case 4:
                listMenu();
                break;
            case 5:
                return 0;
        }
    }
}
