#include "main.h"

void check_password(int new_socket, char *password) {
    if (strcmp(PASSWORD, password) == 0) {
        char *response = make_response_string(" 200 OK", VERSION,
            "{\"success\": true}\r\n",
            "Content-Type: appliction/json\r\n\r\n");
        respond(new_socket, response);
        free(response);
    } else {
        char *response = make_response_string(" 401 Unauthorized", VERSION,
            "{\"success\": false, \"Error\": \"Wrong password\"}\r\n",
            "Content-Type: appliction/json\r\n\r\n");

        respond(new_socket, response);
        free(response);
    }
}

void main_path(request *req, int new_socket) {
    char *response = make_response_string(" 200 OK", VERSION,
        "{\"success\": true}\r\n",
        "Content-Type: appliction/json\r\n\r\n");
    respond(new_socket, response);
    free(response);
}

void test_path(request *req, int new_socket) {
    char *response = make_response_string(" 200 OK", VERSION,
        "{\"success\": true}\r\n",
        "Content-Type: appliction/json\r\n\r\n");
    respond(new_socket, response);
    free(response);
}

void page_path(request *req, int new_socket) {
    char *response = make_response_string(" 200 OK", VERSION,
        "{\"success\": true}\r\n",
        "Content-Type: appliction/json\r\n\r\n");
    respond(new_socket, response);
    free(response);
}

void auth_path(request *req, int new_socket) {
    check_password(new_socket, req->body);
}

void magic_path(request *req, int new_socket) {
    char *response = make_response_string(" 200 OK", VERSION,
        "{\"success\": true, \"Message\": \"Your hui was handled\"}\r\n",
        "Content-Type: appliction/json\r\n\r\n");

    respond(new_socket, response);
    free(response);
}