#include "main.h"

void free_header(struct Header *h, int h_amount) {
    Header *next = NULL;
    printf("TEST [%i]\n", h_amount);
    for (int i = 0; i < h_amount; i++) {
        next = h->next;
        free(h->name);
        free(h);
        h = next;
    }
}

void free_request(struct request *req, int h_amount) { 
    free(req->url);
    free(req->version);
    free_header(req->headers, h_amount);
    free(req);
}

void free_ss(ss *head) {
    for (size_t i = 0; i < head->top; i++) {
        free(head->header[i]);
    }
    free(head);
}
