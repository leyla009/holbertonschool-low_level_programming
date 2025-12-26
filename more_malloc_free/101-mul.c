#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit_str - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit_str(char *s)
{
    while (*s)
    {
        if (!isdigit(*s))
            return 0;
        s++;
    }
    return 1;
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    int len1, len2, len, i, j, carry, n1, n2, sum;
    char *num1, *num2;
    int *result;

    if (argc != 3 || !is_digit_str(argv[1]) || !is_digit_str(argv[2]))
    {
        printf("Error\n");
        return 98;
    }

    num1 = argv[1];
    num2 = argv[2];
    len1 = strlen(num1);
    len2 = strlen(num2);
    len = len1 + len2;

    /* Allocate memory for result array */
    result = calloc(len, sizeof(int));
    if (!result)
        return 98;

    /* Multiply each digit */
    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }

    /* Skip leading zeros */
    i = 0;
    while (i < len && result[i] == 0)
        i++;

    if (i == len)
        printf("0");
    else
        for (; i < len; i++)
            printf("%d", result[i]);

    printf("\n");

    free(result); /* Fixed memory leak */
    return 0;
}

