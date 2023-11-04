#include <stdio.h>
#include <string.h>

typedef struct Carte {
    char titlu[100];
    char autor[50];
    int an_publicare;
    struct Carte* next;
} Carte;

void inserareCarteLaSfarsit(Carte** lista, char titlu[], char autor[], int an_publicare) {
    Carte* nouaCarte = (Carte*)malloc(sizeof(Carte));
    strcpy(nouaCarte->titlu, titlu);
    strcpy(nouaCarte->autor, autor);
    nouaCarte->an_publicare = an_publicare;
    nouaCarte->next = NULL;

    if (*lista == NULL) {
        *lista = nouaCarte;
    } else {
        Carte* temp = *lista;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nouaCarte;
    }
}

void stergereCarteDupaTitlu(Carte** lista, char titlu[]) {
    Carte* temp = *lista;
    Carte* anterior = NULL;

    while (temp != NULL) {
        if (strcmp(temp->titlu, titlu) == 0) {
            if (anterior == NULL) {
                *lista = temp->next;
            } else {
                anterior->next = temp->next;
            }
            free(temp);
            return;
        }
        anterior = temp;
        temp = temp->next;
    }
}

void afisareCartiAutor(Carte* lista, char autor[]) {
    Carte* temp = lista;

    while (temp != NULL) {
        if (strcmp(temp->autor, autor) == 0) {
            printf("Titlu: %s, Autor: %s, An Publicare: %d\n", temp->titlu, temp->autor, temp->an_publicare);
        }
        temp = temp->next;
    }
}

void actualizareAnPublicare(Carte* lista, char titlu[], int noulAn) {
    Carte* temp = lista;

    while (temp != NULL) {
        if (strcmp(temp->titlu, titlu) == 0) {
            temp->an_publicare = noulAn;
            return;
        }
        temp = temp->next;
    }
}

// Funcție pentru a elibera memoria alocată pentru lista de cărți
void eliberareLista(Carte** lista) {
    while (*lista != NULL) {
        Carte* temp = *lista;
        *lista = (*lista)->next;
        free(temp);
    }
}

int main() {
    Carte* lista = NULL;

    inserareCarteLaSfarsit(&lista, "Carte 1", "Autor 1", 2000);
    inserareCarteLaSfarsit(&lista, "Carte 2", "Autor 2", 2010);
    inserareCarteLaSfarsit(&lista, "Carte 3", "Autor 1", 1995);

    afisareCartiAutor(lista, "Autor 1");
    stergereCarteDupaTitlu(&lista, "Carte 1");
    afisareCartiAutor(lista, "Autor 1");

    actualizareAnPublicare(lista, "Carte 2", 2022);

    eliberareLista(&lista);

    return 0;
}










/*

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool is_empty(struct Stack *stack) {
    return stack->top == -1;
}

bool is_full(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow, cannot push %d\n", value);
    } else {
        stack->items[++stack->top] = value;
    }
}

int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

int peek(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Is the stack empty? %s\n", is_empty(&stack) ? "Yes" : "No");
    printf("Top element: %d\n", peek(&stack));

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    printf("Stack size: %d\n", stack.top + 1);

    return 0;
}





*/



















// Linked list implementation in C
/*
#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
    int value;
    struct node * ;
};

// print the linked list value
void printLinkedlist(struct node *p) {
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
}

int main() {
    // Initialize nodes
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // Allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // Assign value values
    one->value = 4;
    two->value = 5;
    three->value = 7;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // printing node-value
    head = one;
    printLinkedlist(head);
} */