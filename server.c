#include "main.h"

void respond(int new_socket, char *responce) {
    send(new_socket, responce, strlen(responce), MSG_OOB);
    close(new_socket);
}

int create_and_bind_socket(int server, int domain, int port, in_addr_t addr, struct sockaddr_in *address) {
	server < 0 ? printf("socked() failed\n") : printf("sock() succeed\n");

	memset(address, 0, sizeof(*address));
	address->sin_family = domain;
	address->sin_addr.s_addr = htonl(addr);
	address->sin_port = htons(port);
    int option = 1;
    setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    return bind(server, (const struct sockaddr *)address, sizeof(*address)) < 0 ? -1 : 1;
}

void start_and_run_server(r *Router, int server, int connections, struct sockaddr_in *address, int port) {	
	printf("Server is running on port %i\n", port);
	listen(server, connections);
	while (1) {
		int new_socket = accept(server, (struct sockaddr *)address, (socklen_t *)&address->sin_addr);
        if (new_socket < 0) {
			perror("accept failed\n");
		} else {
			printf("user connected\n");
			char buffer[1024];
		    int read_data = recv(new_socket, buffer, sizeof(buffer), 0);
			printf("------------------------\n");
			printf("start [%s] \n", buffer); 
		    ss *list = split_request(buffer);
    		request *req = parse_request(list);
			print_h(req->headers, req->body ? list->top - 2 : list->top - 1);
			print(list);

			router(req, new_socket, Router);
			printf("------------------------\n");
    		free_request(req, req->body ? list->top - 2 : list->top - 1);
		    free_ss(list);
		}
	}
}
