#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define EmptyTos -1
#define MinStackSize 5
#define MaxStackSize 50

struct  StackRecord {
    int capacity;
    int topOfStack;
    int* array;

}; typedef struct StackRecord* Stack;

void MakeEmptyStack(Stack stack)
{
    stack->topOfStack = EmptyTos;
}

Stack CreateStack(int capacity)
{

    Stack stack = (Stack)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    MakeEmptyStack(stack);
    return stack;

}

int isEmpty(Stack stack)
{
    return stack->topOfStack == -1;
}

int isFull(Stack stack)
{
    return stack->topOfStack == stack->capacity - 1;
}


void push(Stack stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->topOfStack] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(Stack stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->topOfStack--];
}

int peek(Stack stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->topOfStack];
}

int main ()
{
    Stack stack = CreateStack(MaxStackSize);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", peek(stack));

    return 0;
}

