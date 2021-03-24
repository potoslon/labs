#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Item {
    char* data;
    struct Item *next;
} Item;

typedef struct velist {
    Item *head;
    Item *tail;
} velist;

velist *velist_new();
int velist_push_forward(velist* l, char* data);
void velist_remove(velist* l, char* data);
void velist_delete(velist* l);
void velist_print(const velist* l);
char* velist_get(velist* l);


#endif // LIST_H_INCLUDED
