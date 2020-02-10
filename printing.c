#include "main.h"
void print(ss *head) {
    printf("START OF SS\n");

    for (int i = 0; i < head->top; i++) {
        printf("ss [%s]\n", head->header[i]);        
    }
    printf("END OF SS\n");
}


void print_h(Header *head, int h_amount) {
    Header *tmp = head;

    for (int i = 0; i < h_amount; i++) {
        printf("headers [%s %s]\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
}
