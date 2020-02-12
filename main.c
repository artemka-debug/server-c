#include "main.h"

int main(int argc, char *argv[]) {
	// char *test = make_response_string(" 500 Not Handled", VERSION, "NULL, NULL", "null");
	// printf("TEST [%s]\n", test);

	// free(test);
	if (argc == 1 || argc > 2) {
		printf("Required only one argument: port number\n");
		exit(1);
	}

	char *get_path[] = {"/", "/page", "/test", "/hui"};
	char *post_path[] = {"/auth"}; 

	void (*g[])(request *req, int new_socket) = {
		main_path, page_path, test_path, magic_path
	};

	void (*p[])(request *req, int new_socket) = {
		auth_path
	};

	r *Router = init_router(get_path, g, post_path, p, 4, 1);
	
	int port = atoi(argv[1]);
	int server = socket(AF_INET, SOCK_STREAM, 0);

	int failed = create_and_bind_socket(server, AF_INET, port, INADDR_ANY, &address);
	failed < 0 
		? printf("Failed to run server") 
		: start_and_run_server(Router, server, CONNECTIONS, &address, port);

	return 0;
}
