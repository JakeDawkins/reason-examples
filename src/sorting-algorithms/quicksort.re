let rec sort = (l: list(int)) =>
  List.length(l) > 1 
    ? List.concat([
      (sort(List.filter(x => x < List.hd(l), List.tl(l)))), 
      [List.hd(l)], 
      (sort(List.filter(x => x >= List.hd(l), List.tl(l))))
    ])
    : l;

/* TESTS */

let print = (a: list(int)) => {
  List.iter(((v) => {
    print_int(v);
    print_string(", ");
  }), a);
  print_string("\n");
};

/* print(sort([9, 8, 7, 6, 5, 4, 3, 2, 1])); */