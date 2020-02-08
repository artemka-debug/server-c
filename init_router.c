#include "main.h"

void init_get(get *get, char *path[], void (*fnc[])(request *req, int new_socket), int length) {
    add_get_path(get, path, length);
    add_get_func(get, fnc, length);
}

void init_post(post *post, char *path[], void (*fnc[])(request *req, int new_socket), int length) {
    add_post_path(post, path, length);
    add_post_func(post, fnc, length);
}

r *init_router(char *get_path[], void (*g[])(request *req, int new_socket), char *post_path[], void (*p[])(request *req, int new_socket), int length_g, int length_p) {
    r *Router = malloc(sizeof(r));
	Router->get = malloc(sizeof(get));
	Router->post = malloc(sizeof(post));

	init_get(Router->get, get_path, g, length_g);
	init_post(Router->post, post_path, p, length_p);

    return Router;
}
