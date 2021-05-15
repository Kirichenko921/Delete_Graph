#include "graph.h"
#include <iostream>


Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
/* Для проверки, существует ли ребро, нужно посмотреть значение элемента матрицы смежности с индексами номеров вершин (если есть ребро, он отличен от 0).*/
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
/*Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes.*/
bool Graph::vertexExists(int vnumber)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == vnumber)
            return true;
    return false;
}

void Graph::depth(int start)
{
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false; // инициализируем как непосещенные
    depthInner(start, visited); // запуск алгоритма 

    std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[])
{
    std::cout << "v" << current << " -> "; // вывод текущей
    visited[current] = true; // помечаем как посещенную
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину

    }
}

