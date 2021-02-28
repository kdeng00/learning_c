/*
 *
 * Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat
 * return as its function value?
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define BUFSIZE 100
#define SIZE 1024

int getch(void);
void ungetch(int);

int getfloat(float *ptr);


int main(void)
{
    int n;
    float array[SIZE];

    for(n=0; n<SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for(; n >= 0; n--)
    {
        printf("%f ",array[n]);
    }

    printf("\n");

    return 0;
}

int getfloat(float *ptr)
{
    int c,sign;
    float power;

    while(isspace(c = getch()))
        ;

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1: 1;

    if(c == '+' || c == '-')
    {
        c = getch();
    }

    for(*ptr = 0.0; isdigit(c); c = getch())
    {
        *ptr = 10.0 * (*ptr) + (c - '0');
    }

    if(c == '.')
    {
        c = getch();
    }

    for(power=1.0; isdigit(c); c = getch())
    {
        *ptr = 10.0 * (*ptr) + (c - '0');   /* fractional part */
        power *= 10.0;
    }

    *ptr  *= sign / power;

    if(c != EOF)
    {
        ungetch(c);
    }

    return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
