#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertCharToDigit(char* match, int matchLen, int isLast);

int main()
{
    FILE* fp = fopen("input.txt", "r");

    // Get the longest possible string that starts and ends with a digit OR a word that spells a digit
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
    while (fgets(line, sizeof(line), fp))
    {
        regexec(&regex, line, 1, &match, 0);
        int matchLen = match.rm_eo - match.rm_so;

        // If first or last char is alpha, convert it to a digit
        if (isalpha(line[match.rm_so]))
            convertCharToDigit(&line[match.rm_so], matchLen, 0);
        if (isalpha(line[match.rm_eo - 1]))
            convertCharToDigit(&line[match.rm_so], matchLen, 1);

        digits[0] = line[match.rm_so];
        digits[1] = line[match.rm_eo - 1];

        // Convert to int and add it to total
        num = atoi(digits);
        sum += num;
    }
    fclose(fp);
    regfree(&regex);

    printf("Sum: %d\n", sum);

    return 0;
}

void convertCharToDigit(char* match, int matchLen, int isLast)
{
    char* words[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int lengths[] = { 3, 3, 5, 4, 4, 3, 5, 5, 4 };
    for (int i = 0; i < 9; i++)
    {
        int offset = isLast ? matchLen - lengths[i] : 0;
        if (strncmp(match + offset, words[i], lengths[i]) == 0)
        {
            if (isLast) match[matchLen - 1] = i + '1';
            else match[0] = i + '1';
            break;
        }
    }
}
