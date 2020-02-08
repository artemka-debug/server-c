#include "main.h"

void add_get_path(get *get, char *path[], int length) {
    if (!get->top) get->top = 0;

    for (int i = 0; i < length; i++) {
        get->pathes[get->top++] = path[i];
    }
}

void add_get_func(get *get, void (*fnc[])(request *req, int new_socket), int length) {
    if (!get->top) get->top = 0;

    for (int i = 0; i < length; i++) {
        get->fnc[get->top_fnc++] = fnc[i];
    }
}

void add_post_path(post *post, char *path[], int length) {
    if (!post->top) post->top = 0;

    for (int i = 0; i < length; i++) {
        post->pathes[post->top++] = path[i];
    }
}

void add_post_func(post *post, void (*fnc[])(request *req, int new_socket), int length) {
    if (!post->top) post->top = 0;

    for (int i = 0; i < length; i++) {
        post->fnc[post->top_fnc++] = fnc[i];
    }
}

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
