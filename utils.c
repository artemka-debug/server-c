#include "main.h"

char *pop_from_ss(ss **head) {
    if (!*head) printf("SS IS EMPTY\n");

    ss *h = *head;
    char *data = (*head)->header;

    *head = (*head)->next;
    free(h);
    return data;
}

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

void print(ss *head) {
    printf("START OF SS\n");
    ss *tmp = head;

    while (tmp) {
        printf("ss [%s]\n", tmp->header);
        tmp = tmp->next;
    }
    printf("END OF SS\n");
}


void print_h(Header *head) {
    Header *tmp = head;

    while (tmp) {
        printf("headers [%s %s]\n", tmp->name, tmp->value);
        tmp = tmp->next;
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
        free_ss(head->next);
        free(head);
    }
}

ss *push(ss *head, char *header) {
    ss *new = malloc(sizeof(ss));
    new->header = header;
    new->next = head;

    return new;
}

Header *push_header(Header *head, char *name, char *value) {
    Header *new = malloc(sizeof(Header));
    new->value = value;
    new->name = name;
    new->next = head;

    return new;
}
