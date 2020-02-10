#include "main.h"

request *parse_request(ss *list) {
    request *req = malloc(sizeof(request)); 

    // print(list);
    parse_body(list, req);
    // printf("req body [%s]\n", req->body);
    parse_headers(list, req);
    parse_req_str(list, req);

    return req;
}
