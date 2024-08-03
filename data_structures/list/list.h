#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 3

struct list_node {
	void             *data;
	struct list_node *next;
};

struct linked_list {
	struct list_node *head;
	struct list_node *tail;
	size_t            size;
	size_t        max_size;
};

struct linked_list *create(void *data);

/*
 * ADDS NODE WITH DATA = data TO THE END OF THE LIST
 * RETURNS TAIL OF THE LIST: list->tail
 */
struct list_node *add(struct linked_list *list, void *data);

/*
 * REALLOCATES MEMORY FOR THE LIST  
 * RETURNS POINTER TO A NEW (BIGGER) LIST
 */
struct linked_list *reallocate_memory(struct linked_list *list);

void print(struct linked_list *list);

#endif // LIST_H

