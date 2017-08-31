// Generated by BUCKLESCRIPT VERSION 1.9.1, PLEASE EDIT WITH CARE
'use strict';

var Pervasives = require("bs-platform/lib/js/pervasives.js");

function printTree(_node) {
  while(true) {
    var node = _node;
    if (node) {
      var n = node[0];
      printTree(n[1]);
      Pervasives.print_int(n[0]);
      Pervasives.print_string(", ");
      _node = n[2];
      continue ;
      
    } else {
      return Pervasives.print_string("");
    }
  };
}

function insert(node, value) {
  if (node) {
    var n = node[0];
    var r = n[2];
    var l = n[1];
    var v = n[0];
    var match = +(value < v);
    if (match !== 0) {
      return /* Node */[/* tuple */[
                v,
                insert(l, value),
                r
              ]];
    } else {
      return /* Node */[/* tuple */[
                v,
                l,
                insert(r, value)
              ]];
    }
  } else {
    return /* Node */[/* tuple */[
              value,
              /* Empty */0,
              /* Empty */0
            ]];
  }
}

var test = /* Node */[/* tuple */[
    5,
    /* Empty */0,
    /* Empty */0
  ]];

var inserted = insert(insert(insert(test, 1), 10), 20);

printTree(inserted);

var emptyNode = /* Node */[/* tuple */[
    0,
    /* Empty */0,
    /* Empty */0
  ]];

var correct = /* Node */[/* tuple */[
    5,
    /* Node */[/* tuple */[
        1,
        /* Empty */0,
        /* Empty */0
      ]],
    /* Node */[/* tuple */[
        10,
        /* Empty */0,
        /* Node */[/* tuple */[
            20,
            /* Empty */0,
            /* Empty */0
          ]]
      ]]
  ]];

exports.emptyNode = emptyNode;
exports.printTree = printTree;
exports.insert    = insert;
exports.test      = test;
exports.inserted  = inserted;
exports.correct   = correct;
/* inserted Not a pure module */