#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define CONNECTIONS 10000
#define PASSWORD "62137990Aa"
#define VERSION "1.1"

struct sockaddr_in address;
typedef enum Method {UNSUPPORTED, GET, HEAD, POST} Method;

typedef struct splited_req {
    char *header[30];
    int top;
} ss;

typedef struct Header {
    char *name;
    char *value;
    struct Header *next;
} Header;

typedef struct request {
    enum Method method;
    char *url;
    char *version;
    struct Header *headers;
    char *body;
    char *referer;
} request;

typedef struct get {
    void (*fnc[20])(request *req, int new_socket);
    char *pathes[20];
    int top;
    int top_fnc;
} get;

typedef struct post {
    void (*fnc[20])(request *req, int new_socket);
    char *pathes[20];
    int top;
    int top_fnc;
} post;

typedef struct router {
    struct get get;
    struct post post;
} r;

void parse_body(ss *list, request *req);
void parse_headers(ss *list, request *req);
void parse_req_str(ss *list, request *req);

request *parse_request(ss *list);

ss *split_request(char *str);
char *request_header(const char *name, request *req);

void print(ss *head);
void print_h(Header *head, int h_amount);

void free_ss(ss *head);
void free_header(struct Header *h, int h_amount);
void free_request(struct request *req, int h_amount);

Header *push_header(Header *head, char *name, char *value);
void push(ss *head, char *header);
void add_get_path(get *get, char *path[], int length);
void add_get_func(get *get, void (*fnc[])(request *req, int new_socket), int length);
void add_post_func(post *post, void (*fnc[])(request *req, int new_socket), int length);
void add_post_path(post *post, char *path[], int length);

char *substring(char *str, size_t start, size_t end);
char *concat(const char *s1, const char *s2);
char *make_response_string(char *status, char *http_version, char *json_data, char *headers);

void respond(int new_socket, char *msg);
int create_and_bind_socket(int server, int domain, int port, in_addr_t addr, struct sockaddr_in *address);
void start_and_run_server(r *Router, int server, int connections, struct sockaddr_in *address, int port);
void router(request *req, int new_socket, r *Router);

void check_password(int new_socket, char *password);

void init_get(get *get, char *path[], void (*fnc[])(request *req, int new_socket), int length);
void init_post(post *post, char *path[], void (*fnc[])(request *req, int new_socket), int length);
r *init_router(char *get_path[], void (*g[])(request *req, int new_socket), char *post_path[], void (*p[])(request *req, int new_socket), int length_g, int length_p);

void main_path(request *req, int new_socket);
void test_path(request *req, int new_socket);
void page_path(request *req, int new_socket);
void auth_path(request *req, int new_socket);
void magic_path(request *req, int new_socket);