#include "main.h"

void parse_body(ss *list, request *req) {
    printf("parsing body\n");
    req->body = list->header;
    printf("end\n");
}

void parse_headers(ss *head, request *req) {
    ss *list = head;

    for (; list->next; list = list->next) {
        if (!list->header) continue;

        char *value = strchr(list->header, ':') + 2;
        char *header = substring(list->header, 0, strlen(list->header) - (strlen(value) + 2));
        if (strcmp("ref", header) == 0 || strcmp("Referer", header) == 0) {
            req->referer = value;
        } else {
            req->headers = push_header(req->headers, header, value);
        }
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

void parse_req_str(ss *head, request *req) {
    ss *list = head;
    
    while (list->next) {
        if (!list->header) {
            list = list->next;
            continue;
        }
        list = list->next;
    }

    int start = 0;
    char *space = strchr(list->header, ' ');
    int end = strlen(list->header) - strlen(space);
    char *method = substring(list->header, start, end);

    req->method = check_method(method);
    printf("%u\n", req->method);

    start = end + 1;
    space = strchr(list->header + start, ' ');
    end = strlen(list->header) - strlen(space);
    req->url = substring(list->header, start, end);
    printf("%s\n", req->url);

    start = strlen(strchr(list->header + start, '/')) + 1;
    end = strlen(list->header);
    req->version = substring(list->header, start, end);
    printf("%s\n", req->version);
}