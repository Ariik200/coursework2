#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int num);
void printList(struct Node *head);
void append(struct Node **head, int num);
void prepend(struct Node **head, int num);
void deleteByKey(struct Node **head, int key);
void deleteByValue(struct Node **head, int value);
void insertAfterKey(struct Node **head, int key, int value);
void insertAfterValue(struct Node **head, int searchValue, int newValue);

int main()
{
    struct Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete by Key\n");
        printf("5. Delete by Value\n");
        printf("6. Insert After Key\n");
        printf("7. Insert After Value\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printList(head);
            break;
        case 2:
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 3:
            printf("Enter data to prepend: ");
            scanf("%d", &data);
            prepend(&head, data);
            break;
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &data);
            deleteByKey(&head, data);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            break;
        case 6:
            printf("Enter key to insert after: ");
            scanf("%d", &data);
            int newValue;
            printf("Enter new value: ");
            scanf("%d", &newValue);
            insertAfterKey(&head, data, newValue);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &data);
            printf("Enter new value: ");
            scanf("%d", &newValue);
            insertAfterValue(&head, data, newValue);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

struct Node *createNode(int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->number = num;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

void append(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void prepend(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
}

void deleteByKey(struct Node **head, int key)
{
    struct Node *current = *head;
    struct Node *prev = NULL;

    if (current != NULL && current->number == key)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->number != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key not found in the list.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void deleteByValue(struct Node **head, int value)
{
    struct Node *current = *head;
    struct Node *prev = NULL;

    if (current != NULL && current->number == value)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->number != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Value not found in the list.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void insertAfterKey(struct Node **head, int key, int value)
{
    struct Node *current = *head;

    while (current != NULL && current->number != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key not found in the list.\n");
        return;
    }

    struct Node *newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
}

void insertAfterValue(struct Node **head, int searchValue, int newValue)
{
    struct Node *current = *head;

    while (current != NULL && current->number != searchValue)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Value not found in the list.\n");
        return;
    }

    struct Node *newNode = createNode(newValue);
    newNode->next = current->next;
    current->next = newNode;
}
