# Review

How does $C$ know what the end of the string is?

A string in $C$ ends with a NUL byte, which is 0x00 (`\0`).

### What happens when you try to use a constant variable in place of a non constant variable?

```c
void foo (int* a) {
	// do something
}

int main() {
	const int x = 5;
	foo(&x);
}
```

Most compilers will see this code and, at minimum, give a compiler warning. At most, it will throw an error and prevent compilation of this code.

If this compiles, this is known as **UB** (undefined behaviour). That means it will *probably* crash at runtime.

```c
const int x = 1;
int* const const_ptr = &x;
```

This won't compile because these are two different types, a `const int` vs a `int* const` which is a `const` pointer to an `int`.

# New stuff

- Strings and string functions
- Immutable strings
- Reading user input
	- `scanf`
- 2D arrays

## The string.h Library

```c
#include <string.h>
```

> The string.$h$ library includes "string manipulation functions" which are library/helper functions for... manipulating strings

Whenever you pass these functions a $c$ string, you are implicitly saying that you are passing it a *proper $c$ string*

- Must end with `\0` 

Because these functions rely on the final character being a NUL byte, setting any random character in the char* array to `\0` may break many of these functions

### strlen
- Returns the length of the string, excluding the NUL byte.
- Does not always mean the size allocated to the actual char array

```c
char str1[20] = "Hello World!";
str1[5] = '\0';

printf("%d", (int)strlen(str1)); // 5
```

Despite "Hello World!" being markedly longer than 5 characters, strlen will return 5 because it exits on NUL byte.

### strcpy - `strcpy(char* dest, const char* src)`

`strcpy` is a convenient way to deep copy (copy by value) a $c$ string. (the length of the destination must be sufficent to copy)

It knows when to stop copying when it sees the NUL byte (which it will also copy over)

A variant of this function is the `strncpy` function which only copies a part (`n`) of the $C$ string from the source.

> prof says to google `strncpy` as an exercise for the reader (LOL)

### strcat - `strcat(char* dest, const char* src)`

**str**ing con**cat**enation -> stitch two strings together

A way to create a new $C$ string by combining 2 $C$ strings. This function also does *not* check if the destination is sufficient in size, so that is up to the author.

It knows where to begin and when to stop when it sees the NUL byte, which it will also copy over.

### strcmp - `strcmp(const char* str1, const char* str2)`

**str**ing **c**o**mp**are

When comparing two $C$ strings, it makes sense to write the code `str1 == str2`, but **this is wrong!** When you do this, you are actually comparing the address of `str1` and `str2` in memory.

Instead, you must use `strcmp`.

- Returns 0 if contents of both $C$ strings are equal
- Returns a non-zero upon the first mismatch: <0 if the mismatch character in str1 has a lower value than in str2, >0 otherwise.
- With this information, you can sort $C$ strings in alphabetical order (foreshadowing)

Be careful with `strcmp` because it returns 0 for true, which generally represents false

### strstr - `strstr(const char* str1, const char* str2)`

Looks for the presence of str2 (substring) within str1.
- Stops at the first occurrence of this and returns a pointer to it. 

A variant of this function is the `strchr` function that locates the first occurrence of a character (including `\0`)

> Prof says "what if I want to define a function which finds all the occurrences of a substring within another string"

Something along the lines of "making use of the first pointer that gets returned" (big foreshadowing)

What if you call `strstr` on a string and it doesn't exist?
- Then, it will return the NULL pointer (0x00 pointer). 

## Tips on Using $C$ Strings

- They are just character arrays that end with `\0`
- Always remember to `#include <string.h>` 

### Immutable Strings

There are 3 main ways to create a $C$ string
- `char str1[5] = { 'w', 'o', 'r', 'd', '\0' }` -> array of size 5 initialized with values
- `char str2[] = { 'w', 'o', 'r', 'd', '\0'}` -> same as the above but the compiler sets the length
- `char* str3 = "word";` -> creating with a string literal (stored in a special location in memory)

The third way is different because of how it is stored in memory - as an immutable string

`str3[3] = 'k'` -> this will cause a SEGFAULT that crashes a program due to attempting to modify a read-only memory location.

`printf("%c", str3[3])` -> this is ok because it is just reading the value from the memory location.

# Interactive Programs

## scanf

```c
int scanf(const char *format, ...);
```

```c
int x = 0; y = 0;

scanf("%d %d", &x, &y);

printf("This reads 2 integers from the console, %d and %d\n", x, y);
```

You can use different format specifiers (`%s, %c, %d, etc)

The return type of scanf indicates the number of values that have been successfully read.

# 2d arrays
Essentially, a 2d array is a pointer to an array of pointers.

```c
int int2DArr[4][25]; // 2DArr of 100 integers, in 4 rows of 25
```

## Passing 2DArrays into functions

You need to specify how many rows in the parameter type.

## Matrices and 2D arrays

In mathematics, matrices group number into rectangular arrays to outline their relationship. 

This grouping can be represented will in a 2D array of integers

Matrix operations such as addition, multiplication and row reduction can be done on these matrices. 