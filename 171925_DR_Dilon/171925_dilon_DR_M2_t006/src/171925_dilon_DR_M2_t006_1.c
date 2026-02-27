#include <stdio.h>
#include <limits.h>
#include <float.h>

void size_of_data_type() {

    // CHARACTER TYPES
    printf("Signed Char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned Char: 0 to %u\n", UCHAR_MAX);

    // SHORT TYPES
    printf("Signed Short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned Short: 0 to %u\n", USHRT_MAX);

    // INT TYPES
    printf("Signed Int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned Int:  0 to %u\n", UINT_MAX);

    // LONG TYPES
    printf("Signed Long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned Long: 0 to %lu\n", ULONG_MAX);

    // FLOATING POINT TYPES (from float.h)
    printf("Float:         %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Double:        %e to %e\n", DBL_MIN, DBL_MAX);

}
