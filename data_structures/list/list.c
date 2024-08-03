#include "list.h"

#define DEFAULT_SIZE 3

struct linked_list *create(void *data) 
{	
	struct list_node *node = malloc(sizeof(struct list_node));
	node->data = data;
	
	struct linked_list *list = malloc(sizeof(struct list_node) * DEFAULT_SIZE);
	list->head = node;
	list->tail = node;
	list->size = 1;
	list->max_size = DEFAULT_SIZE;
}

/*
 * ADDS NODE WITH DATA = data TO THE END OF THE LIST
 * RETURNS TAIL OF THE LIST: list->tail
 */
struct list_node *add(struct linked_list *list, void *data) 
{
	/*
	 * IN CASE LIST IS FULL, WE GOTTA REALLOCATE NEW MEMMORY 
	 * NEW MEMMORY = 2 * LAST MEMMORY
	 */
	if (list->size == list->max_size) {
		list->max_size *= 2;
		printf("max_size increased: %d\n", list->max_size);
		list = reallocate_memory(list);
		printf("memory reallocated\n");		
	}
	
	/* CREATING NEW NODE */
	struct list_node *new_node = malloc(sizeof(struct list_node));
	new_node->data = data;

	/* ADDING NEW NODE TO THE END OF THE LIST */
	list->tail->next = new_node;
	printf("YO\n");
	list->tail = new_node;

	list->size++;
	return list->tail;
}

/*
 * REALLOCATES MEMORY FOR THE LIST
 * RETURNS POINTER TO A NEW (BIGGER) LIST
 */
struct linked_list *reallocate_memory(struct linked_list *list) 
{
	/* INITIALIZING NEW HEAD */
	struct list_node *new_head = malloc(sizeof(struct list_node)); 
	new_head->data = list->head->data;
	
	/*  INITIALIZING NEW LIST WITH INCREASED MEMORY SIZE */
	struct linked_list *new_list = malloc(sizeof(struct list_node) * list->max_size);
	
	/* 
	 * NOW WE'RE GONNA ITERATE OVER AN OLD LIST  
	 * AND CREATE AND ADD NEW NODES TO THE NEW LIST 
	 */
	struct list_node *curr     = list->head;
	struct list_node *new_curr = new_list->head;
	while (curr->next)
	{
		curr = curr->next;

		/* CREATE NEW NODE */
		struct list_node *new_node = malloc(sizeof(struct list_node));
		new_node->data = curr->data;

		/* SETTING NEXT OF new_curr TO new_node */
		new_curr->next = new_node;

		new_curr = new_curr->next;
	}

	return new_list;
}

void print(struct linked_list *list)
{
	printf("[ ");

	struct list_node *curr = list->head;
	while (curr->next)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	
	printf("]\n");
	printf("size: %d\n", list->size);
	printf("max_size: %d\n", list->max_size);
}

