#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit_str - checks if a string contains only digits
 * @s: string to check
 * Return: 1 if valid, 0 otherwise
 */
int is_digit_str(char *s)
{
    int i = 0;

    if (!s || !s[0])
        return (0);

    while (s[i])
    {
        if (!isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    int i, j, carry, n1, n2, sum;
    int len1, len2, len, start = 0;
    int *result = NULL;

    if (argc != 3 || !is_digit_str(argv[1]) || !is_digit_str(argv[2]))
    {
        printf("Error\n");
        return (98);
    }

    len1 = strlen(argv[1]);
    len2 = strlen(argv[2]);
    len = len1 + len2;

    result = calloc(len, sizeof(int));
    if (!result)
        return (98);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = argv[1][i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = argv[2][j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }

    while (start < len && result[start] == 0)
        start++;

    if (start == len)
        printf("0");
    else
        for (i = start; i < len; i++)
            printf("%d", result[i]);

    printf("\n");

    free(result);
    return (0);
}

