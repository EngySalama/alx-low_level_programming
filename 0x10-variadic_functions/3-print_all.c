#include "variadic_functions.h"

/**
 * format_char - formats character
 * @separator: the string separator
 * @ap: argument pointer
 */
void format_char(char *separator, va_list ap)
{
	printf("%s%c", separator, va_arg(ap, int));
}

/**
 * format_int - formats integer
 * @separator: the string seprator
 * @ap: argument pointer
 */
void format_int(char *separator, va_list ap)
{
	printf("%s%d", separator, va_arg(ap, int));
}

/**
 * format_float - formats float
 * @separator: the string separator
 * @ap: argument pointer
 */
void format_float(char *separator, va_list ap)
{
	printf("%s%f", separator, va_arg(ap, double));
}

