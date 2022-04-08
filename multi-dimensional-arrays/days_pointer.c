#include <stdio.h>
#include <assert.h>

static char leapyear[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char nonleapyear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[13] = {nonleapyear, leapyear};

int day_of_year(int year, int month, int day)
{
    assert(month < 13 && month > 0);
    int i, leap;
    char *original;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    assert(day <= daytab[leap][month]);

    original = daytab[leap];

    for (i = 1; i < month; i++)
        day += *++daytab[leap];

    daytab[leap] = original;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    assert(yearday > 0);

    int i, leap;
    char *original;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    assert(leap == 0 ? yearday < 366 : yearday < 367);

    original = daytab[leap];

    for (i = 1, ++daytab[leap]; yearday > *daytab[leap]; i++, daytab[leap]++)
        yearday -= *daytab[leap];

    *pmonth = i;
    *pday = yearday;
    daytab[leap] = original;
}

int main()
{
    int dayyear, modmonth, modday, month = 12, day = 1;

    printf("month: %d day: %d\n", month, day);
    dayyear = day_of_year(2022, 12, 1);
    printf("day of the year: %d\n", dayyear);

    month_day(2022, dayyear, &modmonth, &modday);
    printf("month: %d day: %d\n", modmonth, modday);

    return 0;
}
