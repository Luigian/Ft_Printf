<img src="resources/images/fdf_banner.png" width="1200">

# Ft_Printf
### A 42 School Project

* This project is about re-building the printf function with most of its functionality by using only other self-built functions based on the C standard library.

* ft_printf writes output to stdout according to a format and returns the number of characters printed or a negative number in case of error.  

* ft_printf is prototyped similarly to printf: `int ft_printf(const char* format, ...)`

* ft_printf is a variadic function wich means that it can print a varying number of arguments of varying types.

* The string `const char* format` is composed by ordinary characters (not %), which are copied unchanged to the output; and conversion specifications introduced by `%` and ended by the type of conversion which must correspond properly to the next argument in the argument list `...`. The following may appear in a conversion sequence: 

  `%[argument][flags][width][precision][length]type`

This implementation handles:
<h3>Handled Conversion specifiers</h3>

|Group|Specifier | Description|
|-----|----------|------------|
|argument|`n$`|Decimal digit string followed by a $, specifying the next argument to access.|
|flag|`#`|May add '0' to `o`, '0x' to `x` and '0X' to `X`. Print the decimal point for `f`. Known as the 'alternate form'.|
|flag|`0`|The value is padded on the left with zeros rather than blanks when the 'width' option is specified.|
|flag|`-`|the converted value is to be left adjusted on the field boundary.|
|flag|` `|A blank should be left before a positive number produced by a signed conversion.|
|flag|`+`| A sign must always be placed before a number produced by a signed conversion.|
|flag|`'`| Decimal and floating point conversion should be grouped and separated by thousands.|


|`%` | literal % character.|
|<code>c</code> | a specified char.|
|<code>s</code> | string, a sequence of characters preceded of a '\0' char.|
|<code>p</code> | the address of a variable in hexadecimal form|
|<code>d,i</code> | int as a signed decimal number.|
|<code>o</code> | unsigned int in octal.|
|<code>u</code> | decimal unsigned int.|
|<code>x</code> | unsigned int as a hexadecimal number (lowercase).|
|<code>X</code> | unsigned int as a hexadecimal number (UPPERCASE).|
|<code>f</code> | double in normal (fixed-point) notation.|

<h3>Handled Flags</h3>

|Character | Description|
|----------|------------|
|<code>h</code> | For integer types, expects an int-sized integer argument which was promoted from a short.|
|<code>hh</code> | For integer types, expects an int-sized integer argument which was promoted from a char.|
|<code>l</code> | For integer types, expects a long-sized integer argument. No effects on floating point vars.|
|<code>ll</code> | For integer types, expects a long long-sized integer argument.|
|<code>L</code> | For floating point types, causes printf to expect a long double argument.|









n$, #, 0, -, (space), +, ', n, .n 


a great example of a basic “dispatcher” in C via the use of an array of function’s pointers. This projects represents a good exercise in programming, because of printf's versatility in C. The key to a successful ft_printf is a well-structured and good extensible code.

Re-creation of the printf function, supporting %s, %S, %p, %d, %D, %i, %o, %O, %u, %U, %x, %X, %c, %C and more

This project aims at rebuilding the printf library with basic functionality.

This implementation includes management of:

Minimal field width
Precision
Wildcards
Length flags "hh, h, l, ll, j, z"
Flags "#, 0, -, +"
Unicode characters
Convensions "s, S, p, d, D, i, o, O, u, U, x, X, c, C, n"



## Flowchart
<img src="resources/images/fdf_flowchart.png" width="1000">

## Input
<img src="resources/images/fdf_input.png" width="500">

## Output
<img src="resources/images/fdf_output.png" width="1000">

## Installation

`make && make clean` | Compiles and creates the library `libftprintf.a`.

`make re && make clean` | Recompiles.

## Usage

`gcc resources/test_main.c libftprintf.a && ./a.out` | Prints the test main provided as example. 

## Credits

[*Luis Julian Sanchez Quiros*](https://www.linkedin.com/in/luis-juli%C3%A1n-s%C3%A1nchez-quir%C3%B3s-13bb3b189/)
2019. Freemont, CA
