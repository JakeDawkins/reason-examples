let rec sort l =>
  if ( List.length l > 1 ) {
    let hd = List.hd l;
    List.concat [
      (sort (List.filter (fun (x) => x < hd) (List.tl l))), 
      [hd], 
      (sort (List.filter (fun (x) => x >= hd) (List.tl l)))
    ];
  } else {
    l;
  };
