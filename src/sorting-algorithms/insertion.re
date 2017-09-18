/* 
  FYI about fold_left
  fold_left takes 3 args. (f, a, l)

  it applies `f` to all items in the list (l). a is the default value
  of an accumulator. f is a function that takes the accumulator and the
  current value in the list and produces a new accumulator.

  this process acts like the Array.prototype.reduce function in JS.
  https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce?v=a
  JS: l.reduce(f, a)
  ML: List.fold_left f a l

  --- 
  
  that being said, `sort` is the function that does the actual sorting.
  It does so, by taking the list and folding it using `insert`.
*/

let rec insert = fun (a: (list int)) (v: int) => {
  switch(List.length a){
  | 0 => [v]
  | 1 => v > (List.hd a) ? [(List.hd a), v] : [v, List.hd a]
  | _ => v < List.hd a ? [v, ...a] : [(List.hd a), ...(insert (List.tl a) v)];
  };
};

let sort = fun (a: list int) => {
  List.fold_left insert [] a;
};


/* TESTS */

let testPrint = fun (a: list int) => {
  List.iter (fun v => {
    print_int v;
    print_string ", ";
  }) a;
  print_string "\n";
};

/* inserting on empty lists */
/* 1, */
/* testPrint (insert [] 1); */

/* inserting on single item lists - left */
/* 0, 1 */
/* testPrint (insert [1] 0); */

/* inserting on single item lists - right */
/* 0, 1 */
/* testPrint (insert [0] 1); */

/* inserting on multi item lists */
/* 0, 1, 2 */
/* testPrint (insert [0, 1] 2); */

/* [0, 1, 2, 3, 4, 5, 6, 7, 8] */
/* testPrint (insert (insert (insert [0, 1, 2, 4, 5, 7] 3) 6) 8); */

/* full list sorting */
/* testPrint (sort [9, 8, 7, 6, 5, 4, 3, 2, 1]); */