#include "monty.h"

/**
 * error_handler - Prints appropriate error messages based on error codes.
 * @error_code: The error codes and their meanings:
 *   (1) => No file provided or more than one file given to the program.
 *   (2) => Unable to open or read the provided file.
 *   (3) => Invalid instruction in the file.
 *   (4) => Memory allocation failure.
 *   (5) => Non-integer parameter passed to the "push" instruction.
 */
void error_handler(int error_code, ...)
{
	va_list args;
	char *op;
	int line_number;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_number = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
			break;
		case 4:
			fprintf(stderr, "Error: Memory allocation failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * stack_operation_error - Handles various stack operation errors.
 * @error_code: The error codes and their meanings:
 *   (6) => Stack is empty for pint.
 *   (7) => Stack is empty for pop.
 *   (8) => Stack is too short for an operation.
 *   (9) => Division by zero.
 */
void stack_operation_error(int error_code, ...)
{
	va_list args;
	char *op;
	int line_number;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			line_number = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_operation_error - Handles errors related to string operations.
 * @error_code: The error codes and their meanings:
 *   (10) => Value inside a node is outside ASCII bounds for pchar.
 *   (11) => Stack is empty for pchar.
 */
void string_operation_error(int error_code, ...)
{
	va_list args;
	int line_number;

	va_start(args, error_code);
	line_number = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
