/*------------------------------------------------------------------
 * strnlen_s.c
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

size_t strnlen_s(const char *str, size_t maxsize)
{
    if (str == NULL) {
        return RCNEGATE(0);
    }

    if (maxsize == 0) {
        invoke_safe_str_constraint_handler("strnlen_s: maxsize is 0", NULL, ESZEROL);
        return RCNEGATE(0);
    }

    if (maxsize > RSIZE_MAX_STR) {
        invoke_safe_str_constraint_handler("strnlen_s: maxsize exceeds max", NULL, ESLEMAX);
        return RCNEGATE(0);
    }

    size_t count = 0;

    while (*dest++ && dmax--) {
        count++;
    }

    return RCNEGATE(count);
}
