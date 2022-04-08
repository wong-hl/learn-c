#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find patter\n");
    else
    {
        while (getLine(line, MAXLINE) > 1)
        {
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int getLine(char s[], int lim)
{
    int c, i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}