#include "shell.h"

/**
 * bfree - to free a pointer and NULLs the address
 * @ptr: address of the pointer to be freed
 *
 * Return: 0 if freed, otherwise 1.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
