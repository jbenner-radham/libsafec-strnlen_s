/*------------------------------------------------------------------
 * strnlen_s.c
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

rsize_t strnlen_s(const char *dest, rsize_t dmax)
{
    if (dest == NULL) {
        return RCNEGATE(0);
    }

    if (dmax == 0) {
        invoke_safe_str_constraint_handler("strnlen_s: dmax is 0", NULL, ESZEROL);
        return RCNEGATE(0);
    }

    if (dmax > RSIZE_MAX_STR) {
        invoke_safe_str_constraint_handler("strnlen_s: dmax exceeds max", NULL, ESLEMAX);
        return RCNEGATE(0);
    }

    rsize_t count = 0;

    while (*dest++ && dmax--) {
        count++;
    }

    return RCNEGATE(count);
}
