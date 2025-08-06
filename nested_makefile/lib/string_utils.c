// Library source file - string utilities
#include "string_utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* string_reverse(const char* str) {
    if (!str) return NULL;
    
    int len = strlen(str);
    char* result = malloc(len + 1);
    
    for (int i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    
    return result;
}

char* string_upper(const char* str) {
    if (!str) return NULL;
    
    int len = strlen(str);
    char* result = malloc(len + 1);
    
    for (int i = 0; i <= len; i++) {
        result[i] = toupper(str[i]);
    }
    
    return result;
}

int string_length(const char* str) {
    return str ? strlen(str) : 0;
}
