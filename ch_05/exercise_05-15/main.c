/*
 *
 * Exercise 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.
 *
 * Author: Kun Deng
 */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5
char *lineptr[MAXLINES];


void qsort(void *v[], int left, int right, int (*comp)(void *, void *));
void swap(void *[], int i, int j);
int numcmp(char *s1, char *s2);
int strcmp_ignore(char *s1, char *s2);

int readlines(char *lptr[], int nlines);
void writelines(char *lptr[], int nlines);


void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
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
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
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

// TODO: Implement function
int strcmp_ignore(char *s1, char *s2) {
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
    lineptr[0] = "ffffc";
    lineptr[1] = "zzzz";
    lineptr[2] = "aaaa";
    lineptr[3] = "bbsss";
    lineptr[4] = "osp";

    return 5;
}


int main(int argc, char **argv)
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    else if (argc > 1 && strcmp(argv[1], "-f") == 0)
        numeric = 3;

    if ((nlines = testlines(lineptr)) >= 0 ) {
        printf("Currently\n");
        writelines(lineptr, nlines);

        if (numeric != 3) {
            void (*my_func) = (numeric ? numcmp : strcmp);

            qsort((void **) lineptr, 0, nlines-1, 
                (int (*)(void *, void *))my_func);
        } else {
            void (*my_func) = strcmp_ignore;
            qsort((void **) lineptr, 0, nlines-1, my_func);
                
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
