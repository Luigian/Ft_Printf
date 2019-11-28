<img src="resources/images/fdf_banner.png" width="1200">

# Ft_Printf
42 School Project

This projects seeks to discover variadic functions in C in a particularly relevant context, as well as to learn about a great example of a basic “dispatcher” in C via the use of an array of function’s pointers. This projects represents a good exercise in programming, because of printf's versatility in C. The key to a successful ft_printf is a well-structured and good extensible code.

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

using self-built standard functions

## Flowchart
<img src="resources/images/fdf_flowchart.png" width="1000">

## Input
<img src="resources/images/fdf_input.png" width="500">

## Output
<img src="resources/images/fdf_output.png" width="1000">

## Key points

* Trigonometry
* Objects
* Data structures.

## Objectives
* Simple graphic library
* Segment layout
* Events
* 3D projection to 2D

## Skills
* Graphics
* Imperative programming
* Algorithms & AI
* Rigor 

## Installation

`make` | First time compilation. Creates the library `libftprintf.a` in the `ft_printf` directory.

`make fclean` | Delete files generated from compilation.

`make re` | Delete files generated from compilation and recompile.

## Usage

`gcc resources/test_main.c ft_printf/libftprintf.a && ./a.out` | Prints the test main provided as example. 

## Credits

[*Luis Julian Sanchez Quiros*](https://www.linkedin.com/in/luis-juli%C3%A1n-s%C3%A1nchez-quir%C3%B3s-13bb3b189/)
2019. Freemont, CA
