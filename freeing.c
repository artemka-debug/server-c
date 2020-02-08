#include "main.h"

void free_header(struct Header *h) {
    if (h) {
        free(h->name);
        free_header(h->next);
        free(h);
    }
}

void free_request(struct request *req) { 
    free(req->url);
    free(req->version);
    free_header(req->headers);
    free(req->body);
    free(req->referer);
    free(req);
}

void free_ss(ss *head) {
    for (size_t i = 0; i < head->top - 1; i++) {
        free(head->header[i]);
    }
}
