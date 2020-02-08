#include "main.h"

void _get(request *req, get *get, char *path, int new_socket) {
    for (int i = 0; i < get->top; i++) {
        if (strcmp(path, get->pathes[i]) == 0) {
            get->fnc[i](req, new_socket);
        }
    }
    respond(new_socket, make_response_string(" 500 Not Handled", VERSION, NULL, NULL));
}

void _post(request *req, post *post, char *path, int new_socket) {
    for (int i = 0; i < post->top; i++) {
        if (strcmp(path, post->pathes[i]) == 0) {
            post->fnc[i](req, new_socket);
        }
    }
    respond(new_socket, make_response_string(" 500 Not Handled", VERSION, "\r\n\r\n", NULL));
}

 void router(request *req, int new_socket, r *Router) {
    if (req->method == GET) {
        _get(req, Router->get, req->url, new_socket);
    } else if (req->method == POST) {
        _post(req, Router->post, req->url, new_socket);
    }
 }
