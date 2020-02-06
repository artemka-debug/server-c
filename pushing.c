#include "main.h"
void push(ss *head, char *data) {
    if (!head->top) head->top = 0;

    head->header[head->top++] = data;
}

Header *push_header(Header *head, char *name, char *value) {
    Header *new = malloc(sizeof(Header));
    new->value = value;
    new->name = name;
    new->next = head;

    return new;
}
