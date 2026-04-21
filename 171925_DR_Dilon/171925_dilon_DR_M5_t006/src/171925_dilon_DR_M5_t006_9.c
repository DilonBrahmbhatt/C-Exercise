/*
Discribtion:Rewrite the routines day_of_year and month_day with pointers instead of indexing.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/
#include <stdio.h>
#include <stdint.h>

static const uint8_t day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: month/day -> day of year */
int16_t day_of_year_pointer(int32_t year, uint8_t month, uint8_t day) {
    uint8_t is_leap_year;
    const uint8_t *ptr_month_days;
    int16_t total_day = day;

    is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    /* Error checking */
    if (month < 1 || month > 12) return -1;
    if (day < 1 || day > day_table[is_leap_year][month]) return -1;

    /* Point to the correct row in the table */
    ptr_month_days = day_table[is_leap_year];

    /* Accumulate days from previous months */
    for (uint8_t month_index = 1; month_index < month; month_index++) {
        total_day += *(ptr_month_days + month_index);
    }

    return total_day;
}

/* month_day: day of year -> month & day */
void month_day_pointer(int32_t year, uint16_t year_day, uint8_t *ptr_month, uint8_t *ptr_day) {
    uint8_t is_leap_year, month_index;
    const uint8_t *ptr_month_days;

    is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (year_day < 1 || (is_leap_year && year_day > 366) || (!is_leap_year && year_day > 365)) {
        *ptr_month = 0;
        *ptr_day = 0;
        return;
    }

    ptr_month_days = day_table[is_leap_year];
    month_index = 1;

    while (year_day > *(ptr_month_days + month_index)) {
        year_day -= *(ptr_month_days + month_index);
        month_index++;
    }

    *ptr_month = month_index;
    *ptr_day = (uint8_t)year_day;
}

void main_day_of_year_using_pointer() {
    int year, month, day, year_day, choice;
    uint8_t res_month, res_day;

    printf("1. Month/Day -> Day of Year\n2. Day of Year -> Month/Day\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Year Month Day: ");
        scanf("%d %d %d", &year, &month, &day);
        int16_t result = day_of_year_pointer(year, (uint8_t)month, (uint8_t)day);
        if (result == -1) printf("Error: Invalid Date\n");
        else printf("Day of Year: %d\n", result);
    } else if (choice == 2) {
        printf("Enter Year Day_of_Year: ");
        scanf("%d %d", &year, &year_day);
        month_day_pointer(year, (uint16_t)year_day, &res_month, &res_day);
        if (res_month == 0) printf("Error: Invalid Day\n");
        else printf("Month: %d, Day: %d\n", res_month, res_day);
    }
    return 0;
}
