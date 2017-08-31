 let x = [6, 3, 8, 1, 5, 7, 9];  

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

sort x;
