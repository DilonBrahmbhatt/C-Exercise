/*
Description: Write a private version of scanf analogous to minprintf from the previous section.
Author: Dilon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/
#include <stdio.h>
#include <stdarg.h>
#include "header.h"
/*
Description: minscanf: minimal scanf using variable arguments
Author: Dilon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/
void minscanf(char *fmt, ...) {
    va_list ap;
    char *p;
 
    va_start(ap, fmt);
 
    for (p = fmt; *p; p++) {
 
        if (*p != '%')
            continue;
 
        p++;
 
        switch (*p) {
 
            case 'd': {
                int *ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            }
 
            case 'f': {
                float *fval = va_arg(ap, float *);
                scanf("%f", fval);
                break;
            }
 
            case 's': {
                char *sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            }
 
            case 'c': {
                char *cval = va_arg(ap, char *);
                scanf(" %c", cval);
                break;
            }
            case 'u': {
                unsigned int *uval = va_arg(ap, unsigned int *);
                scanf("%u", uval);
                break;
            }
 
            case 'p': {
                void **pval = va_arg(ap, void **);
                scanf("%p", pval);
                break;
            }
             case 'l': {
                p++;
 
                if (*p == 'd') {
                    long *lval = va_arg(ap, long *);
                    scanf("%ld", lval);
                }
                else if (*p == 'u') {
                    unsigned long *ulval = va_arg(ap, unsigned long *);
                    scanf("%lu", ulval);
                }
                else if (*p == 'f') {
                    double *dval = va_arg(ap, double *);
                    scanf("%lf", dval);
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

void MinScanfModified() {
    int i;
    float f;
    char s[100];
    char c;
    unsigned int u;
    long ld;
    unsigned long lu;
    double d;
    void *ptr;

    printf("Enter an integer: ");
    minscanf("%d", &i);

    printf("Enter a float: ");
    minscanf("%f", &f);

    printf("Enter a string: ");
    minscanf("%s", s);

    printf("Enter a Character: ");
    minscanf("%c", &c);

    printf("Enter an unsigned integer: ");
    minscanf("%u", &u);

    printf("Enter a long integer: ");
    minscanf("%ld", &ld);

    printf("Enter an unsigned long integer: ");
    minscanf("%lu", &lu);

    printf("Enter a double: ");
    minscanf("%lf", &d);

    printf("Enter a pointer value (hex like 0x1234): ");
    minscanf("%p", &ptr);

   minprintf("\nYou entered:\n");
    minprintf("Integer: %d\n", i);
    minprintf("Float: %f\n", f);
    minprintf("String: %s\n", s);
    minprintf("Character: '%c'\n", c);
    minprintf("Unsigned Integer: %u\n", u);
    minprintf("Long Integer: %ld\n", ld);
    minprintf("Unsigned Long Integer: %lu\n", lu);
    minprintf("Double: %lf\n", d);
    minprintf("Pointer: %p\n", ptr);
}
