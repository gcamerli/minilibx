# **MinilibX**

42 (Paris)

### **Description**

Simplified **graphics programming** interface written in **C**.

This is the native version for **MacOSX**. It no longer uses **X11**
graphics libraries, neither **XQuartz**.

This version uses instead MacOSX's **Cocoa** window system (**AppKit**) and the modern **OpenGL** graphics primitives.

### **Notes**

The following `src` files present errors related to the way they were coded. You can ignore them all:

+ **mlx_int_str_to_wordtab.c**

```text
Error (line 40): function mlx_int_str_str_cote has 27 lines
Error (line 71): function mlx_int_str_to_wordtab has 38 lines
```

+ **mlx_shaders.c**

```text
Error (line 31): function mlx_shaders_pixel has 56 lines
Error (line 91): function mlx_shaders_image has 61 lines
Error (line 156): function mlx_shaders_font has 63 lines
Error (line 172): line has 90 characters
```

+ **mlx_xpm.c**

```text
Error: 9 functions in the file
Error (line 22): declaration of Struct forbidden in .c
Error (line 28): declaration of Struct forbidden in .c
Error (line 34): .c included
Error (line 34): #include "mlx_rgb.c" should be before line 22
Error (line 36): wrong number of spaces in preprocessor line
Error (line 36): multiline define
Error (line 111): mlx_int_xpm_set_pixel have 5 parameters
Error (line 117): function mlx_int_parse_xpm has 105 lines
Error (line 117, col 0): mlx_int_parse_xpm has 20 variables
```

### **Credits**

This is a simple optimization based on the remarkable work made
by **Olivier Crouzet (Ol)**, Head of pedagogy at **42**.

### **BSD License**

This work is licensed under the terms of
[BSD License](https://opensource.org/licenses/BSD-2-Clause).
