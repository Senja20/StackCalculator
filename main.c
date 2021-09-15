#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //printf("%d pushed to stack\n", item);
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


void enterValue(Stack , int );
void AdditionOperation(Stack);
void SubtractionOperation(Stack);
void MultiplicationOperation(Stack);
void DivisionOperation(Stack);

int isNumber(char []);
int convertToNumber(char []);
int isOperator(char []);

int main ()
{
    Stack stack = CreateStack(MaxStackSize);
    char userInput[6];

    while (1)
    {
        printf("Enter:");
        gets(userInput);

        if(isNumber(userInput)) // if a number
        {
            int tempNumber = convertToNumber(userInput);
            enterValue(stack,  tempNumber);
        }
        else if(isOperator(userInput) == 43) // addition
        {
            AdditionOperation(stack);
        }
        else if (isOperator(userInput) == 45) // subtraction
        {
            SubtractionOperation(stack);
        }
        else if(isOperator(userInput) == 42) // multiplication
        {
            MultiplicationOperation(stack);
        }
        else if (isOperator(userInput) == 47) // Division
        {
            DivisionOperation(stack);
        }
        else
        {
            printf("\nInvalid input\n");
            break;
        }

    }
    return 0;
}

int isOperator(char str[])
{
    int operator = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if(str[i] == 43) // addition
        {
            operator = 43;
        }
        else if (str[i] == 45) // subtraction
        {
            operator = 45;
        }
        else if(str[i] == 42 || str[i] == 120) // multiplication
        {
            operator = 42;
        }
        else if (str[i] == 47 || str[i] == 58) // Division
        {
            operator = 47;
        }
    }

    return operator;

}

int isNumber(char str[])
{
    int count = 0, isNumber = 0;

    for(int i=0; str[i] >= 48 && str[i] <= 57 ;i++)
    {
        count++;
    }

    if (count == strlen(str))
    {
        isNumber = 1;
        return isNumber;
    }
    else
    {
        return isNumber;
    }
}

int convertToNumber(char str[])
{
    char *text;
    long value;
    int intValue;

    value = strtol(str, &text, 10);
    intValue = value;
    return intValue;
}

void enterValue(Stack stack, int value)
{

    if(!isFull(stack))
        push(stack, value);
    else
        printf("No more space for more values!\n");
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
        printf("Result: %i\n", sumOfOperands);
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
        int DifferenceOfOperands = secondOperand - firstOperand;
        printf("\n");
        push(stack, DifferenceOfOperands);
        printf("Result: %i\n", DifferenceOfOperands);
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
            printf("Not enough values to multiply\n");
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
        printf("Result: %i\n", ProductOfOperands);
    }
}

void DivisionOperation(Stack stack)
{
    int numerator = 0;
    int denominator = 0;

    if (peek(stack) == 0)
    {
        printf("Cannot divide by zero\n");
        pop(stack);
        printf("Zero is removed from the stack\n");
    }
    else if(peek(stack) != EmptyTos)
    {
        denominator = pop(stack);
        
        if(peek(stack) != EmptyTos)
        {
            numerator = pop(stack);
        }
        else
        {
            push(stack, numerator);
            printf("Not sufficient values to divide\n");
            numerator = 0; // null out value, just in case
        }
    }

    else
    {
        printf("No values to perform subtraction on\n");
    }

    if(numerator != 0 && denominator != 0)
    {
        if(numerator%denominator == 0)
        {
            int QuotientOfOperand = numerator / denominator;
            printf("\n");
            push(stack, QuotientOfOperand);
            printf("Result: %i\n", QuotientOfOperand);
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

            push(stack, numerator);
            push(stack, denominator);

        }
    }
}