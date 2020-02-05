#include "main.h"

char *substring(char *str, size_t start, size_t end) {
    size_t size = end - start;
    char *out = malloc(sizeof(char) * size);

    for (size_t j = start, c = 0; j < end; j++, c++) {
        out[c] = str[j];
    }
    out[end] = '\0';

    return out;
}

ss *split_request(char *str) {
    ss *list = NULL;
    int start = 0;
    int end = 0;
    char *end_of_req = strstr(str, "\r\n\r\n");
    int req_lenght = strlen(str) - strlen(end_of_req);

    while (start <= req_lenght) {
        char *test = strstr(str + start, "\r\n");
        end = strlen(str) - strlen(test);
        char *header = substring(str, start, end);

        list = push(list, header);
        start = end + strlen("\r\n");
    }

    int len = strlen(str);
    int i = start + 1 + 1;

    while ((str[i] >= 0 && str[i] <= 127) && str[i] != '\r') {
        i++;
    }
            
    return start + 2 == len ? push(list, " ") : push(list, substring(str, start + 2, i - 2));
}