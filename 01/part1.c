#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("input.txt", "r");

    if (fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }


    // Compile regex to get the longest possible string that starts and ends with a digit
    regex_t regex;
    regcomp(&regex, "[0-9].*[0-9]|[0-9]", REG_EXTENDED);
    regmatch_t match;

    int num;
    char digits[3];
    digits[2] = '\0';

    char line[100];
    int sum = 0;
    while (fgets(line, sizeof(line), fp)) {

        // For sake of simplicity, assume it won't fail to match
        regexec(&regex, line, 1, &match, 0);

        // Concatenate the first and last characters of the match
        digits[0] = line[match.rm_so];
        digits[1] = line[match.rm_eo - 1];

        // Convert the string to an integer and add it to the running sum
        num = atoi(digits);
        sum += num;

        printf("%s <- ", digits);
        printf("%.*s <- ", (int)(match.rm_eo - match.rm_so), &line[match.rm_so]);
        printf("%s", line);
    }

    // Clean up
    fclose(fp);
    regfree(&regex);

    printf("\n\n");
    printf("Sum: %d\n", sum);

    return 0;
}