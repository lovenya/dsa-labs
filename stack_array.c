#include "element.h"
#include "stack.h"
#include <stdlib.h>
#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};
Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL)
        s->top = -1;
    return s;
}
bool push(Stack *s, Element e)
{
    if (s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

Element *top(Stack *s)
{
    return isEmpty(s) ? NULL : &(s->data[s->top]);

    // This is incorrect. The expression s + s->top adds the top index to the Stack pointer, which will not return the correct address of the top element in the data array.
}

bool isEmpty(Stack *s)
{
    return s->top == -1 ? true : false;
}

bool pop(Stack *s)
{
    if (isEmpty(s))
    {
        return false;
    }

    else
    {
        // free(top(s));  You should not call free(top(s)). The data array in the Stack is statically allocated, and there’s no need to free individual elements. The pop function should just decrement the top index to remove the top element.
        s->top--;
        return true;
    }
}

void freeStack(Stack *s)
{
    free(s);
    // Since the data array is statically allocated inside the Stack, you only need to free the Stack structure itself, not individual elements.
}