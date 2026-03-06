/*
discribtion:Extend atof to handle scientific notation
Author: Dilon Brahmbhatt
Created: 02 march, 2026
Modified: 02 march, 2026
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void atof_1(char num[])
{
    double result = 0.0;
    double fraction = 0.1;
    int index = 0;
    bool sign = true;
    bool point = false;
    int8_t exp_sign = 1;
    int8_t exponent = 0;

    if (num[index] == '-') {
        sign = false;
        index++;
    }
    else if (num[index] == '+') {
        index++;
    }

    while (num[index] != '\0') {

        if (num[index] >= '0' && num[index] <= '9') {
            if (!point) {
                result = result * 10 + (num[index] - '0');
            } else {
                result = result + (num[index] - '0') * fraction;
                fraction /= 10;
            }
        }

        else if (num[index] == '.') {
            point = true;
        }

        else if (num[index] == 'e' || num[index] == 'E') {
            index++;

            if (num[index] == '-') {
                exp_sign = -1;
                index++;
            }
            else if (num[index] == '+') {
                index++;
            }

            while (num[index] >= '0' && num[index] <= '9') {
                exponent = exponent * 10 + (num[index] - '0');
                index++;
            }
            break;
        }

        index++;
    }

    while (exponent > 0) {
        if (exp_sign == 1)
            result *= 10;
        else
            result /= 10;

        exponent--;
    }

    if (!sign)
        result = -result;

printf("Converted value = %lf\n", result);
}

void atof_main()
{
    char str[50];

    printf("Enter number: ");
    scanf("%49s", str);
    atof_1(str);
}
