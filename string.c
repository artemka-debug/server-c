#include "main.h"

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    
    return result;
}

char* concat_h(const char *s1, int last_header) {
    char *final_header = malloc(strlen(s1) + last_header ? 4 : 2);
	final_header[strlen(final_header)] = '\r';
	final_header[strlen(final_header)] = '\n';

    if (last_header) {
        final_header[strlen(final_header)] = '\r';
        final_header[strlen(final_header)] = '\n';
    }
    return final_header;
}

char *substring(char *str, size_t start, size_t end) {
    size_t size = end - start;
    char *out = malloc(sizeof(char) * (size + 1));
    int c = 0;

    for (size_t j = start; j < end; j++, c++) {
        out[c] = str[j];
    }
    out[c] = '\0';

    return out;
}

