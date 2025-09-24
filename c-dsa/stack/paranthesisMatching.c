#include <stdio.h>
#include <stdlib.h>
// Step 1: Define Stack structure
struct Stack
{
    int top;
    char items[100]; // You can change size
};
void push(struct Stack *s, char c)
{
    if (s->top == 99)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = c;
}

char pop(struct Stack *s)
{
    if (s->top == -1)
    {
        return '\0';
    }
    return s->items[s->top--];
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void perenthesisMatch(char exp[])
{

    // Step 2: Declare and initialize stack
    struct Stack s;
    s.top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(&s))
            {
                printf("Unmatched closing parenthesis at position %d\n", i);
                return;
            }
            pop(&s);
        }
    }
    if (isEmpty(&s))
    {
        printf("Parentheses are matched.\n");
    }
    else
    {
        printf("Unmatched opening parentheses remain.\n");
    }
}

int main()
{
    char exp[] = "3*2+(5-4)";

    perenthesisMatch(exp);
    return 0;
}