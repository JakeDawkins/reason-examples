# Reason Examples

This is a project intended to showcase some basic data structures/algorithms in Reason (v3 syntax). I found it helpful for myself to work through some of these problems to learn more about typing (especially with the BST example) and how the reason/bucklescript tooling works.

If you have questions/comments, hit me up on [twitter](https://twitter.com/jakedawkins), or read the `Contributing` section below.

## Current Examples

* Data Structures
  * [Binary Search Tree](src/bst.re)
    * [What is a BST](https://medium.com/@JakeDawkins/what-is-a-binary-search-tree-2bfdc2bcba7b)
  * [Stack](src/stack.re)
    * [What is a stack](<https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>)
* Algorithms
  * QuickSort
  * Insertion Sort

## Installing locally

```
git clone https://github.com/JakeDawkins/reason-examples.git
npm i
```

## Build

```
npm run build
```

## Build + Watch

```
npm run watch
```

## Running built js

```
node lib/js/src/sorting-algorithms/quicksort.js
```

## Contributing

If you'd like to contribute, fork the Repo and open a PR back to master here. If you'd like to request an example, open an issue.
