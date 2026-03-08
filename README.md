# Monopoly Board Simulator (Spring 2026)

## Overview
A C++ simulation of a Monopoly board using a **Circular Linked List**.

## Constraints
* **Max Capacity:** 40 spaces
* **Data Structure used:** Circular linked list, the tailNode always connects back to the headNode in order to create a continuous ring, preventing the need for array indexing.

## Build Instructions
* **Compile:** `g++ -std=c++17 main.cpp -o monopoly`
* **Run:** `./monopoly`

## Traversal and Movement Logic
Because we are using a circular linked list, in order to move the player pointer simply steps forward using playerNode = playerNode->nextNode.
In order to track passing go, we check if player is on the tailNode before moving. If the player is on tailNode, then next step wraps to head and we increment `passGoCount`.

## Function List
* `addSpace(T value)`: this function allows us to add a node at the tail while still enforcing the 40-space limit. it also connects the tail back to head after the space is added.
* `addMany(vector<T> values)`: this function takes a vector full of spaces and adds them sequentially, but it stops adding spaces from the vector as soon as the board hits capacity.
* `movePlayer(int steps)`: this function moves the player node by node around the linked list `steps` amount of times. it also keeps track of how many times the player has passed go.
* `printFromPlayer(int count)`: this function prints each space that is in front of the players current position `count` amount of times.
* `removeByName(string name)`: this function takes in a string `name` as a parameter, and searches the linked list until it finds the first match and deletes it. It then patches any pointer hole to keep the circle intact.
* `findByColor(string color)`: traverses ring exactly once while simultaneously printing spaces that match `color` directly to the console.
* `clear()`: this breaks the circular link of our linked list, then we safely delete all nodes linearly with a while loop.