#include "main.h"

void free_header(struct Header *h) {
    if (h) {
        printf("6\n");
        free(h->name);
        printf("7\n");
        free(h->value);

        printf("8\n");
        free_header(h->next);
        printf("9\n");

        free(h);
    }
}

void free_request(struct request *req) {
    free(req->url);
    printf("1\n");
    free(req->version);
    printf("2\n");

    free_header(req->headers);

    printf("3\n");
    free(req->body);

    printf("4\n");
    free(req->referer);
    printf("5\n");
    free(req);
}

void free_ss(ss *head) {
    if (head) {
        free(head);
    }
}
