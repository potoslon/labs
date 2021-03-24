#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

velist* velist_new(){
    velist* s = (velist*) calloc(1, sizeof(velist));
    s->number = 0;
    s->size = 100;
    s->data = calloc(102, sizeof(char*));
    return s;
}

int velist_push_forward(velist* l, char* data){
    if (l->number == l->size){
        return -1;
    }
    *(l->data + l->number) = data;
    l->number = l->number + 1;
    return 0;
}

void velist_remove(velist* l, char* data){
    for(int i = 0; i < l->number; i++){
        if ( *(l->data + i) == data ){
            for(i; i < l->number; i++){
                *(l->data + i) = *(l->data + i + 1);
            }
            *(l->data + i + 1) = NULL;
            l->number = l->number - 1;
            return;
        }
    }
    return;
}

void velist_delete(velist* l){
    for(int i = 0; i < l->number - 1; i++){
        free( *(l->data + i) );
    }
    free(l->data);
    free(l);
}

void velist_print(const velist* l){
     for (int i = 0; i < l->number; i++){
        printf("%s ", *(l->data + i) );
     }
     printf("\n");
}

char* velist_get(velist* l){
    if (*(l->data)){
        char* s = *(l->data + l->number - 1);
        return  s;
    }
    return NULL;
}

