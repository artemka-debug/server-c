#include "main.h"

char *make_response_string(char *status, char *http_version, char *json_data, char *headers) {
    char *response_string = concat(concat("HTTP/", http_version), status);
    response_string = realloc(response_string, 2);

    response_string[strlen(response_string)] = '\r';
    response_string[strlen(response_string)] = '\n';
    
    if (headers && json_data) {
        return concat(concat(response_string, headers), json_data);
    } else {
        response_string[strlen(response_string)] = '\r';
        response_string[strlen(response_string)] = '\n';
        return response_string;
    }

    return concat(concat(response_string, json_data), "");
}