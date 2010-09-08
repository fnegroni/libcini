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
