#include "main.h"

char *make_response_string(char *status, char *http_version, char *json_data, char *headers) {
    char *response_string = malloc(sizeof(char) * (strlen(status) + strlen(http_version) + 8));
    int offset = 5;

    strcpy(response_string, "HTTP/");
    strcpy(response_string + offset, http_version);
    offset += strlen(http_version);
    strcpy(response_string + offset, status);
    offset += strlen(status);
    strcpy(response_string + offset, "\r\n");

    if (json_data && headers) {
        char *h = concat(response_string, headers);
        char *res = concat(h, json_data);
        free(h);
        free(response_string);

        return res;
    }

    char *res = concat(response_string, "\r\n");
    free(response_string);

    return res;
}