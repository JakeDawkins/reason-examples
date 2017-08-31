const sort = require('./lib/js/src/quicksort').sort;

let x = [6, [3, [8, [1, [5, [7, [9, 0]]]]]]];

const reasonListToArray = l =>
  l[1] === 0 ? l[0] : [l[0]].concat(reasonListToArray(l[1]));

const arrayToReasonList = a =>
  a.reduceRight((acc, item, index, array) => [item, acc], 0);

const sorted = reasonListToArray(sort(x));
const list = arrayToReasonList(sorted);

console.log(reasonListToArray(list));
