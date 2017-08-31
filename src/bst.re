
/* The node type. It can either have a value (Node type) or be "Empty" */
/* (::nodeValue int, ::leftSubtree node, ::rightSubtree node) */
type node = 
  | Node (int, node, node)
  | Empty;

/* LCR Printing. Should print tree values in ASC order */
let rec print = fun (node: node) => {
  switch(node){
    | Node n => {
      let (v, left, right) = n;
      print left;
      print_int v;
      print_string ", ";
      print right;
    } 
    | Empty => print_string ""
  }
};

/* checks if `value` is anywhere in the tree recursively */
let rec find = fun (node: node) (value: int) => {
  switch (node){
    | Empty => false
    | Node n => {
      let (v, l, r) = n;
      (v == value) || (value < v ? (find l value) : (find r value));
    }
  }
};

/* 
  insert. 
  1. Checks if node is empty. if it is, returns a node with a value.
  2. if not empty, calls insert on either left or right subtree. l if <, r if > current node value
  3. recursively calls until an empty node is found and inserts
  * NOTE: Does not currently check for existing values
*/
let rec insert = fun (node: node) (value: int) => {
  switch(node){
    | Node n => {
      let (v, l, r) = n;
      (value < v) 
        ? Node (v, (insert l value), r) 
        : Node (v, l, (insert r value));
    }
    | Empty => Node (value, Empty, Empty);
  };
};

/* TESTS */

let test = Node (5, Empty, Empty);
let inserted = insert (insert (insert test 1) 10) 20;

/* what the tree should look like after the inserts */
let correct = Node (5, Node (1, Empty, Empty), Node (10, Empty, Node (20, Empty, Empty)));

/* print_string ((find inserted 19) ? "true" : "false"); */
/* print (insert (insert Empty 10) 5) */
print inserted;