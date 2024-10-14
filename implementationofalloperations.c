// C program for all operations in
// the Singly Linked List

#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;

// Function to create list with n nodes initially
void createList() {
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            if (newnode == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
            newnode->link = NULL;
            start = newnode;
            temp = start;
            printf("\nEnter number to be inserted: ");
            scanf("%d", &data);
            start->info = data;

            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                if (newnode == NULL) {
                    printf("Memory allocation failed\n");
                    return;
                }
                newnode->link = NULL;
                temp->link = newnode;
                printf("\nEnter number to be inserted: ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    } else {
        printf("\nThe list is already created\n");
    }
}

// Function to traverse the linked list
void traverse() {
    struct node* temp;

    // List is empty
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

// Function to insert at the front of the linked list
void insertAtFront() {
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;

    // Pointer of temp will be assigned to start
    temp->link = start;
    start = temp;
}

// Function to insert at the end of the linked list
void insertAtEnd() {
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Enter the number
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    // Changes links
    temp->link = NULL; // NULL instead of 0 for clarity
    temp->info = data;
    head = start;
    if (head == NULL) { // If the list is empty
        start = temp;
        return;
    }
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

// Function to insert at any specified position in the linked list
void insertAtPosition() {
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Enter the position and data
    printf("\nEnter position and data: ");
    scanf("%d %d", &pos, &data);

    // Change Links
    temp = start;
    newnode->info = data;
    newnode->link = NULL;
    if (pos == 1) {
        newnode->link = start;
        start = newnode;
        return;
    }
    while (i < pos - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }
    if (temp == NULL) {
        printf("Position does not exist\n");
        free(newnode);
        return;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

// Function to delete from the front of the linked list
void deleteFirst() {
    struct node* temp;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        start = start->link;
        free(temp);
    }
}

// Function to delete from the end of the linked list
void deleteEnd() {
    struct node *temp, *prevnode;
    if (start == NULL) {
        printf("\nList is Empty\n");
    } else {
        temp = start;
        if (temp->link == NULL) { // Only one node
            free(temp);
            start = NULL;
            return;
        }
        while (temp->link != NULL) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = NULL;
    }
}

// Function to delete from any specified position from the linked list
void deletePosition() {
    struct node *temp, *position;
    int i = 1, pos;

    // If LL is empty
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    // Otherwise
    else {
        printf("\nEnter index: ");
        scanf("%d", &pos);
        if (pos == 1) {
            deleteFirst();
            return;
        }
        temp = start;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->link;
            i++;
        }
        if (temp == NULL || temp->link == NULL) {
            printf("Position does not exist\n");
            return;
        }
        position = temp->link;
        temp->link = position->link;

        // Free memory
        free(position);
    }
}

// Function to find the maximum element in the linked list
void maximum() {
    struct node* temp;

    // If LL is empty
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = start;
    int max = temp->info;

    // Traverse LL and update the maximum element
    while (temp != NULL) {
        if (max < temp->info) {
            max = temp->info;
        }
        temp = temp->link;
    }
    printf("\nMaximum number is: %d\n", max);
}

// Function to find the mean of the elements in the linked list
void mean() {
    struct node* temp;

    // If LL is empty
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = start;

    // Stores the sum and count of elements in the LL
    int sum = 0, count = 0;
    float m;

    // Traverse the LL
    while (temp != NULL) {
        sum += temp->info;
        temp = temp->link;
        count++;
    }

    // Find the mean
    m = (float)sum / count;

    // Print the mean value
    printf("\nMean is %f\n", m);
}

// Function to sort the linked list in ascending order
void sort() {
    struct node* current = start;
    struct node* index = NULL;
    int temp;

    // If LL is empty
    if (start == NULL) {
        return;
    }

    // Else
    while (current != NULL) {
        index = current->link;

        // Traverse the LL nestedly and find the minimum element
        while (index != NULL) {
            if (current->info > index->info) {
                temp = current->info;
                current->info = index->info;
                index->info = temp;
            }
            index = index->link;
        }

        // Update the current
        current = current->link;
    }
}

// Function to reverse the linked list
void reverseLL() {
    struct node *t1, *t2;
    t1 = t2 = NULL;

    // If LL is empty
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    // Else
    while (start != NULL) {
        t2 = start->link;
        start->link = t1;
        t1 = start;
        start = t2;
    }
    start = t1;

    // New head Node
    struct node* temp = start;

    printf("Reversed linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

// Driver code
int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Insert At Front\n");
        printf("4. Insert At End\n");
        printf("5. Insert At Position\n");
        printf("6. Delete First\n");
        printf("7. Delete End\n");
        printf("8. Delete At Position\n");
        printf("9. Find Maximum\n");
        printf("10. Find Mean\n");
        printf("11. Sort List\n");
        printf("12. Reverse List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: traverse(); break;
            case 3: insertAtFront(); break;
            case 4: insertAtEnd(); break;
            case 5: insertAtPosition(); break;
            case 6: deleteFirst(); break;
            case 7: deleteEnd(); break;
            case 8: deletePosition(); break;
            case 9: maximum(); break;
            case 10: mean(); break;
            case 11: sort(); break;
            case 12: reverseLL(); break;
            case 0: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice\n"); break;
        }
    } while (choice != 0);

    return 0;
}

