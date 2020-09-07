/*
 *
 * Exercise 1-23. Write a program to remove all comments from a c program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't nest.
 *
 * This program assumes that the user will enter a syntactically correct c program.
 *
 * Author: Kun Deng
 */

#include <stdio.h>

#define LINE_MAX_COUNT 1000 // The max amount of characters accepted for a line
#define PROGRAM_MAX_CHARACTER_COUNT 10000 // The max amount of characters allowed for the c program

// The two symbolic constants server to check if currently in a quote. Comments will not
// be removed if within quotes
#define IN_QUOTES 1
#define OUT_QUOTES 0

#define NO_COMMENT_STATE 0
#define SINGLE_COMMENT_STATE  1
#define MULTI_LINE_COMMENT_START_STATE 2
#define MULTI_LINE_COMMENT_END_STATE 3

char line[LINE_MAX_COUNT];
char c_program[PROGRAM_MAX_CHARACTER_COUNT];

int c_program_length = 0;

int get_line(void);
// Returns 1 if line contains comments, 2 if the line begins with a multi-line comment specifier,
// 3 if the trailing multi-line comment specifier is found
// and 0 if no comments found
int line_contains_comments(int line_length);

void copy_line(int line_length);


int main()
{
    printf("Enter a simple C program that contains comments.\n");
    printf("Comments will be removed and the end result will be the c program ");
    printf("without comments.\n");
    
    extern char line[];
    extern char c_program[];

    extern int c_program_length;

    int length = 0;
    int comment_state = NO_COMMENT_STATE;

    while (length = get_line())
    {
        int current_state = line_contains_comments(length);

        // printf("current state %d\n", current_state);
        // printf("line %s\n", line);
        
        if (current_state == SINGLE_COMMENT_STATE)
        {
            comment_state = current_state;
        }
        else if (current_state == MULTI_LINE_COMMENT_START_STATE)
        {
            comment_state = current_state;
        }
        else if (current_state == NO_COMMENT_STATE && 
                comment_state != MULTI_LINE_COMMENT_START_STATE)
        {
            comment_state = current_state;
        }

        if (comment_state == MULTI_LINE_COMMENT_START_STATE && 
                current_state == MULTI_LINE_COMMENT_END_STATE)
        {
            comment_state = current_state;
        }

        if (comment_state == NO_COMMENT_STATE)
        {
            copy_line(length);
        }
    }

    c_program[c_program_length] = '\0';

    printf("\n\nC program without comments\n\n%s\n", c_program);

    return 0;
}

int get_line(void)
{
    extern char line[];
    int c;
    int length = 0;

    for (; (c = getchar()) != EOF && c != '\n'; ++length)
    {
        line[length] = c;
    }

    line[length] = '\0';

    return length;
}

int line_contains_comments(int line_length)
{
    extern char line[];

    int result = NO_COMMENT_STATE; // Defaulting to no comments found
    int state = OUT_QUOTES;
    int quote_count = 0; // Resets the state if quote count is 2

    for (int i = 0; i != line_length; ++i)
    {
        int c = line[i];

        if (c == '"')
        {
            ++quote_count;

            if (quote_count == 2)
            {
                quote_count = 0;
                state = OUT_QUOTES;
            }
            else
            {
                state = IN_QUOTES;
            }
        }

        if (state == OUT_QUOTES && c == '/' && i > 0 && (line[i - 1] == '/'))
        {
            result = SINGLE_COMMENT_STATE; // Found comment
            // printf("found single-line comment\n");
        }
        else if (state == OUT_QUOTES && c == '*' && i > 0 && (line[i - 1] == '/'))
        {
            result = MULTI_LINE_COMMENT_START_STATE; // Found multi-line comment start
            // printf("found start of multi-line comment\n");
        }
        else if (state == OUT_QUOTES && c == '/' && i > 0 && (line[i - 1] == '*'))
        {
            result = MULTI_LINE_COMMENT_END_STATE; // Found multi-line comment end
            // printf("found end of multi-line comment\n");
        }
    }

    return result;
}


void copy_line(int line_length)
{
    extern char line[];
    extern char c_program[];

    extern int c_program_length;

    // printf("copying line\n");

    for (int i = 0; i != line_length; ++i)
    {
        c_program[c_program_length++] = line[i];
    }

    c_program[c_program_length++] = '\n';
}
