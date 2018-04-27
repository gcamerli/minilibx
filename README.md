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

You can also run the **configure** script to generate the appropriate `Makefile.gen`.

### **Usage**

To add the **MinilibX** to your system you can copy:

+ `libmlx.a` in `/usr/local/lib`
+ `mlx.h` in `/usr/local/include`
+ `man/man3/mlx*.1` in `/usr/local/man/man3`

### **Notes**

This version detects which operating system you are using to properly compile the library. You can use it under **FreeBSD** and **Linux** distros.

### **Credits**

This is a simple optimization based on the remarkable work made
by **Olivier Crouzet (Ol)**.

### **BSD License**

This work is licensed under the terms of
[BSD License](https://opensource.org/licenses/BSD-2-Clause).
