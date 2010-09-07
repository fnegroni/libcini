/* Verify Stack_create and Stack_destroy work well together, and that
 * Stack_destroy sets the argument to 0.
 */

#include <stdbool.h> // for cini/Stack.h
#include <cini/Stack.h>
#include <stdlib.h> // for sugo.h
#include "sugo.h"

int
main(void)
{
	struct cini_Stack *stack;
	stack = cini_Stack_create();
	cini_Stack_destroy(&stack);
	TEST(1, stack == 0)
	return 0;
}
