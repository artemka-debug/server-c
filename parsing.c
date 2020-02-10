#include "main.h"

void parse_body(ss *list, request *req) {
    // printf("parsing body\n");
    req->body = list->header[list->top - 1];
    // printf("end\n");
}

void parse_headers(ss *list, request *req) {
    for (int i = 1; i < list->top - 1; i++) {
        char *value = strchr(list->header[i], ':') + 2;
        char *header = substring(list->header[i], 0, strlen(list->header[i]) - (strlen(value) + 2));
        req->headers = push_header(req->headers, header, value);
    }
}

Method check_method(char *method) {
    if (strcmp(method, "GET") == 0) {
        return GET;
    } else if (strcmp(method, "POST") == 0) {
        return POST;
    } else {
        return UNSUPPORTED;
    }
}

void parse_req_str(ss *list, request *req) {
    int start = 0;
    int req_str = 0;
    char *space = strchr(list->header[req_str], ' ');
    int end = strlen(list->header[req_str]) - strlen(space);
    char *method = substring(list->header[req_str], start, end);

    req->method = check_method(method);
    // printf("%u\n", req->method);
    free(method);

    start = end + 1;
    space = strchr(list->header[req_str] + start, ' ');
    end = strlen(list->header[req_str]) - strlen(space);
    req->url = substring(list->header[req_str], start, end);
    // printf("%s\n", req->url);

    start = strlen(strchr(list->header[req_str] + start, '/')) + 1;
    end = strlen(list->header[req_str]);
    req->version = substring(list->header[req_str], start, end);
    // printf("%s\n", req->version);
}