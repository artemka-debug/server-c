#include "main.h"

char *make_response_string(char *status, char *http_version, char *json_data, char *headers) {
    
    char *version = concat("HTTP/", http_version);
    char *http_string = concat(version, status);
    char *response_string = concat(http_string, "\r\n");
    
    if (json_data && headers) {
        return concat(concat(response_string, headers), json_data);
    }

    return concat(response_string, "\r\n");
}