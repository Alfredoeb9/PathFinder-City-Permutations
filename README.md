# PathFinder: Permutations

## Overview:
This is a C++ application designed to solve shortest path based on distance between cities.

Given a starting city, the program calculates the most efficient route to visit every city exactly once and return back to the original city.

## The Problem:
We have a graph of 4 cities. The goal is the find the shortest path the salesperson can take starting at a city going through all cities and returning back to the original city.

## The Data Structure: 
We are given a undirected graph with weights, the weights represent the miles it takes from one city to the other. So, we will build a graph[4][4]. Where, graph[0][0] will be starting point = 0 miles, graph[0][1] will be starting point to next city = 16 miles, etc.

```
     [0] [1] [2] [3]
[0]   0  16  26  30
[1]   x   0   x   x
[2]   x   x   0   x
[3]   x   x    x  0

```

## How it Works:
This program uses Time Complexity of O(N!) due to permutations with Space Complexity of O(N^2) as we are using a matrix.

1. Inital: We have a order of {1, 2, 3}, starting at One city
2. Permutation: Using next_permutation, we generate the next largest possible order of cities {1,2,3}, {1, 3, 2}, {2, 1, 3}, etc.
3. For each permutation loop we calculate the total distance from the Start -> City A -> City B -> ... Start
4. Compare and find the best path with the best distance. 

## Complexity Analysis
- Time Complexity: O(N!): Based on permutations, 4 cities (3! = 6 loops)
- Space Complexity: O(N^2): Accessing the matrix [4][4]