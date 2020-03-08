
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <list.h>

listobj *listobj_new(void *data) {
	listobj *obj = malloc(sizeof(listobj));
	if (obj == NULL) {
		errno = ENOMEM;
		return NULL;
	}
	obj->data = data;
	obj->prev = NULL;
	obj->next = NULL;
	return obj;
}

void listobj_free(listobj *obj) {
	if (obj == NULL) {
		errno = EFAULT;
		return;
	}
	free(obj);
}

list *list_new() {
	list *L = malloc(sizeof(list));
	if (L == NULL) {
		errno = ENOMEM;
		return NULL;
	}
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
	return L;
}

void list_free(list *L) {
	if (L == NULL) {
		errno = EFAULT;
		return;
	}
	free(L);
}

size_t list_size(list *L) {
	return L->size;
}

int list_is_empty(list *L) {
	return (L->size == 0);
}

int list_insert_before(list *L, void *data, listobj *ref) {
	if (L == NULL) {
		errno = EFAULT;
		return -1;
	}
	listobj *obj = listobj_new(data);
	if (obj == NULL)
		return -1;

	if (list_is_empty(L) || ref == NULL) {
		L->head = obj;
		L->tail = obj;
		L->size++;
		return 0;
	}

	obj->prev = ref->prev;
	obj->next = ref;
	ref->prev = obj;

	if (ref == L->head)
		L->head = obj;

	L->size++;
	return 0;
}

int list_insert_after(list *L, void *data, listobj *ref) {
	if (L == NULL) {
		errno = EFAULT;
		return -1;
	}
	listobj *obj = listobj_new(data);
	if (obj == NULL)
		return -1;

	if (list_is_empty(L) || ref == NULL) {
		L->head = obj;  
		L->tail = obj;                  
		L->size++;
		return 0;
	}

	obj->next = ref->next;
	obj->prev = ref;
	ref->next = obj;

	if (ref == L->tail)
		L->tail = obj;

	L->size++;
	return 0;
}

int list_push_front(list *L, void *data) {
	if (L == NULL) {
		errno = EFAULT;
		return -1;
	}
	return list_insert_before(L, data, L->head);
}

int list_push_back(list *L, void *data) {
	if (L == NULL) {
		errno = EFAULT;
		return -1;
	}
	return list_insert_after(L, data, L->tail);
}

int list_remove(list *L, listobj *obj) {
	if (L == NULL || obj == NULL) {
		errno = EFAULT;
		return -1;
	}

	if (obj == L->head)
		L->head = obj->next;
	if (obj == L->tail)
		L->tail = obj->prev;

	if (obj->prev != NULL)
		obj->prev->next = obj->next;
	if (obj->next != NULL)
		obj->next->prev = obj->prev;

	listobj_free(obj);
	L->size--;
	return 0;
}

listobj *list_find(list *L, void *data) {
	if (L == NULL) {
		errno = EFAULT;
		return NULL;
	}

	listobj *current = L->head;
	while (current != NULL && current->data != data)
		current = current->next;

	return current;
}

