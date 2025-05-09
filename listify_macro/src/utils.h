#ifndef __UTILS_H__
#define __UTILS_H__

#define UTIL_CAT(a, ...) UTIL_PRIVATE_CAT(a, __VA_ARGS__)
#define UTIL_PRIVATE_CAT(a, ...) a ## __VA_ARGS__
#define LISTIFY(COUNT, FUNC, SEP, ...) UTIL_CAT(LISTIFY_, COUNT)(FUNC, SEP, __VA_ARGS__)

#define _DEBRACKET(...) __VA_ARGS__
#define LISTIFY_0(F, SEP, ...)
#define LISTIFY_1(F, SEP, ...) F(0, __VA_ARGS__)
#define LISTIFY_2(F, SEP, ...) \
LISTIFY_1(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(1, __VA_ARGS__)
#define LISTIFY_3(F, SEP, ...) \
LISTIFY_2(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(2, __VA_ARGS__)
#define LISTIFY_4(F, SEP, ...) \
LISTIFY_3(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(3, __VA_ARGS__)
#define LISTIFY_5(F, SEP, ...) \
LISTIFY_4(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(4, __VA_ARGS__)
#define LISTIFY_6(F, SEP, ...) \
LISTIFY_5(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(5, __VA_ARGS__)
#define LISTIFY_7(F, SEP, ...) \
LISTIFY_6(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(6, __VA_ARGS__)
#define LISTIFY_8(F, SEP, ...) \
LISTIFY_7(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(7, __VA_ARGS__)
#define LISTIFY_9(F, SEP, ...) \
LISTIFY_8(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(8, __VA_ARGS__)
#define LISTIFY_10(F, SEP, ...) \
LISTIFY_9(F, SEP, __VA_ARGS__) _DEBRACKET SEP F(9, __VA_ARGS__)

#endif // __UTILS_H__