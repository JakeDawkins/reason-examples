let rec sort = (l: list(int)) =>
  if ( List.length(l) > 1 ) {
    let hd = List.hd(l);
    List.concat([
      (sort(List.filter((fun (x) => x < hd), (List.tl(l))))), 
      [hd], 
      (sort(List.filter((fun (x) => x >= hd), (List.tl(l)))))
    ]);
  } else {
    l;
  };



/* TESTS */

let print = (a: list(int)) => {
  List.iter(((v) => {
    print_int(v);
    print_string(", ");
  }), a);
  print_string("\n");
};

/* print(sort([9, 8, 7, 6, 5, 4, 3, 2, 1])); */