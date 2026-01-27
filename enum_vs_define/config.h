#ifndef __CONFIG_H__
#define __CONFIG_H__

#define PROJECT_NAME "EnumVsDefine"
#define VERSION "1.0.0"

/**
 * Using #define to declare constants
 */
// #define CONST_A 10
// #define CONST_B 20
// #define CONST_C 30

/**
 * Using enum to declare constants (commented out)
 */
enum Constants {
    CONST_A = 10,
    CONST_B = 20,
    CONST_C = 30
};

#endif // __CONFIG_H__