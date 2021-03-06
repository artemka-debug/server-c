#include "main.h"

int get_body_lenght(ss *list) {
    for (int i = 0; i < list->top; i++) {
        if (strstr(list->header[i], "content-length")) {
            return atoi(strchr(list->header[i], ':') + 2);
        }
    }

    return 0;
}

ss *split_request(char *str) {
    ss *list = malloc(sizeof(ss));
    list->top = 0;
    int start = 0;
    char *end_of_req = strstr(str, "\r\n\r\n");
    int req_lenght = strlen(str) - strlen(end_of_req);

    while (start <= req_lenght) {
        char *test = strstr(str + start, "\r\n");
        int end = strlen(str) - strlen(test);
        char *header = substring(str, start, end);
        // printf("testing %i %i [%s]\n", start, end, header);

        push(list, header);
        start = end + strlen("\r\n");
    }
    
    start += 2;
    // printf("TEST [%i %i %i]", start, get_body_lenght(list), strlen(str));
    push(list, substring(str, start, start + get_body_lenght(list)));
    return list;
}