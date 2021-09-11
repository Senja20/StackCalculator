#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define EmptyTos -1
#define MaxStackSize 50

struct  StackRecord
{
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
    return stack->topOfStack == EmptyTos;
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
        return EmptyTos;
    return stack->array[stack->topOfStack--];
}

int peek(Stack stack)
{
    if (isEmpty(stack))
        return EmptyTos;
    return stack->array[stack->topOfStack];
}

void enterValue(Stack , char );
void AdditionOperation(Stack);
void SubtractionOperation(Stack);

int main ()
{
    Stack stack = CreateStack(MaxStackSize);
    char userInput;

    while (1)
    {
        printf("Enter:");
        scanf("%c", &userInput);
        getchar();

        if(userInput == 'q')
        {
            break;
        }
        else if(userInput > 47 && userInput < 58)
        {
            enterValue(stack,  userInput);
        }
        else if(userInput == 43)
        {
            AdditionOperation(stack);
        }
        else if (userInput == 45)
        {
            SubtractionOperation(stack);
        }
        else
        {
            printf("\nInvalid input\n");
        }

    }
    return 0;
}

void enterValue(Stack stack, char value)
{
    int IntValue = value - 48;

    if(!isFull(stack))
        push(stack, IntValue);
    else
        printf("No more space for more values!");
}

void AdditionOperation(Stack stack)
{
    int firstOperand = 0;
    int secondOperand = 0;

    if(peek(stack) != EmptyTos)
    {
        firstOperand = pop(stack);

        if(peek(stack) != EmptyTos)
        {
            secondOperand = pop(stack);
        }
        else
        {
            push(stack, firstOperand);
            printf("Not enough values to perform addition on\n");
        }
    }
    else
    {
        printf("No values to perform addition on\n");
    }

    if(firstOperand && secondOperand)
    {
        int sumOfOperands = firstOperand + secondOperand;
        printf("\n");
        push(stack, sumOfOperands);
    }
}

void SubtractionOperation(Stack stack)
{
    int firstOperand = 0;
    int secondOperand = 0;

    if(peek(stack) != EmptyTos)
    {
        firstOperand = pop(stack);

        if(peek(stack) != EmptyTos)
        {
            secondOperand = pop(stack);

        } else
        {
            push(stack, firstOperand);
            printf("Not enough values to subtract\n");
        }
    }
    else
    {
        printf("No values to perform subtraction on\n");
    }

    if(firstOperand && secondOperand)
    {
        int DifferenceOfOperands = firstOperand - secondOperand;
        printf("\n");
        push(stack, DifferenceOfOperands);
    }
}