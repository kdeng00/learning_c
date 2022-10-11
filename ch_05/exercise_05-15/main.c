/*
 *
 * Exercise 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.
 *
 * Author: Kun Deng
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPARE_NUMBERS 0
#define COMPARE_CHARACTERS 1
#define COMPARE_CHARACTERS_IGNORE_CASE 3

#define MAXLINES 5
char *lineptr[MAXLINES];


void qsort_simple(void *v[], int left, int right, int (*comp)(void *, void *));
void swap(void *[], int i, int j);
int numcmp(char *s1, char *s2);
int strcmp_ignore(char *s1, char *s2);

int readlines(char *lptr[], int nlines);
void writelines(char *lptr[], int nlines);


void qsort_simple(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {        
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort_simple(v, left, last-1, comp);
    qsort_simple(v, last+1, right, comp);
}

void swap(void *v[], int i, int j) {
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmp_ignore(char *s1, char *s2) {
    int s1_size, s2_size;

    s1_size = strlen(s1);
    s2_size = strlen(s2);

    for (int i = 0; i < s1_size; i++) {
        int a, b;

        a = s1[i];

        for (int j = 0; j < s2_size; j++) {
            b = s2[j];

            if (a == b)
                continue;
            else if ((a > b && a-32 == b) || (a < b && b-32 == a))D {
                continue;

            if (a < b)
                return -1;
            else if (a > b)
                return 1;
        }
    }

    return 0;
}

int readlines(char *lptr[], int nlines) {
    int i = 0;

    printf("Enter some lines\n");

    int max = 25;

    for (; i < nlines; i++) {
        char line[max];
        char c = getchar();
        int ii = 0;

        while (c != EOF) {
            line[ii++] = c;
            c = getchar();
        }

        lptr[i] = line;
    }

    return i;
}

void writelines(char *lptr[], int nlines)
{
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lptr[i]);
    }
}

int testlines(char *lineptr[]) {
    lineptr[0] = "aaaa";
    lineptr[1] = "zzzz";
    lineptr[2] = "AAAA";
    lineptr[3] = "bbsss";
    lineptr[4] = "osp";

    return 5;
}


int main(int argc, char **argv)
{
    int nlines;
    int numeric = COMPARE_NUMBERS;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = COMPARE_CHARACTERS;
    else if (argc > 1 && strcmp(argv[1], "-f") == 0)
        numeric = COMPARE_CHARACTERS_IGNORE_CASE;

    if ((nlines = testlines(lineptr)) >= 0 ) {
        printf("Currently\n");
        writelines(lineptr, nlines);

        if (numeric != COMPARE_CHARACTERS_IGNORE_CASE) {
            void (*my_func) = (numeric == COMPARE_NUMBERS ? numcmp : strcmp);

            qsort_simple((void **) lineptr, 0, nlines-1, 
                (int (*)(void *, void *))my_func);
        } else if (numeric == COMPARE_CHARACTERS_IGNORE_CASE) {
            void (*my_func) = strcmp_ignore;

            qsort_simple((void **) lineptr, 0, nlines-1, 
                (int (*)(void *, void *))my_func);
        } else {
            void (*my_func) = strcmp_ignore;
            qsort_simple((void **) lineptr, 0, nlines-1, my_func);
        }

        printf("\nAfter\n");
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Input too big to sort\n");
        return 1;
    }

    return 0;
}
