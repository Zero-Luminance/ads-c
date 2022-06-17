# LINKED LISTS

## Directory Contents:
1) [Linked List Implementations](#linked-list-implementations)
2) [Introduction](#introduction)
3) [Singly Linked Lists (SLL)](#singly-linked-lists)
    -  [SLL Operation Runtimes](#sll-operation-runtimes)
4) [Doubly Linked Lists (DLL)](#doubly-linked-lists)
    -  [DLL Operation Runtimes](#dll-operation-runtimes)
5) [Circular Linked Lists (CLL)](#circular-linked-lists)
6) [Comparing Arrays & Linked Lists](#comparing-arrays--linked-lists)

## Linked List Implementations:
1. [Singly Linked List (SLL)](https://github.com/Zero-Luminance/ads-c/tree/main/data-structures/linked-lists/singly-linked-list-files)
2. [Doubly Linked List (DLL)](https://github.com/Zero-Luminance/ads-c/tree/main/data-structures/linked-lists/doubly-linked-list-files)
3. [Circular Linked Lists (CLL)](https://github.com/Zero-Luminance/ads-c/tree/main/data-structures/linked-lists/circular-linked-list-files)

## Introduction:
- ***‘Linked Lists’*** are a sequence of nodes containing:
    - Pointers to _OTHER_ nodes (or _NULL_ if end of sequence)
    - _INFORMATION_ of any valid data type (e.g. int, double, etc)
- ***‘Head’*** is the FIRST node
- ***‘Tail’*** or ***‘Foot’*** is the _LAST_ node
- _BASIC OPERATIONS_: searching, insertion, & deletion
- Variations: singly linked lists, doubly linked lists, circular linked lists
- Other Implementations: Stacks, Queues, Dictionaries, etc...
<figure>
    <img src="../../assets/markdown-images/linked-list-images/linked-list-introduction.png" alt="Linked List Diagram">
    <figcaption>Source: <a href="https://www.educative.io/edpresso/what-is-a-linked-list">educative.io</a></figcaption>
</figure>
<br>

## SINGLY LINKED LISTS:
- ***‘Singly Linked Lists’*** _(SLL)_ only contain a SINGLE pointer variable that points to the _NEXT_ node in the sequence
- Diagram:
<figure>
    <img src="../../assets/markdown-images/linked-list-images/singly-linked-list-diagram.png" alt="Singly Linked List Diagram">
    <figcaption>Source: <a href="https://www.geeksforgeeks.org/data-structures/linked-list/">GeeksforGeeks</a></figcaption>
</figure>
<br>

### SLL Operation Runtimes:
- NOTE: runtimes depend on the implementation (e.g. having a _LIST_ ***‘tail’*** pointer would make _BACK_ insertion & deletion ***O(1)*** constant time)
<table>
    <tr>
        <th scope="col" colspan="2">OPERATION:</th>
        <th scope="col">COST & OPERATION:</th>
    </tr>
    <tr>
        <th scope="row"><i>RANDOM</i></th>
        <th scope="row" rowspan="3">INSERTION</th>
        <td><b>O(n)</b> - need to traverse the ENTIRE SLL</td>
    </tr>
    <tr>
        <th scope="row"><i>FRONT</i></th>
        <td><b>O(1)</b> - access header pointer</td>
    </tr>
    <tr>
        <th scope="row"><i>BACK</i></th>
        <td><b>O(n)</b> - same reason as random insertion</td>
    </tr>
    <tr>
        <th scope="row"><i>RANDOM</i></th>
        <th scope="row" rowspan="2">DELETION</th>
        <td><b>O(n)</b> - same as reason as random insertion</td>
    </tr>
    <tr>
        <th scope="row"><i>FRONT</i></th>
        <td><b>O(1)</b> - same reason as front insertion</td>
    </tr>
    <tr>
        <th scope="row"><i>UNSORTED</i></th>
        <th scope="row" rowspan="2">SEARCHING</th>
        <td rowspan="2"><b>O(n)</b> - sorted or unsorted does NOT matter, worst case requires the traversal of the ENTIRE SLL (i.e. data not found in SLL)</td>
    </tr>
    <tr>
        <th scope="row"><i>SORTED</i></th>
    </tr>
</table>
<br>

## DOUBLY LINKED LISTS:
- ***‘Doubly Linked Lists’*** _(DLL)_ contain _TWO_ pointer variables that refer to the current node’s _NEXT_ & _PREVIOUS_ nodes
- Diagram:
<figure>
    <img src="../../assets/markdown-images/linked-list-images/doubly-linked-list-diagram.png" alt="Doubly Linked List Diagram">
    <figcaption>Source: <a href="https://www.geeksforgeeks.org/doubly-linked-list/">GeeksforGeeks</a></figcaption>
</figure>
<br>

### DLL Operation Runtimes:
<table>
    <tr>
        <th scope="col" colspan="2">OPERATION:</th>
        <th scope="col">COST & REASON:</th>
    </tr>
    <tr>
        <th scope="row" rowspan="2"><i>BACK</i></th>
        <th scope="row">INSERTION</th>
        <td rowspan="2"><b>O(1)</b> - access tail pointer (assuming it has been implementation in the list code)</td>
    </tr>
    <tr>
        <th scope="row"><i>DELETION</i></th>
    </tr>
</table>
<br>

## CIRCULAR LINKED LISTS:
- ***‘Circular Linked Lists’*** _(CLL)_ requires the _TAIL_ node’s pointer to point _BACK_ to the _HEAD_ node (or vice versa if doubly too)
- Diagram:
<figure>
    <img src="../../assets/markdown-images/linked-list-images/circular-linked-list-diagram.png" alt="Circular Linked List Diagram">
    <figcaption>Source: <a href="https://www.javatpoint.com/circular-singly-linked-list">javaTpoint</a></figcaption>
</figure>
<br>

## Comparing Arrays & Linked Lists
<table>
    <tr>
        <th scope="col">STATIC ARRAY ADVANTAGES:</th>
        <th scope="col">LINKED LIST ADVANTAGES:</th>
    </tr>
    <tr>
        <td>Implementation requires <i>LESS</i> space</td>
        <td>Overflow only occurs due to a <i>LACK</i> of memory</td>
    </tr>
    <tr>
        <td>Can <i>ACCESS</i> items <i>DIRECTLY</i></td>
        <td>Easier to <i>INSERT</i> & <i>DELETE</i> items</td>
    </tr>
    <tr>
        <td>Better memory locality & cached performance</td>
        <td><i>EASIER</i> & <i>FASTER</i> to move pointers instead of shifting entire array items</td>
    </tr>
</table>