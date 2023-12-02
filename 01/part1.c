#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("input.txt", "r");

    // Get the longest possible string starting and ending with a digit
    regex_t regex;
    regcomp(&regex, "[0-9].*[0-9]|[0-9]", REG_EXTENDED);
    regmatch_t match;

    int num;
    char digits[3];
    digits[2] = '\0';

    char line[128];
    int sum = 0;
    while (fgets(line, sizeof(line), fp))
    {
        regexec(&regex, line, 1, &match, 0);

        // Concatenate
        digits[0] = line[match.rm_so];
        digits[1] = line[match.rm_eo - 1];

        // Convert to int and add to total
        num = atoi(digits);
        sum += num;
    }
    fclose(fp);
    regfree(&regex);

    printf("Sum: %d\n", sum);

    return 0;
}
