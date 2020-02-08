#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define CONNECTIONS 1000
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

void parse_body(ss *list, request *req);
void parse_headers(ss *list, request *req);
void parse_req_str(ss *list, request *req);

request *parse_request(ss *list);

ss *split_request(char *str);
char *request_header(const char *name, request *req);

void print(ss *head);
void print_h(Header *head);

void free_ss(ss *head);
void free_header(struct Header *h);
void free_request(struct request *req);

Header *push_header(Header *head, char *name, char *value);
void push(ss *head, char *header);

char *substring(char *str, size_t start, size_t end);
char *concat_h(const char *s1, int last_header);
char *concat(const char *s1, const char *s2);
char *make_response_string(char *status, char *http_version, char *json_data, char *headers);

void respond(int new_socket, char *msg);
int create_and_bind_socket(int server, int domain, int port, in_addr_t addr, struct sockaddr_in *address);
void start_and_run_server(int server, int connections, struct sockaddr_in *address, int port);
void router(char *path, request *req, int new_socket);

void check_password(int new_socket, char *password);