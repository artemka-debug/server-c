#include "main.h"

request *parse_request(char *str) {
    request *req = malloc(sizeof(request)); 
    // printf("start [%s] \n", str); 
    printf("1");
    ss *list = split_request(str);

    print(list);
    parse_body(list, req);
    printf("req body [%s]\n", req->body);
    parse_headers(list, req);
    print_h(req->headers);
    parse_req_str(list, req);
    // free_ss(list);

    return req;
}
