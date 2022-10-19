/*
 *
 * Exercise 6-1. Our version of getword does not properly handle underscores,
 * string constants, comments, or preprocessor control lines. Write a
 * better version.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

#define BUFFSIZE 5
#define MAXWORD 5

#define NKEYS (sizeof keytab / sizeof(struct key))

char buf[BUFFSIZE];
int bufp = 0;

struct key {
    char *word;
    int count;
};

/*
struct key {
    char *word;
    int count;
} keytab[NKEYS];
*/

struct key keytab[] = {
    "auto", 0,
    "break", 0,
};


/* getword: get next word or character from input */
int getword(char *word, int lim);

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n);

/* get a (possibly pushed back) character */
int getch(void);

/* push character back on input */
void ungetch(int c);


int getword(char *word, int lim) {
    int c;
    /* int c, getch(void); */
    /* void ungetch(int); */
    char *w = word;

    while (isspace(c = getch()) || c != EOF);

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return 0;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];
}

struct key *binsearch(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0 )
            high = mid;
        else if (cond > 0 )
            low = mid + 1;
        else
            return mid;
    }

    return NULL;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) {
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


int main()
{
    int n;
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;

    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);


    return 0;
}
