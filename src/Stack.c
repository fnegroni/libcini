#include <stdbool.h> // for cini_Stack.h
#include <stdlib.h> // for size_t, malloc, free
#include <assert.h> // for assert

#include "Stack.h"

struct Elem {
	void *x;
	struct Elem *link;
};

struct cini_Stack {
	size_t count;
	struct Elem *head;
};

struct cini_Stack *
cini_Stack_create(void)
{
	struct cini_Stack *stack = malloc(sizeof *stack);
	stack->count = 0;
	stack->head = 0;
	return stack;
}

void
cini_Stack_destroy(struct cini_Stack **stack)
{
	assert(*stack);
	/* FIXME: free all the nodes first */
	free(*stack);
	*stack = 0;
}

bool 
cini_Stack_is_empty(struct cini_Stack *stack)
{
	assert(stack);
	return stack->count == 0;
}

void
cini_Stack_push(struct cini_Stack *stack, void *x)
{
	assert(stack);
	struct Elem *e = malloc(sizeof *e);
	e->x = x;
	e->link = stack->head;
	stack->head = e;
	++stack->count;
}

void *
cini_Stack_pop(struct cini_Stack *stack)
{
	assert(stack);
	assert(stack->head);
	struct Elem *t = stack->head;
	stack->head = t->link;
	--stack->count;
	void *x = t->x;
	free(t);
	return x;
}

