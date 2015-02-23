# Safe C Lib - strnlen_s

## Synopsis

```c
#include "safe_str_lib.h"
size_t strnlen_s(const char *s, size_t maxsize)
```

### Description

The `strnlen_s` function computes the length of the string pointed to by `s`.

### Specified In

ISO/IEC TR 24731-1 § 6.7.4.3, Programming languages, environments and system software
interfaces, Extensions to the C Library, Part I: Bounds-checking interfaces.

### Input Parameters

- `s` pointer to string
- `maxsize` restricted maximum length.

### Output Parameters

    none

### Runtime Constraints

    none

### Returns

If `s` is a null pointer, then the `strnlen_s` function returns zero.

Otherwise, the `strnlen_s` function returns the number of characters that precede the terminating null character. If there is no null character in the first `maxsize` characters of `s` then `strnlen_s` returns `maxsize`. At most the first `maxsize` characters of `s` shall be accessed by strnlen_s.
