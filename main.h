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

struct sockaddr_in address;
typedef enum Method {UNSUPPORTED, GET, HEAD, POST} Method;

typedef struct _sslited_str {
    char *header;
    struct _sslited_str *next;
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

ss *split_request(char *str);
void parse_body(ss *list, request *req);
void parse_headers(ss *list, request *req);
void parse_req_str(ss *list, request *req);
char *pop_from_ss(ss **list);
void print(ss *head);
void free_ss(ss *head);
void print_h(Header *head);
char *substring(char *str, size_t start, size_t end);
Header *push_header(Header *head, char *name, char *value);
ss *push(ss *head, char *header);
char *concat_h(const char *s1, const char *s2, int last_header);
char *concat(const char *s1, const char *s2);
char *make_response_string(request *req);
char *request_header(const char *name, request *req);
request *parse_request(char *raw);
void free_header(struct Header *h);
void free_request(struct request *req);
void respond(int new_socket, char *msg);
int create_and_bind_socket(int server, int domain, int port, in_addr_t addr, struct sockaddr_in *address);
void start_and_run_server(int server, int connections, struct sockaddr_in *address, int port);