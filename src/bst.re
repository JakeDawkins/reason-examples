
/* The node type. It can either have a value (Node type) or be "Empty" */
/* (::nodeValue int, ::leftSubtree node, ::rightSubtree node) */
type node = 
  | Node (int, node, node)
  | Empty;
let emptyNode = Node (0, Empty, Empty);

/* LCR Printing. Should print tree values in ASC order */
let rec printTree = fun (node: node) => {
  switch(node){
    | Node n => {
      let (v, left, right) = n;
      printTree left;
      print_int v;
      print_string ", ";
      printTree right;
    } 
    | Empty => print_string ""
  }
};

/* OLD -- switch(left){
  | Node ln => printTree (Node ln)
  | Empty => print_string ""
}; */

/* insert. Checks if node is empty. if it is, returns a node with a value */
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

/* OLD */
/* switch(l){
  | Empty => Node (v, Node (value, Empty, Empty), r)
  | Node no => Node (v, (insert (Node no) value), r) 
} */
  
let test = Node (5, Empty, Empty);
let inserted = insert (insert (insert test 1) 10) 20;

/* what the tree should look like after the inserts */
let correct = Node (5, Node (1, Empty, Empty), Node (10, Empty, Node (20, Empty, Empty)));

/* printTree (insert (insert Empty 10) 5) */
printTree inserted;
