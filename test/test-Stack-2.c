/*
libcini -- a collection of system application building blocks.

Copyright (C) 2010  Filippo Erik Negroni <f.e.negroni@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
