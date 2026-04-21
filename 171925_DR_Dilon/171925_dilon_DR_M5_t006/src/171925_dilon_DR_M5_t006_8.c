/*
discribtion:There is no error checking in day_of_year or month_day. Remedy this defect.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* Using uint16_t everywhere for consistency */

static const uint16_t day_table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* Month/Day → Day of Year */
int16_t day_of_year(int32_t year, uint16_t month, uint16_t day) {
    uint16_t month_index;
    uint8_t is_leap_year;

    is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month < 1 || month > 12) return -1;
    if (day < 1 || day > day_table[is_leap_year][month]) return -1;

    for (month_index = 1; month_index < month; month_index++) {
        day += day_table[is_leap_year][month_index];
    }

    return (int16_t)day;
}

/* Day of Year → Month/Day */
void month_day(int32_t year, uint16_t year_day,
               uint16_t *ptr_month, uint16_t *ptr_day) {

    uint16_t month_index;
    uint8_t is_leap_year;

    is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (year_day < 1 || (is_leap_year && year_day > 366) ||
        (!is_leap_year && year_day > 365)) {

        *ptr_month = 0;
        *ptr_day = 0;
        return;
    }

    for (month_index = 1;
         year_day > day_table[is_leap_year][month_index];
         month_index++) {

        year_day -= day_table[is_leap_year][month_index];
    }

    *ptr_month = month_index;
    *ptr_day = year_day;
}

void main_day_of_year() {
    uint16_t choice;
    int32_t input_year;

    uint16_t input_month, result_month;
    uint16_t input_day, result_day;

    uint16_t input_year_day;
    int16_t result_year_day;

    printf("Date Utility (uint16_t version)\n");
    printf("1. Month/Day -> Day of Year\n");
    printf("2. Day of Year -> Month/Day\n");
    printf("Enter choice: ");
    scanf("%" SCNu16, &choice);

    if (choice == 1) {
        printf("Enter Year, Month, Day (e.g., 2024 12 31): ");
        scanf("%" SCNd32 " %" SCNu16 " %" SCNu16,
              &input_year, &input_month, &input_day);

        result_year_day = day_of_year(input_year, input_month, input_day);

        if (result_year_day == -1) {
            printf("Error: Invalid date.\n");
        } else {
            printf("Day %" PRId16 " of the year.\n", result_year_day);
        }

    } else if (choice == 2) {
        printf("Enter Year and Day of Year (e.g., 2024 366): ");
        scanf("%" SCNd32 " %" SCNu16,
              &input_year, &input_year_day);

        month_day(input_year, input_year_day,
                  &result_month, &result_day);

        if (result_month == 0) {
            printf("Error: Invalid day of year.\n");
        } else {
            printf("Month %" PRIu16 ", Day %" PRIu16 "\n",
                   result_month, result_day);
        }
    } else {
        printf("Invalid selection.\n");
    }
}
