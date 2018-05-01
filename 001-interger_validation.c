/*
* @file        : 001-interger_validation.c
* @brief       : This file contains code to check whether the given
*                input from user is a valid integer or not.
* @author      : Thiyagarajan.P
*/


/*
 * =============== Header files ===============
 * It contains definition of library functions.
 */
#include <stdio.h>

/*
 * Macro definition used to understand the program easily
 */
#define SUCCESS  0
#define FAILURE -1

/*
 * Macro to define colour
 */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
 * @function    : main                   "Flow of program starts from here"
 * @brief       : In this program this function gets input from user and it
 *                checks whether the given input is a valid integer or not.
 * @members
 *   @num       : It will stores the input number.
 *   @tmp       : It will stores extra characters if any.
 */

int main()
{
    /*
     * Variables declaration and initialization. We cannot
     * use variables without declaration. Initialization
     * will prevent it from containting garbage value.
     */
    int num = 0;
    char tmp = '\0';

    printf("Enter a number : ");

    /*
     * Reads input from user integer will be stored in num and
     * extra character will be stored in tmp
     */
    scanf("%d%c", &num, &tmp);

    /*
     * Checking the extra input character is a 'NEWLINE', if it is true
     * then prints "The given input is a valid interger" and exits with
     * SUCCESS else checking the extra input character is a 'TAB SPACE'
     * or a 'BLANK SPACE', if it is true then prints "The given input is
     * valid interger, but has some extra spaces" and exits with SUCCESS
     * else prints "The given input is not a valid interger" and exits
     * with FAILURE.
     */
    if (tmp == '\n') {
        printf(ANSI_COLOR_GREEN "The given input is a valid integer\n" ANSI_COLOR_RESET);
        return SUCCESS;
    } else if (tmp == '\t' || tmp == ' ') {
        printf(ANSI_COLOR_YELLOW "The given input is valid integer, but has some extra spaces\n" ANSI_COLOR_RESET);
        return SUCCESS;
    } else {
        printf(ANSI_COLOR_RED "The given input is not a valid integer\n" ANSI_COLOR_RESET);
        return FAILURE;
    }
}
