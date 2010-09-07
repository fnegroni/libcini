/* Stack_push and Stack_pop complement each other, and Stack_size must be 
 * consistent.
 */

#include <stdbool.h> // for cini/Stack.h
#include <cini/Stack.h>
#include <stdlib.h> // for sugo.h
#include "sugo.h"

int
main(void)
{
	struct cini_Stack *stack = cini_Stack_create();
	int item1 = 1, item2 = 2;
	cini_Stack_push(stack, &item1);
	cini_Stack_push(stack, &item2);
	int ret_item1 = 0, ret_item2 = 0;
	ret_item2 = *(int *)cini_Stack_pop(stack);
	ret_item1 = *(int *)cini_Stack_pop(stack);
	TEST(1, ret_item1 == item1)
	TEST(2, ret_item2 == item2)
	return 0;
}
