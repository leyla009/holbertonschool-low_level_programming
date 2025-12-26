#include <stdlib.h>
#include <stdio.h>

/**
 * is_digit - checks if string contains only digits
 * @s: string to check
 *
 * Return: 1 if digits only, 0 otherwise
 */
int is_digit(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

/**
 * _strlen - returns length of string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
    int len = 0;
    while (*s++)
        len++;
    return (len);
}

/**
 * multiply - multiplies two numbers as strings
 * @num1: first number
 * @num2: second number
 * @result: result buffer
 *
 * Return: pointer to result string
 */
char *multiply(char *num1, char *num2, char *result)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int i, j, n1, n2, carry, sum;
    
    for (i = 0; i < len1 + len2; i++)
        result[i] = '0';
    
    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = (result[i + j + 1] - '0') * n1 + n2 * (num1[i] - '0') + carry;
            carry = sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }
        result[i + j + 1] += carry;
    }
    return result;
}

/**
 * remove_leading_zeros - removes leading zeros from string
 * @s: string
 *
 * Return: pointer to first non-zero digit
 */
char *remove_leading_zeros(char *s)
{
    while (*s == '0' && *(s + 1) != '\0')
        s++;
    return (s);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    char *num1, *num2, *result;
    int len1, len2, len_result;
    
    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }
    
    num1 = argv<span class="source-link" data-source-id="1" data-source-url=""><span class="source-link-title"><span></span></span><span class="source-tooltip"><span>Sources · 1</span><span class="source-tooltip-content"><a href="" target="_blank" rel="noopener noreferrer"><img class="source-tooltip-content-img" src="https://www.google.com/s2/favicons?domain=null&sz=64" /><span class="source-tooltip-text"></span></a></span></span></span>;
    num2 = argv<span class="source-link" data-source-id="2" data-source-url=""><span class="source-link-title"><span></span></span><span class="source-tooltip"><span>Sources · 1</span><span class="source-tooltip-content"><a href="" target="_blank" rel="noopener noreferrer"><img class="source-tooltip-content-img" src="https://www.google.com/s2/favicons?domain=null&sz=64" /><span class="source-tooltip-text"></span></a></span></span></span>;
    
    if (!is_digit(num1) || !is_digit(num2))
    {
        printf("Error\n");
        exit(98);
    }
    
    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len_result = len1 + len2;
    
    result = malloc(sizeof(char) * (len_result + 1));
    if (!result)
        return (0);
    
    multiply(num1, num2, result);
    result[len_result] = '\0';
    
    printf("%s\n", remove_leading_zeros(result));
    free(result);
    
    return (0);
}
