<img src="resources/images/fdf_banner.png" width="1200">

<h1>Ft_Printf - 42 School Project</h1> 
<h3>Highlights</h3>

* This project is about re-building the printf function with most of its functionality by using only other self-built functions based on the C standard library.

* ft_printf writes output to stdout according to a format and returns the number of characters printed or a negative number in case of error.  

* ft_printf is prototyped similarly to printf: `int ft_printf(const char* format, ...)`

* ft_printf is a variadic function wich means that it can print a varying number of arguments of varying types.

* The string `const char* format` is composed by ordinary characters (not %), which are copied unchanged to the output; and conversion specifications introduced by `%` and ended by the type of conversion which must correspond properly to the next argument in the argument list `...`. The following may appear in a conversion sequence: 

  `%[argument][flags][width][precision][length]type`

<h3>Supported</h3>

|Specifier|Group|Description|
|---------|-----|-----------|
|n`$`|argument|Decimal digit string followed by a $, specifying the next argument to access.|
|`#`|flag|Known as the 'alternate form', may add '0' for o, '0x' for x and '0X' for X. For f always print the decimal point.|
|`0`|flag|The value is padded on the left with zeros rather than blanks when the 'width' option is specified.|
|`-`|flag|The converted value is to be left adjusted on the field boundary.|
|` ` (space)|flag|A blank should be left before a positive number produced by a signed conversion.|
|`+`|flag|A sign must always be placed before a number produced by a signed conversion.|
|`'`|flag|Decimal and floating point conversion should be grouped and separated by thousands.|
|n|width| Decimal digit string specifying a minimum field width.|
|`.`n|precision|A period '.' followed by a digit string gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the decimal point for f, or the maximum number of characters to be printed from a string for s conversions.
|`hh`|length|Specifies the size of the argument as 'signed char' or 'unsigned char'.
|`h`|length|Specifies the size of the argument as 'short' or 'unsigned short'.
|`l`|length|Specifies the size of the argument as 'long' or 'unsigned long'.
|`ll`|length|Specifies the size of the argument as 'long long' or 'unsigned long long'.
|`j`|length|Specifies the size of the argument as 'intmax_t' or 'uintmax_t'.
|`z`|length|Specifies the size of the argument as 'size_t'.
|`L`|length|Specifies the size of the argument as 'long double'.

|Type|Description|
|----|-----------|
|`c`|The int argument is converted to an unsigned char.|
|`s`|The argument is expected to be a pointer to an array of character type.|
|`p`|The void * pointer argument is printed in hexadecimal.|
|`d`,`i`|The argument is converted to signed decimal.|
|`o`|The argument is converted to unsigned octal.|
|`u`|The argument is converted to unsigned decimal.|
|`U`|The 'long int' argument is converted to unsigned decimal.|
|`x`|The argument is converted to unsigned hexadecimal in lowercase.|
|`X`|The argument is converted to unsigned hexadecimal in uppercase.|
|`f`|The double argument is rounded and converted to decimal notation in the style `[-]ddd.ddd`.|
|`e`|The double argument is rounded and converted in the style `[-]d.ddde+-dd`.|
|`g`|The double argument is converted in style f or e. Style e is used if the exponent from its conversion is less than -4 or greater than or equal to the precision.|
|`%`|A '%' is written.  No argument is converted. The complete conversion specification is `%%`.|
|`b`|The argument is printed in binary.|
|`k`|The int argument is converted to timestamp.|




a great example of a basic “dispatcher” in C via the use of an array of function’s pointers. This projects represents a good exercise in programming, because of printf's versatility in C. The key to a successful ft_printf is a well-structured and good extensible code.





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
