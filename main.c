#include "main.h"

int main(int argc, char *argv[]) {
	// char *req = "POST / HTTP/1.1\r\n"
	// 			"Host: localhost:8080\r\n"
	// 			"content-type: text/plain\r\n"
	// 			"ref: http://localhost:8080\r\n"
	// 			"content-length: 10\r\n\r\n"
	// 			"62137990Aa";

	// request *test = parse_request(req);
	// free_request(test);
	if (argc == 1 || argc > 2) {
		printf("Required only one argument: port number\n");
		exit(1);
	}
	int port = atoi(argv[1]);
	int type = SOCK_STREAM;
	int server = socket(AF_INET, type, 0);

	int failed = create_and_bind_socket(server, AF_INET, port, INADDR_ANY, &address);
	failed < 0 ? printf("Failed to run server") : start_and_run_server(server, CONNECTIONS, &address, port);

	return 0;
}
