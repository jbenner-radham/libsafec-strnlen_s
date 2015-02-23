/*------------------------------------------------------------------
 * strnlen_s.c
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

size_t strnlen_s(const char *s, size_t maxsize)
{
    if (s == NULL) {
        return 0;
    }

    size_t count = 0;

    while (*s++ && maxsize--) {
        count++;
    }

    return count;
}
