/* 
  Just a simple wrapper around the list type. 

  Stacks are LIFO (Last in, first out) so it makes sense to use
  the head of a list for this. Especially since it's a linear operation.
*/

type stack = (list int);

/* pushes `value` to the top of the stack, and returns the new stack */
let push = fun (stack: stack) (value: int) => {
  [value, ...stack];
};

/* access top item, but doesn't remove */
let peek = fun (stack: stack) => {
  List.hd stack;
};

/* removes top item, but doesn't return it. Returns the new stack */
let pop = fun (stack: stack) => {
  List.tl stack;
};

let stack = push (push (push [] 0) 1) 2; /* [2, [1, [0, 0]]] */
print_int (peek (pop stack)); /* 1 */
