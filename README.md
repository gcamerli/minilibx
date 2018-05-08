# **MinilibX**

42 (Paris)

### **Description**

Simplified **X-Window** (X11R6) programming **API**
written in **C**, suitable for X-beginners.

### **Requirements**

+ **gcc**
+ **X11** library
+ **XShm** extension

**MinilibX** only supports **TrueColor visual type**
(8,15,16,24 or 32 bits depth).

### **Setup**

To compile **MinilibX**, execute:

```bash
$ make
```

The compilation produce `libmlx.a` and `libmlx_$(HOSTTYPE).a` files.

Alternatively, you can also run the **configure** script to generate the appropriate `Makefile.gen` and the .a files.

### **Usage**

To add the **MinilibX** to your system you can copy:

+ `libmlx.a` in `/usr/local/lib`
+ `mlx.h` in `/usr/local/include`
+ `man/man3/mlx*.1` in `/usr/local/man/man3`

### **Notes**

This version detects which operating system you are using to properly compile the library. You can use it under **FreeBSD** and **Linux** distros.

Personal additions to the original version are:

+ Customization of the `Makefile` and the `configure` script
+ .c and .h files cleaned according to the **42 Norme**

The following `src` files present errors related to the way they were coded. You can ignore them all:

+ **mlx_hook.c**

```text
Error (line 15): mlx_hook have 5 parameters
```

+ **mlx_int_param_event.c**

```text
Error: 8 functions in the file
Error (line 20, col 0): mlx_int_param_KeyPress not unixcase
Error (line 27, col 0): mlx_int_param_KeyRelease not unixcase
Error (line 34, col 0): mlx_int_param_ButtonPress not unixcase
Error (line 40, col 0): mlx_int_param_ButtonRelease not unixcase
Error (line 47, col 0): mlx_int_param_MotionNotify not unixcase
Error (line 53, col 0): mlx_int_param_Expose not unixcase
Error (line 64, col 7): global named mlx_int_param_event is not well prefixed
```

+ **mlx_int_str_to_wordtab.c**

```text
Error (line 68): function mlx_int_str_to_wordtab has 38 lines
```

+ **mlx_lib_xpm.c**

```text
Error (line 15): mlx_int_xpm_f_image have 5 parameters
Error (line 15): function mlx_int_xpm_f_image has 45 lines
```

+ **mlx_new_window.c**

```text
Error (line 27): function mlx_new_window has 27 lines
```

+ **mlx_put_image_to_window.c**

```text
Error (line 15): mlx_put_image_to_window have 5 parameters
```

+ **mlx_loop.c**

```text
Error (line 15, col 14): global named mlx_int_param_event is not well prefixed
```

+ **mlx_string_put.c**

```text
Error (line 15): mlx_string_put have 6 parameters
```

+ **mlx_new_image.c**

```text
Error (line 21, col 5): mlx_X_error not unixcase
Error (line 21, col 5): global named mlx_X_error is not well prefixed
Error (line 34): function mlx_int_new_xshm_image has 67 lines
Error (line 105): function mlx_int_new_image has 26 lines
```

+ **mlx_pixel_put.c**

```text
Error (line 15): mlx_pixel_put have 5 parameters
```

+ **mlx_xpm.c**

```text
Error: 9 functions in the file
Error (line 18): preprocessor block must be followed by one empty line
Error (line 18): multiline define
Error (line 98): mlx_int_xpm_set_pixel have 5 parameters
Error (line 113): function mlx_int_parse_xpm has 135 lines
Error (line 113, col 0): mlx_int_parse_xpm has 23 variables
```

### **Credits**

This is a simple optimization based on the remarkable work made
by **Olivier Crouzet (Ol)**, Head of pedagogy at **42**.

### **BSD License**

This work is licensed under the terms of
[BSD License](https://opensource.org/licenses/BSD-2-Clause).
