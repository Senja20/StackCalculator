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
void MultiplicationOperation(Stack);
void DivisionOperation(Stack);

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
        else if(userInput > 47 && userInput < 58) // if a number
        {
            enterValue(stack,  userInput);
        }
        else if(userInput == 43) // addition
        {
            AdditionOperation(stack);
        }
        else if (userInput == 45) // subtraction
        {
            SubtractionOperation(stack);
        }
        else if(userInput == 42 || userInput == 120) // multiplication
        {
            MultiplicationOperation(stack);
        }
        else if (userInput == 47 || userInput == 58)
        {
            DivisionOperation(stack);
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
    int IntValue = value - 48; // from char to int

    if(!isFull(stack))
        push(stack, IntValue);
    else
        printf("No more space for more values!");
}

void AdditionOperation(Stack stack)
{
    int firstOperand = 0;
    int secondOperand = 0;

    if(peek(stack) != EmptyTos) // if stack is not empty
    {
        firstOperand = pop(stack); // remove first value and store it in a variable

        if(peek(stack) != EmptyTos)  // if stack is still not empty
        {
            secondOperand = pop(stack); // store and remove the second value
        }
        else // if there are no second operand first value will be returned and user will get error message
        {
            push(stack, firstOperand);
            printf("Not enough values to perform addition on\n");
            firstOperand = 0; // null out value, just in case
        }
    }
    else // if stack is empty to begin with, user will be the message
    {
        printf("No values to perform addition on\n");
        printf("looks like no values have been entered\n");
    }

    if(firstOperand && secondOperand) // if both values are not zero, operations will be performed
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
            firstOperand = 0; // null out value, just in case
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

void MultiplicationOperation(Stack stack)
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
            firstOperand = 0; // null out value, just in case
        }
    }
    else
    {
        printf("No values to perform subtraction on\n");
    }

    if(firstOperand && secondOperand)
    {
        int ProductOfOperands = firstOperand * secondOperand;
        printf("\n");
        push(stack, ProductOfOperands);
    }
}

void DivisionOperation(Stack stack)
{
    int numerator = 0;
    int denominator = 0;

    if(peek(stack) != EmptyTos)
    {
        denominator = pop(stack);

        if(peek(stack) != EmptyTos || peek(stack) != 0)
        {
            numerator = pop(stack);
        }
        else
        {
            printf("hello");
            push(stack, numerator);
            printf("Not sufficient values to subtract\n");
            numerator = 0; // null out value, just in case
        }
    }
    else
    {
        printf("No values to perform subtraction on\n");
    }

    if(numerator && denominator)
    {
        if(numerator%denominator == 0)
        {
            int QuotientOfOperand = numerator / denominator;
            printf("\n");
            push(stack, QuotientOfOperand);
        }
        else if(numerator%denominator != 0)
        {
            int mod;
            int gcd;

            // Increasing the number till the rest of division both numerator and denominator
            // The for-loop will go on until mod in larger og equal to both numerator & denominator

            for(mod=1; mod <= numerator && mod <= denominator; ++mod)
            {
                // Checks if mod is factor of both integers
                if(numerator % mod == 0 && denominator % mod == 0)
                    gcd = mod; // The number that fills the requirement becomes gcd
            }

            printf("%i/%i\n", numerator/gcd, denominator/gcd);
            printf("This is not an integer and therefore cannot be pushed to the stack\n");

        }

    }

}