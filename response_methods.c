#include "main.h"

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* concat_h(const char *s1, const char *s2, int last_header) {
    char *final_header = malloc(strlen(s1) + strlen(s2) + 7); // +1 for the null-terminator
    strcpy(final_header, s1);
	final_header[strlen(final_header)] = ':';
	final_header[strlen(final_header)] = ' ';
    strcat(final_header, s2);
	final_header[strlen(final_header)] = '\r';
	final_header[strlen(final_header)] = '\n';

    if (last_header) {
        final_header[strlen(final_header)] = '\r';
        final_header[strlen(final_header)] = '\n';
    }
    return final_header;
}
