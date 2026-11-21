
#include <stdio.h>

char grade_if(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';
    else if (marks >= 90)
        return 'S';
    else if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else
        return 'F';
}

char grade_switch(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';

    switch (marks / 10)
    {
        case 10:
        case 9:
            return 'S';
        case 8:
            return 'A';
        case 7:
            return 'B';
        case 6:
            return 'C';
        case 5:
            return 'D';
        default:
            return 'F';
    }
}

int main(void)
{
    int tests[] = {100, 90, 89, 0, -1, 101};
    int i;

    printf("Marks  If-Else  Switch\n");

    for (i = 0; i < 6; i++)
    {
        printf("%5d     %c       %c\n",
               tests[i],
               grade_if(tests[i]),
               grade_switch(tests[i]));
    }

    return 0;
}

