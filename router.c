#include "main.h"

 void router(char *path, request *req, int new_socket) {
    if (req->method == GET && strcmp(req->url, path) == 0) {
        check_password(new_socket, req->body);
    } else if (req->method == POST && strcmp(req->url, path) == 0) {
        check_password(new_socket, req->body);
    } else {
        respond(new_socket, make_response_string(" 500 Not Handled", VERSION, "{\"success\": false}\r\n\r\n", NULL));
    }
 }

 void check_password(int new_socket, char *password) {
    if (strcmp(PASSWORD, password) == 0) {
        respond(new_socket, make_response_string(" 200 OK", VERSION,
            "{\"success\": true}\r\n",
            "Content-Type: appliction/json\r\n\r\n"));
    } else {
        respond(new_socket, make_response_string(" 401 Unauthorized", VERSION,
            "{\"success\": false, \"Error\": \"Wrong password\"}\r\n",
            "Content-Type: appliction/json\r\n\r\n"));
    }
 }