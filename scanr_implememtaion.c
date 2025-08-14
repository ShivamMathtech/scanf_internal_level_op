#include <stdio.h>
#include <stdarg.h> // for va_list, va_start, va_arg, va_end
#include <ctype.h>  // for isspace()

int my_scanf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int assigned = 0; // number of successfully assigned variables
    int ch;

    while (*fmt) {
        if (isspace(*fmt)) { 
            // Skip whitespace in format
            while (isspace((ch = getchar())) && ch != EOF);
            ungetc(ch, stdin); // push back the non-space
            fmt++;
            continue;
        }

        if (*fmt != '%') {
            // Literal match
            ch = getchar();
            if (ch != *fmt) {
                ungetc(ch, stdin);
                break; // mismatch
            }
            fmt++;
            continue;
        }

        fmt++; // skip '%'

        if (*fmt == 'd') {
            int *iptr = va_arg(args, int*);
            if (scanf("%d", iptr) == 1) assigned++;
        }
        else if (*fmt == 'c') {
            char *cptr = va_arg(args, char*);
            *cptr = getchar();
            assigned++;
        }
        else if (*fmt == 's') {
            char *sptr = va_arg(args, char*);
            int idx = 0;
            while ((ch = getchar()) != EOF && !isspace(ch)) {
                sptr[idx++] = ch;
            }
            sptr[idx] = '\0';
            assigned++;
        }

        fmt++;
    }

    va_end(args);
    return assigned;
}

int main() {
    int num;
    char name[50];
    char grade;

    printf("Enter: <int> <string> <char>\n");
    my_scanf("%d %s %c", &num, name, &grade);

    printf("You entered:\n");
    printf("Number: %d\n", num);
    printf("Name: %s\n", name);
    printf("Grade: %c\n", grade);

    return 0;
}
