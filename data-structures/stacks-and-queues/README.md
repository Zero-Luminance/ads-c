# STACKS & QUEUES

## Directory Contents:
1) [Stacks & Queues Implementations](#stacks--queues-implementations)
2) [Containers](#containers)
3) [Stacks](#stacks-lifo)
4) [Queues](#queues-fifo)
5) [Example Implementations (Not Limited To) For Stacks & Queues](#example-implementations-not-limited-to-for-stacks--queues)

## Stacks & Queues Implementations:
- [Singly Linked List Stack (SLLS)](https://github.com/Zero-Luminance/ads-c/tree/main/data-structures/stacks-and-queues/singly-linked-list-stack-files)
- [Singly Linked List Queue (SLLQ)](https://github.com/Zero-Luminance/ads-c/tree/main/data-structures/stacks-and-queues/singly-linked-list-queue-files)

## Containers:
- ‘Containers’ refers to data structures whose instances are collections of other objects with examples such as:
<table>
    <tr>
        <th scope="col">ABSTRACT Data Types:</th>
        <th scope="col">CONCRETE Data Types:</th>
    </tr>
    <tr>
        <td>- FIFO Queues</td>
        <td>- Arrays</td>
    </tr>
    <tr>
        <td>- LIFO Stacks</td>
        <td>- Linked Lists</td>
    </tr>
    <tr>
        <td>- Priority Queues</td>
        <td>- Binary Search Trees</td>
    </tr>
    <tr>
        <td>- Priority Queues</td>
        <td>- Hash Tables</td>
    </tr>
    <tr>
        <td>- Lookup Tables</td>
        <td>&nbsp</td>
    </tr>
    <tr>
        <td>- Key-associated data structures: sets, maps, dictionaries</td>
        <td>&nbsp</td>
    </tr>
</table>
- Container Types:
    - ‘Single Value Continuers’ stores data items separately & accessed via iteration
    - ‘Associative Containers’ uses key-value pairs to access & store data

## Stacks (LIFO):
- ‘Stacks’ is an ABSTRACT data structure that RETRIEVES items using a ‘last-in, first-out’ (LIFO) approach
- CIRCUMSTANCE: order of item retrieval does NOT matter
<table>
    <tr>
        <th scope="col">STACK OPERATION:</th>
        <th scope="col">DESCRIPTION:</th>
    </tr>
    <tr>
        <th scope="row">Push(x, s)</th>
        <td>Insert item ‘x’ onto the TOP of stack ’s'</td>
    </tr>
    <tr>
        <th scope="row">Pop(s)</th>
        <td>RETURN & REMOVE the TOP item from stack ’s'</td>
    </tr>
</table>
<figure>
    <img src="../../assets/markdown-images/stacks-and-queues-images/stack-diagram.png" alt="Stack Diagram">
    <figcaption>Source: <a href="https://laptrinhx.com/stacks-and-queues-simplified-1889506540/">LaptrinhX</a></figcaption>
</figure>
<br>

## Queues (FIFO):
- ‘Queue’ is an ABSTRACT data structure that RETRIEVES items using a ‘first-in, first-out’ (FIFO) approach
- CIRCUMSTANCE: order of item retrieval MATTERS
<table>
    <tr>
        <th scope="col">QUEUE OPERATION:</th>
        <th scope="col">DESCRIPTION:</th>
    </tr>
    <tr>
        <th scope="row">Enqueue(x,q)</th>
        <td>Insert item ‘x’ at the BACK of queue ‘q’</td>
    </tr>
    <tr>
        <th scope="row">Dequeue(q)</th>
        <td>RETURN & REMOVE the FRONT item from queue ‘q’</td>
    </tr>
</table>
<figure>
    <img src="../../assets/markdown-images/stacks-and-queues-images/queue-diagram.jpeg" alt="Queue Diagram">
    <figcaption>Source: <a href="https://www.designveloper.com/blog/stacks-and-queues-data-structures/">Designveloper</a></figcaption>
</figure>
<br>

## Example Implementations (Not Limited To) For Stacks & Queues:
<table>
    <tr>
        <th scope="col">STACKS:</th>
        <th scope="col">QUEUES:</th>
    </tr>
    <tr>
        <td colspan="2">Arrays & Linked Lists</tr>
    </tr>
    <tr>
        <td>Recursive Algorithms</td>
        <td>Breadth First Search (Graphs)</td>
    </tr>
</table>