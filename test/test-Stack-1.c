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
