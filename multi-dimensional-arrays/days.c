#include <stdio.h>
#include <assert.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
    assert(month < 13 && month > 0);
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    assert(day <= daytab[leap][month]);

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    assert(yearday > 0);

    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    assert(leap == 0 ? yearday < 366 : yearday < 367);

    for (i = 1; yearday < daytab[leap][i]; i++)
        yearday += daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int day, modmonth, modday;

    day = day_of_year(2022, 12, 31);
    printf("%d\n", day);

    month_day(2022, day, &modmonth, &modday);
    printf("month: %d\nday:%d\n", modmonth, modday);

    return 0;
}
