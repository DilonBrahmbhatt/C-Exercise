/*
Description: Revise minprintf to handle more of the other facilities of printf.
Author: Dilon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "header.h"

/*
Description:  minprintf: extended version this handles more feature of printf using variable arguments.
Author: Dilon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/
void minprintf(char *fmt, ...) {
    va_list ap;
    char *p;

    va_start(ap, fmt);

    for (p = fmt; *p; p++) {

        if (*p != '%') {
            putchar(*p);
            continue;
        }

        p++;

        switch (*p) {

            case 'd': {
                int ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            }

            case 'u': {
                unsigned int uval = va_arg(ap, unsigned int);
                printf("%u", uval);
                break;
            }

            case 'f': {
                double dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            }

            case 's': {
                char *sval = va_arg(ap, char *);
                printf("%s", sval);
                break;
            }

            case 'p': {
                void *pval = va_arg(ap, void *);
                printf("%p", pval);
                break;
            }

            case 'c': {
                int cval = va_arg(ap, int);
                printf("%c", cval);
                break;
            }

            case 'l': {
                p++;

                if (*p == 'd') {
                    long lval = va_arg(ap, long);
                    printf("%ld", lval);
                }
                else if (*p == 'u') {
                    unsigned long ulval = va_arg(ap, unsigned long);
                    printf("%lu", ulval);
                }
                else if (*p == 'f') {
                    double dval = va_arg(ap, double);
                    printf("%lf", dval);
                }
                else {
                    putchar('%');
                    putchar('l');
                    putchar(*p);
                }
                break;
            }

            case '%': {
                putchar('%');
                break;
            }

            default:
                putchar('%');
                putchar(*p);
                break;
        }
    }

    va_end(ap);
}

void MinPrintfModified() {
int8_t a = 10;
int8_t *ptr = &a;

    printf("Testing minprintf:\n");

    minprintf("Integer (%%d): %d\n", 10);
    minprintf("Unsigned Integer (%%u): %u\n", 20);
    minprintf("Float (%%f): %f\n", 3.14);
    minprintf("String (%%s): %s\n", "Hello");
    minprintf("Pointer (%%p): %p\n", ptr);
    minprintf("Character (%%c): %c\n", 'A');
    minprintf("Long Integer (%%ld): %ld\n", 1234567890L);
    minprintf("Unsigned Long Integer (%%lu): %lu\n", 9876543210UL);
    minprintf("Double (%%lf): %lf\n", 2.71828);
}
