#include "main.h"

request *parse_request(char *str) {
    printf("------------------------\n");
    request *req = malloc(sizeof(request)); 
    printf("start %send \n", str); 
    ss *list = split_request(str);

    print(list);
    parse_body(list, req);
    parse_headers(list->next, req);
    print_h(req->headers);
    parse_req_str(list, req);
    free_ss(list);

    printf("------------------------\n");

    return req;
}
