# Eulerian Path and Cycle Finder

## Overview

This project implements functionalities to find Eulerian paths and Eulerian cycles in undirected graphs. 
The graphs are represented using adjacency matrices and can be loaded from a file. 
The program provides an interactive user interface to select a graph and find Eulerian paths or cycles.

## Features

Load multiple graphs from a text file (graph.txt).
Validate the graphs' adjacency matrices.
Detect and print all Eulerian paths or Eulerian cycles.
Interactive CLI user interface for graph selection and operation.
Error handling with descriptive messages for common issues.

## Project structure

| Filename                               | Description                                           |
| -------------------------------------- | ----------------------------------------------------- |
| `main.c`                               | Main entry point, loads graphs and starts UI.         |
| `graph.c`, `graph.h`                   | Graph initialization, loading, printing, and freeing. |
| `euler.c`, `euler.h`                   | Eulerian path and cycle algorithms implementation.    |
| `user_interface.c`, `user_interface.h` | CLI for user interaction.                             |
| `error.c`, `error.h`                   | Error handling definitions and messages.              |
| `graph.txt`                            | Sample input file containing multiple graphs.         |
| `Makefile`                             | Build configuration to compile the project easily.    |

## Compilation and usage

- You can compile the project using the provided Makefile: `make`
- To clean the build files: `make clean`
- Run the compiled program: `make run`

## Input file format
First line: Number of graphs.
For each graph:
- Number of vertices
- Adjacency matrix of the graph (rows with 0 or 1 entries)

Example:
```
2
3
0 1 1
1 0 1
1 1 0
4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
```

## Author
Jiří Tesař