/*
 * @file    : 002-bin_oct_hex_of_dec.c
 * @brief   : This file contain the code to print binary,
 *            octal and hexadecimal form of decimal number.
 * @author  : Thiyagarajan.P
 */

/* ================= Header files ============ */
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

/* Macro */
#define SUCCESS  0
#define FAILURE -1

/* Macro to define colour */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
 * @function    : main
 * @brief       : program starts from here
 * @members
 *  @decimal_num : User input which should be converted into 
 *                 binary, octal and hexadecimal.
 *  @extra_char  : To get extra character except integer from
 *                 user to validate the input.
 *  @i, tmp      : Temporary variables to do the convertion.
 */
int main()
{
    unsigned int decimal_num = 0;
    int i = 0, tmp = 0;
    char extra_char = '\0';
    
    printf("Enter a positive decimal number : ");
    __fpurge(stdin);
    scanf("%u%c", &decimal_num, &extra_char);

    /* Validating user input. */
    while (extra_char != '\n' && extra_char != '\t' && extra_char != ' ') {
        printf(ANSI_COLOR_RED "Enter valid positive integer    : " 
                ANSI_COLOR_RESET);
        __fpurge(stdin);
        scanf("%u%c", &decimal_num, &extra_char);
    }

    if (extra_char != '\n') {
        printf(ANSI_COLOR_YELLOW "The given input has some null character with "
                "integer\n" ANSI_COLOR_RESET);
    }

    /*
     * Converting given decimal number to binary form and printing the output.
     */
    printf("Binary form of %u      : ", decimal_num);
    for (i = 31; i >= 0; i--) {
        tmp = decimal_num >> i;
        printf("%d", tmp & 1);
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");

    /*
     * %#39o will align the output to the right and add leading 0 for octal value.
     * %#39x will align the output to the right and add leading 0x for hex value.
     */
    printf("Octal form of %u       : %#39o\n", decimal_num, decimal_num);
    printf("Hexadecimal form of %u : %#39x\n", decimal_num, decimal_num);
    return SUCCESS;
}
