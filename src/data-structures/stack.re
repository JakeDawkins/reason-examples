/* 
  IMMUTABLE STACK

  Just a simple wrapper around the list type. 

  NOTE: There is a stack module in Reason, so I'd advise against using this :)

  Stacks are LIFO (Last in, first out) so it makes sense to use
  the head of a list for this. Especially since it's a linear operation.
*/

type stack = (list(int));

let size = fun (stack: stack) => {
  List.length(stack);
};

let empty = fun (stack: stack) => {
  (size(stack)) == 0;
};

/* pushes `value` to the top of the stack, and returns the new stack */
let push = fun (stack: stack, value: int) => {
  [value, ...stack];
};

/* access top item, but doesn't remove */
/* Error when peeking at an empty stack */
let peek = (stack: stack) => {
  List.hd(stack);
};

/* removes top item, but doesn't return it. Returns the new stack */
/* Error when popping from an empty stack */
let pop = (stack: stack) => {
  List.tl(stack);
};

/* TESTS */
/* let stack = push([], 0); */
let stack = push(push(push([], 0), 1), 2); /* [2, [1, [0, 0]]] */

/* print_int(peek(pop(stack))); 1 */
print_string((empty([])) ? "empty" : "not empty");