/*
 * uses bool from stdbool.h
 */

struct cini_Stack;

extern struct cini_Stack *cini_Stack_create(void);
extern void cini_Stack_destroy(struct cini_Stack **stack);
extern void cini_Stack_empty(struct cini_Stack *stack);
extern bool cini_Stack_is_empty(struct cini_Stack *stack);
extern void cini_Stack_push(struct cini_Stack *stack, void *x);
extern void *cini_Stack_pop(struct cini_Stack *stack);
