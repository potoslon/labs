#include <stdlib.h>
#include <stdio.h>
#include "list.h"

velist *velist_new() {
    return (velist *) calloc(1, sizeof(velist));
}

void velist_delete(velist *list) {
    Item *ptr = list->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev->data);
        free(ptr_prev);
    }
    free(list);
}

void velist_print(const velist *list) {
    Item *ptr = list->head;
    while (ptr) {
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


char* velist_get(velist* list){
    if (list->head){
        return list->head->data;
    }
    return NULL;
}

int velist_push_forward(velist *list, char* data) {
    Item *ptr = (Item *) malloc(sizeof(Item));
    if (!ptr) {
        return -1;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        ptr->next = list->head;
        list->head = ptr;
    }
    return 0;
}

void velist_remove(velist *list, char* data) {
    Item *ptr = list->head, *ptr_prev = NULL;
    while (ptr && ptr->data != data) {
        ptr_prev = ptr;
        ptr = ptr->next;
    }
    if (!ptr) {
        return;
    }
    if (ptr == list->head) {
        list->head = ptr->next;
    }
    if (ptr == list->tail) {
        list->tail = ptr_prev;
    }
    if (ptr_prev) {
        ptr_prev->next = ptr->next;
    }
    free(ptr);
}

