# Why not `enum` instead `#define`?

In most cases, it seems no differences between `enum` and `#define` macros, but the nuances occur at preprocessing. Long story short, `GCC` preprocessor will replace those `#define` constants in your code by leaving `enum` constants untouched. This can be shown in action by outputting the preprocessed results on purpose.

## QuickStart

```shell
# Make sure current directory is in the root path of this project where the Makefile lives.
make clean; make
```



## Source code

The entry point of this sample code lives in `main.c` file, and the main function prints out those constants defined in `config.h` header.

```c
// main.c
#include <stdio.h>
#include "config.h"

int main() {
    printf("Project Name: %s\n", PROJECT_NAME);
    printf("Version: %s\n", VERSION);
    printf("CONST_A: %d\n", CONST_A);
    printf("CONST_B: %d\n", CONST_B);
    printf("CONST_C: %d\n", CONST_C);
    return 0;
}
```

```c
// config.h
#ifndef __CONFIG_H__
#define __CONFIG_H__

#define PROJECT_NAME "EnumVsDefine"
#define VERSION "1.0.0"

/**
 * Using #define to declare constants
 */
#define CONST_A 10
#define CONST_B 20
#define CONST_C 30

/**
 * Using enum to declare constants (commented out)
 */
// enum Constants {
//     CONST_A = 10,
//     CONST_B = 20,
//     CONST_C = 30
// };

#endif // __CONFIG_H__
```



## Pure `#define` Macros

The result of preprocessing is as shown below. Those constants such as `CONST_A` are replaced with pure integers and string.

```c
// main.preproc
// This file does not exist by default.
// It is generated after compilation by make.

// ... (ignored code)
int main() {
    printf("Project Name: %s\n", "EnumVsDefine");
    printf("Version: %s\n", "1.0.0");
    printf("CONST_A: %d\n", 10);
    printf("CONST_B: %d\n", 20);
    printf("CONST_C: %d\n", 30);
    return 0;
}
```



## `enum` Constants

The result of preprocessing is as shown below. Those constants which are pure integers are not replaced with the values defined in `enum`. They stay unchanged as names in `enum`.

```c
// main.preproc
// This file does not exist by default.
// It is generated after compilation by make.

// ... (ignored code)
# 17 "config.h"
enum Constants {
    CONST_A = 10,
    CONST_B = 20,
    CONST_C = 30
};
# 3 "main.c" 2

int main() {
    printf("Project Name: %s\n", "EnumVsDefine");
    printf("Version: %s\n", "1.0.0");
    printf("CONST_A: %d\n", CONST_A);
    printf("CONST_B: %d\n", CONST_B);
    printf("CONST_C: %d\n", CONST_C);
    return 0;
}
```

## What will happen when including this C header in assembly?

When your assembly code intends to get the right configuration from C header files, such as `config.h`, the nuances between `enum` and `#define` become obvious. With this in mind, assembler such as GNU `as` can not recognize C syntax. If there are any C syntax leaving in the assembly code after preprocessing, the assemble process will fail with parsing those C syntax such as `enum`. According to the previous discussion, preprocessor only replaces `#define` constants directly without leaving any C syntax at all. So, this turns out to be a right fit in our context that including C header from assembly code.