#pragma once
#ifndef __GRAPH__
#define __GRAPH__

#define SIZE 10

//#include "test.h"


class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(int vnumber);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    // удаление вершины
    void delVertex(int vnumber);
    // удаление ребра
    void delEdge(int v1, int v2);
    void depth(int start);
    void depthInner(int current, bool visited[]);

  

    friend bool test(const Graph& g);
    void dummy1(int vnumber);
    void dummy2(int v1, int v2);
//private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};
#endif