/*
How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 10 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

void runWordCountTest()
{
int16_t c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {

        ++nc;

        if (c == '\n') {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl-1, nw, nc-1);
}
