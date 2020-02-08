#include "main.h"

int main(int argc, char *argv[]) {
	// char *req = "POST / HTTP/1.1\r\n"
	// 			"Host: localhost:8080\r\n"
	// 			"content-type: text/plain\r\n"
	// 			"ref: http://localhost:8080/Aa\r\n"
	// 			"content-length: 10\r\n\r\n"
	// 			"62137990Aa";

	// for (int i = 0; i < 3; i++) {
	// 	printf("%i\n", i);
	// 	printf("------------------------\n");

	// 	printf("%s\n", req);
	// 	ss *list = split_request(req);
	// 	request *test = parse_request(list);
	// 	// free_request(test);
	// 	// free_ss(list);
	// 	printf("------------------------\n");
	// }

	if (argc == 1 || argc > 2) {
		printf("Required only one argument: port number\n");
		exit(1);
	}

	//  init
	// 		create
	// 		bind
	// 	router
	//  	route_1
	// 		route_2
	//      ...
	//  event loop


	int port = atoi(argv[1]);
	int server = socket(AF_INET, SOCK_STREAM, 0);

	int failed = create_and_bind_socket(server, AF_INET, port, INADDR_ANY, &address);
	failed < 0 
		? printf("Failed to run server") 
		: start_and_run_server(server, CONNECTIONS, &address, port);

	return 0;
}
