#include "monty.h"

/**
 * err - Prints appropriate error messages based on error codes.
 * @error_code: The error codes and their meanings:
 * (1) => Missing or extra file argument.
 * (2) => Unable to open or read the provided file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation (malloc) failure.
 * (5) => Invalid argument for "push" instruction.
 * Exit the program with an error code.
 */
void err(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
			va_arg(args, char *));
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n",
			va_arg(args, int), va_arg(args, char *));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}

	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - Handles additional errors.
 * @error_code: The error codes and their meanings:
 * (6) => Empty stack when trying to pint.
 * (7) => Empty stack when trying to pop.
 * (8) => Stack is too short for the operation.
 * (9) => Division by zero.
 * Exit the program with an error code.
 */
void more_err(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
			va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
			va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't %s, stack too short\n",
			va_arg(args, int), va_arg(args, char *));
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
			break;
		default:
			break;
	}

	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handles string-related errors.
 * @error_code: The error codes and their meanings:
 * (10) => Value in a node is outside ASCII bounds.
 * (11) => Stack is empty when trying to pchar.
 * Exit the program with an error code.
 */
void string_err(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n",
			va_arg(args, int));
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n",
			va_arg(args, int));
			break;
		default:
			break;
	}

	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}
