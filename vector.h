#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef struct velist{
    int size;
    int number;
    char** data;
} velist;

velist* velist_new();
int velist_push_forward(velist* l, char* data);
void velist_remove(velist* l, char* data);
void velist_delete(velist* l);
void velist_print(const velist* l);
char* velist_get(velist* l);

#endif // VECTOR_H_INCLUDED
