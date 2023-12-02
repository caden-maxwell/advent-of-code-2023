#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertFirstCharToDigit(char* match, int matchLen);
void convertLastCharToDigit(char* match, int matchLen);

int main()
{
    FILE* fp = fopen("input.txt", "r");

    if (fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    // Compile regex to get the longest possible string that starts and ends with a digit or a word that spells a digit
    regex_t regex;
    char* pattern = "([0-9]|one|two|three|four|five|six|seven|eight|nine).*"
        "([0-9]|one|two|three|four|five|six|seven|eight|nine)|"
        "[0-9]|one|two|three|four|five|six|seven|eight|nine";
    regcomp(&regex, pattern, REG_EXTENDED);
    regmatch_t match;

    int num;
    char digits[3];
    digits[2] = '\0';

    char line[128];
    int sum = 0;
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);

        // For sake of simplicity, assume it won't fail to match
        regexec(&regex, line, 1, &match, 0);
        int matchLen = match.rm_eo - match.rm_so;

        // Print the original string that was matched
        printf("\tMatched: %.*s\n", matchLen, &line[match.rm_so]);

        // If first char is alpha, convert it to a digit
        if (isalpha(line[match.rm_so]))
            convertFirstCharToDigit(&line[match.rm_so], matchLen);

        // If last char is alpha, convert it to a digit
        if (isalpha(line[match.rm_eo - 1]))
            convertLastCharToDigit(&line[match.rm_so], matchLen);

        printf("\tAfter Conversion: %.*s\n", matchLen, &line[match.rm_so]);

        digits[0] = line[match.rm_so];
        digits[1] = line[match.rm_eo - 1];

        // Convert the string to an integer and add it to the running sum
        num = atoi(digits);
        sum += num;
        printf("\tAdded: %d\n\n", num);
    }

    // Clean up
    fclose(fp);
    regfree(&regex);

    printf("Sum: %d\n", sum);

    return 0;
}

/**
 * Convert the first character of a match to a digit based on the word it spells
*/
void convertFirstCharToDigit(char* match, int matchLen)
{
    char first2[3];
    first2[0] = match[0];
    first2[1] = match[1];
    first2[2] = '\0';
    printf("\tFirst: %s -> ", first2);

    if (strcmp(first2, "on") == 0)
        match[0] = '1';
    else if (strcmp(first2, "tw") == 0)
        match[0] = '2';
    else if (strcmp(first2, "th") == 0)
        match[0] = '3';
    else if (strcmp(first2, "fo") == 0)
        match[0] = '4';
    else if (strcmp(first2, "fi") == 0)
        match[0] = '5';
    else if (strcmp(first2, "si") == 0)
        match[0] = '6';
    else if (strcmp(first2, "se") == 0)
        match[0] = '7';
    else if (strcmp(first2, "ei") == 0)
        match[0] = '8';
    else if (strcmp(first2, "ni") == 0)
        match[0] = '9';

    printf("%c\n", match[0]);
}

/**
 * Convert the last character of a match to a digit based on the word it spells
*/
void convertLastCharToDigit(char* match, int matchLen)
{
    char last3[4];
    last3[0] = match[matchLen - 3];
    last3[1] = match[matchLen - 2];
    last3[2] = match[matchLen - 1];
    last3[3] = '\0';
    printf("\tLast: %s -> ", last3);

    if (strcmp(last3, "one") == 0)
        match[matchLen - 1] = '1';
    else if (strcmp(last3, "two") == 0)
        match[matchLen - 1] = '2';
    else if (strcmp(last3, "ree") == 0)
        match[matchLen - 1] = '3';
    else if (strcmp(last3, "our") == 0)
        match[matchLen - 1] = '4';
    else if (strcmp(last3, "ive") == 0)
        match[matchLen - 1] = '5';
    else if (strcmp(last3, "six") == 0)
        match[matchLen - 1] = '6';
    else if (strcmp(last3, "ven") == 0)
        match[matchLen - 1] = '7';
    else if (strcmp(last3, "ght") == 0)
        match[matchLen - 1] = '8';
    else if (strcmp(last3, "ine") == 0)
        match[matchLen - 1] = '9';

    printf("%c\n", match[matchLen - 1]);
}