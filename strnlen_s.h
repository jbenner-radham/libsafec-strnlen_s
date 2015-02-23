/*------------------------------------------------------------------
 * strnlen_s.c
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

//#include "safeclib_private.h"
//#include "safe_str_constraint.h"
//#include "../../include/safe_str_lib.h"


rsize_t
strnlen_s (const char *dest, rsize_t dmax)
{
    rsize_t count;

    if (dest == NULL) {
        return RCNEGATE(0);
    }

    if (dmax == 0) {
        invoke_safe_str_constraint_handler("strnlen_s: dmax is 0",
                   NULL, ESZEROL);
        return RCNEGATE(0);
    }

    if (dmax > RSIZE_MAX_STR) {
        invoke_safe_str_constraint_handler("strnlen_s: dmax exceeds max",
                   NULL, ESLEMAX);
        return RCNEGATE(0);
    }

    count = 0;
    while (*dest && dmax) {
        count++;
        dmax--;
        dest++;
    }

    return RCNEGATE(count);
}
