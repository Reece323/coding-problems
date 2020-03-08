#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

typedef struct _listobj {
	void *data;
	struct _listobj *prev;
	struct _listobj *next;
} listobj;

listobj *listobj_new(void *data);
void listobj_free(listobj *obj);

typedef struct _list {
	struct _listobj *head;
	struct _listobj *tail;
	size_t size;
} list;

list *list_new();
void list_free(list *L);
size_t list_size(list *L);
int list_is_empty(list *L);
int list_insert_before(list *L, void *data, listobj *ref);
int list_insert_after(list *L, void *data, listobj *ref);
int list_push_front(list *L, void *data);
int list_push_back(list *L, void *data);
int list_remove(list *L, listobj *obj);
listobj *list_find(list *L, void *data);

#endif /* _LIST_H_ */
