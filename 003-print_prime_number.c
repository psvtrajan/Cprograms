/*
* @file        : 003-print_prime_number.c
* @brief       : Program to print all the prime numbers till a particular upper limit supplied by the user.
*                The prime numbers should be printed page-wise and the page-size should be supplied by the user.
*
*                Eg:   ./a.out
*                Enter page size: 20
*                Enter upper limit: 2000
*
*                will display 20 numbers one page at a time.
*                The user has to press some particular key to get to the next page.
*                If that key isnt pressed then user is prompted to enter again.
*
* @author      : Thiyagarajan P
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>

#include "color.h"

void get_input_int(char *prompt, int *out)
{
	char c = '\0';

	if (!prompt) {
		prompt = "Enter integer: ";
	}

	do {
		printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "%s",
				c ? "Invalid integer!!.. " : "", prompt);
		__fpurge(stdin);
		scanf("%d%c", out , &c);
	} while (c != '\n' && c != ' ' && c != '\t');
}

bool is_valid_positive_int(int val, char *option, int min, int max)
{
	if (val < min || val > max) {
		printf(ANSI_COLOR_RED "Invalid %s (%d)" ANSI_COLOR_GREEN
				" valid range is (%d-%d)\n" ANSI_COLOR_RESET,
				option, val, min, max);
		return false;
	}

	return true;
}

bool is_prime_number(int num)
{
	int factor = 1;

	if (!(num & 1) || num == 1)
		return false;

	for (factor = 3; factor < num / 2; factor += 2) {
		if (!(num % factor))
			return false;
	}

	return true;
}

void wait_till_newline(char *prompt)
{
	char c = '\0';

	if (prompt)
		printf("%s", prompt);

	do {
		scanf("%c", &c);
	} while (c != '\n');
}

void print_prime_number(int page_size, int limit)
{
	int per_page = 0, i = 0;

	if (limit >= 2)
		printf("2\n");

	per_page++;
	for (i = 3; i <= limit; i += 2) {
		if (!is_prime_number(i))
			continue;

		if (per_page >= page_size) {
			per_page = 0;
			wait_till_newline("Press [Enter] for next page");
		}
		printf("%d\n", i);
		per_page++;
	}
}

void help(char *program)
{
	printf("Usage: %s [[-p page_size] [-l limit]] [-h]\n", program);
	printf("Options:\n");
	printf("\tp - Number of entries to print per page\n");
	printf("\tl - Upper limit to print prime numbers\n");
	printf("\th - Print this message\n");
}

int main(int argc, char **argv)
{
	char c = '\0';
	bool valid = true;
	int page_size = 0, limit = 0;

	while ((c = getopt(argc, argv, "hl:p:")) != -1) {
		switch (c) {
		case 'p':
			page_size = atoi(optarg);
			break;
		case 'l':
			limit = atoi(optarg);
			break;
		case 'h':
		default:
			help(argv[0]);
			return -EXIT_FAILURE;
		}
	}

	if (!page_size) {
		get_input_int("Enter page size: ", &page_size);
	}

	valid = is_valid_positive_int(page_size, "page size", 1, 50);
	if (valid == false)
		return -EXIT_FAILURE;

	if (!limit) {
		get_input_int("Enter upper limit: ", &limit);
	}

	valid = is_valid_positive_int(limit, "upper limit", 1, 0x7FFFFFFF /* 2147483647 */);
	if (valid == false)
		return -EXIT_FAILURE;

	print_prime_number(page_size, limit);

	return EXIT_SUCCESS;
}
